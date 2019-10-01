#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

namespace RMLIB {

    template <class T>
    class Grafodll_node_t {
    private:

        vector<Grafodll_node_t<T>>     LS_;        // Lista de adyacencia de los sucesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño//
        Grafodll_node_t<T>     Padre;        // Lista de adyacencia de los predecesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño//

        bool        visitado;  //valmacenar informacion de visitado o no en caso de recorridos.
        T              data_;
        int            nivel_;   //diferentes valores que se pueden agregar a un nodo lista para utilizar segun snecesidades , siendo así un nodo con más informaicon
        double         costo_;
        string action_;

    public:
        Grafodll_node_t();
    Grafodll_node_t(const T& data);

        virtual ~Grafodll_node_t(void);

    void set_next(Grafodll_node_t<T>*);
    void set_prev(Grafodll_node_t<T>*);

    Grafodll_node_t<T>* get_next(void) const;
    Grafodll_node_t<T>* get_prev(void) const;

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
        friend ostream & operator << (ostream & os, Grafodll_node_t<U> & valor);

    };



}
