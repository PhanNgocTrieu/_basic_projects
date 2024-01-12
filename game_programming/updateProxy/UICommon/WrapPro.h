#ifndef WRAP_PRO_H
#define WRAP_PRO_H
#include <mutex>
#include <memory>
#include <shared_mutex>
#include "Proxy/VehicleGeneralState/VehicleGeneralStateModel.h"
namespace uicommon{
    template<typename _T>
    class WrapPro{
        public:
            /**
             * @brief Construct a Wrapper for A property 
             * 
             * @param val The value represent for that property
             * @param frequentlyQuery To indicate that the pro usually requests an action
             *                        of querying. In that case, the value will be update accordingly
             *                        and there is no sound played on
             */
            WrapPro(_T val, bool frequentlyQuery = false)
                : m_val{val},
                m_queriable{frequentlyQuery},
                // START - Fix klocwork UNINIT.CTOR.MUST
                m_proctect()
                // END - Fix klocwork UNINIT.CTOR.MUST
            {
                
            }
            WrapPro(WrapPro<_T>& pro):m_proctect{}
            {
                m_val = pro.m_val;
                m_queriable = pro.m_queriable;

            }
            WrapPro(WrapPro<_T>&& pro): m_proctect{}
            {
                m_val = pro.m_val;
                m_queriable = pro.m_queriable;
            }
            _T get() const {return m_val;}
            void operator = (const _T& val){
                bool isValidToPlaySound = false;
                {
                    std::unique_lock<std::shared_mutex> lock(m_proctect);
                    m_val = val;
                    if (m_queriable){
                        if (m_markRequestChange){
                            isValidToPlaySound = true;
                        }
                        m_markRequestChange = false;
                    }else{
                        isValidToPlaySound = true;
                    }
                }
                if (isValidToPlaySound){
                    uicommon::VehicleGeneralStateModel::getInstance().playSound(uicommon::VehicleGeneralStateAgency::Accept);
                }
            }
            bool operator == (const _T val){
                return val == m_val;
            }
            bool operator != (const _T val){
                return val != m_val;
            }
            void markChange(){
                m_markRequestChange = true;
            }
            operator _T() const{
                return m_val;
            }

        private:
            _T  m_val;
            bool m_queriable ;
            /**
             * @brief This property is used in case the property usually requests query action for a value
             *        In that case, if the pro is indeed maked as request change, after its value is modified 
             *        the sound will be played on
             * 
             */
            bool m_markRequestChange = false;
            std::shared_mutex m_proctect;
    };
};
#endif 
