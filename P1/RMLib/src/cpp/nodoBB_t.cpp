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

#include <cstdio>
#include <nodoBB_t.hpp>
using namespace std;

namespace RMLIB {
template <class T>
nodoBB_t<T>::nodoBB_t(T clave) :
left_(NULL),
right_(NULL),
clave_(clave)
{
    
}
template <class T>
nodoBB_t<T>::~nodoBB_t(void)
{
    left_=NULL;
    right_=NULL;
}

	template <class T>
	void nodoBB_t<T>::set_left(nodoBB_t<T>* nodo)
	{
		left_ = nodo;
	}

	template <class T>
	nodoBB_t<T>* nodoBB_t<T>::get_left(void) const
	{
		return left_;
	}

	template <class T>
	nodoBB_t<T>*& nodoBB_t<T>::get_set_left(void)
	{
		return left_;
	}

	template <class T>
	void nodoBB_t<T>::set_right(nodoBB_t<T>* nodo)
	{
		right_ = nodo;
	}

	template <class T>
	nodoBB_t<T>* nodoBB_t<T>::get_right(void) const
	{
		return right_;
	}

	template <class T>
	nodoBB_t<T>*& nodoBB_t<T>::get_set_right(void)
	{
		return right_;
	}

	template <class T>
	void nodoBB_t<T>::set_clave(const T& clave)
	{
		clave_ = clave;
	}

	template <class T>
	T & nodoBB_t<T>::get_set_clave(void)
	{
		return clave_;
	}
        template <class T>
        ostream & nodoBB_t<T>::write(ostream & os)
        {
            clave_.write(os);            
            return os;
        }
        template <>
        ostream & nodoBB_t<int>::write(ostream & os)
        {
            os << clave_;
            return os;
        }

        template <>
        ostream & nodoBB_t<double>::write(ostream & os)
        {
            os << clave_;
            return os;
        }
        template <>
        ostream & nodoBB_t<char>::write(ostream & os)
        {
            os << clave_;
            return os;
        }
        template <class T>
        int & nodoBB_t<T>::get_set_nivel(void)
        {
            return nivel_;
        }
}



    
