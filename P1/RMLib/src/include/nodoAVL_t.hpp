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

}
