#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

namespace RMLIB {

    template <class T>
    class dll_node_t {
    private:

        dll_node_t<T>* next_;
        dll_node_t<T>* prev_;

	T              data_;
        int            valor1_;   //diferentes valores que se pueden agregar a un nodo lista para utilizar segun snecesidades , siendo así un nodo con más informaicon
        double         valor2_;
        char           valor3_;
        

    public:
        dll_node_t();
	dll_node_t(const T& data);

        virtual ~dll_node_t(void);

	void set_next(dll_node_t<T>*);
	void set_prev(dll_node_t<T>*);

	dll_node_t<T>* get_next(void) const;
	dll_node_t<T>* get_prev(void) const;

	void set_data(T& data);
        void set_valor1(int valor1);
        void set_valor2(double valor2);
        void set_valor3(char valor3);
	T & get_set_data(void);
        int & get_set_valor1(void);
        double & get_set_valor2(void);
        char  & get_set_valor3(void);
        
	ostream& write(ostream& os) const;
        
        template <class U>
        friend ostream & operator << (ostream & os, dll_node_t<U> & valor);

    };



}
