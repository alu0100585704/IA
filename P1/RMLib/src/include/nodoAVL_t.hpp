#pragma once


#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <nodoBB_t.hpp>

using namespace RMLIB;

namespace RMLIB {
template <class T>
class nodoAVL_t : public nodoBB_t<T>
{

    protected:
        int bal_;

    public:
    nodoAVL_t(T clave);
    //nodoAVL_t(T clave,nodoAVL_t<T> * iz, nodoAVL_t<T> * de);
    ~nodoAVL_t(void);
    int & get_set_bal(void);

};
template <class T>
nodoAVL_t<T>::~nodoAVL_t(void)
{

}
template <class T>
nodoAVL_t<T>::nodoAVL_t(T clave) : nodoBB_t<T>(clave)
{
   bal_=0;
   this->left_=NULL;
   this->right_=NULL;

}
/*template <class T>
nodoAVL_t<T>::nodoAVL_t(T clave,nodoAVL_t<T> * iz, nodoAVL_t<T> * de) : nodoBB_t<T>(clave)
{
   bal_=0;
   this->left_=iz;
   this->right_=de;



}*/
template <class T>
int & nodoAVL_t<T>::get_set_bal(void)
{
    return bal_;
}



}
