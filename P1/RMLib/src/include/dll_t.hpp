#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

#include <dll_node_t.hpp>


using namespace std;

namespace RMLIB {

    template <class T>
    class dll_t {
    private:
        dll_node_t<T>* head_;
        dll_node_t<T>* tail_;

        int sz_;

    public:
        dll_t(void);
        virtual ~dll_t(void); 

	void insert_tail_nodo(dll_node_t<T>*);
        void insert_head_nodo(dll_node_t<T>*);

        dll_node_t<T>*  extract_tail_nodo(void);
        dll_node_t<T>*  extract_head_nodo(void);

        dll_node_t<T>* get_tail_nodo(void);
        dll_node_t<T>* get_head_nodo(void);

        void remove_nodo(dll_node_t<T>*);

        void insert_tail_valor(T valor);
        void insert_tail_valor(T valor,int valor1);
        void insert_tail_valor(T valor, double valor2);
        void insert_tail_valor(T valor, char  valor3);
        
        void insert_head_valor(T  valor);        
        void insert_head_valor(T valor,int valor1);
        void insert_head_valor(T  valor, double valor2);
        void insert_head_valor(T  valor, char  valor3);
        


        T  extract_tail_valor(void);
        T  extract_tail_valor(int &valor1);
        T  extract_tail_valor(double & valor1);
        T  extract_tail_valor(char & valor1);
        
        T  extract_head_valor(void);
        T  extract_head_valor(int & valor1);
        T  extract_head_valor(double &valor2);
        T  extract_head_valor(char &valor3);
        
        
        T & get_set_tail_valor(void);
        T & get_set_head_valor(void);


        bool empty(void);


        int get_size(void);

        ostream& write(ostream& os);
                   
        template <class U>
        friend ostream & operator << (ostream & os, dll_t<U> & valor);
            
    };



}
