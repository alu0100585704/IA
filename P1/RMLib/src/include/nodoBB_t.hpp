/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nodoBB.hpp
 * Author: Juan Siverio
 *
 * Created on 28 de abril de 2017, 23:35
 */
#pragma once

#include <cstdio>
#include <iostream>
using namespace std;

namespace RMLIB {
template <class T>
class nodoBB_t { // Clase local: nodo de ArbolBB
    protected:
        T clave_;
        int nivel_;
        nodoBB_t<T> *left_;
        nodoBB_t<T> *right_;
    public:

        nodoBB_t(T clave);
        virtual ~nodoBB_t(void);
        virtual int & get_set_bal(void){}        
	void set_left (nodoBB_t<T>* nodo);
	void set_right (nodoBB_t<T>* nodo);

	nodoBB_t<T>*& get_set_left(void);
	nodoBB_t<T>*& get_set_right(void);

	nodoBB_t<T>* get_left(void)  const;
	nodoBB_t<T>* get_right(void) const;

	void set_clave(const T& clave_);
	T & get_set_clave(void);
        ostream & write(ostream & os);
        int & get_set_nivel(void);
};

}



    
