#ifndef UTIL_H
#define UTIL_H
#include <cstddef>
//Klocwork-Fix rule MISRA.NS.GLOBAL-START
namespace CsApp {
template< class T > inline void SafeDEL( T*& pVal )
{
    if (pVal != nullptr){
        delete pVal;
        pVal = nullptr;
    }
}

template< class T > inline  T Max( T*& p1, T*& p2 ) {
    return (p1 > p2) ? p1 : p2;
}

template< class T > inline  T Min( T*& p1, T*& p2 ) {
    return (p1 > p2) ? p2 : p1;
}

template< class T > inline  void SafeDELArray( T*& pVal )
{
    if (pVal != nullptr){
        delete[] pVal;
    }
    pVal = nullptr;
}
}
//Klocwork-Fix rule MISRA.NS.GLOBAL-END
#endif // UTIL_H
