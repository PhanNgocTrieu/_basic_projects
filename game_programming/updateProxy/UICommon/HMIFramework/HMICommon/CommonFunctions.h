#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H

#ifndef UNUSEDFUNC
#define UNUSEDFUNC
/*!
* \brief This function is a countermeasure for MISRA.FUNC.UNUSEDPAR.
* \param val
*/
template<typename T>
inline void UNUSED(T& val)
{
    (void)(val);
}
#endif 

namespace uicommon {

#ifndef DEFINE_SAFE_DELETE
#define DEFINE_SAFE_DELETE
    template< class T > inline void safeDelete( T*& pVal )
    {
        if(NULL != pVal){
            delete pVal;
            pVal = NULL;
        }
    }
#endif
}
#endif // COMMONFUNCTIONS_H
