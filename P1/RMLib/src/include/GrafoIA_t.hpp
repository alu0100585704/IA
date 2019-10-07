#pragma once

#include <dll_t.hpp>
#include <NodeIA_t.hpp>
#include <EstadoIA_t.hpp>
#include <dll_node_t.hpp>
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class GrafoIA_t {

private:

 RMLIB::dll_t<NodeIA_t<T>> grafo_;
 int numeroNodos_;

public:



    GrafoIA_t();
    GrafoIA_t(char nombrefichero[]);

    ~GrafoIA_t();

    bool actualizar(char nombrefichero[]);
    bool empy();
    void limpiar();    

    template<class U>
    friend ostream & operator << (ostream & os, GrafoIA_t<U> &valor);

};

//muestra el grafo como un árbol.
template<class U>
ostream & operator << (ostream & os, GrafoIA_t<U> & valor)
{
    RMLIB::dll_node_t<NodeIA_t<U>> * aux = valor.grafo_.get_head_nodo();

                    while (aux != NULL) {

                        os << endl << "El Nodo : " << *aux << " es padre de : " << endl;
                        os << aux->get_set_data().LS_ << endl;
                        aux = aux->get_next();
                    }


   return os;

}


template<class T>
GrafoIA_t<T>::GrafoIA_t():
    numeroNodos_(0)
{

}

template<class T>
GrafoIA_t<T>::GrafoIA_t(char nombrefichero[])
{
       actualizar(nombrefichero);
}

template<class T>
GrafoIA_t<T>::~GrafoIA_t()
{
    limpiar();
}

template<class T>
bool GrafoIA_t<T>::actualizar(char nombrefichero[])
{
    int i, j;
    double temp;
    ifstream fichero_grafo;

    limpiar(); //por si acaso ya se hab�a abierto alg�n fichero, libero las posibles bloques de memoria reservados.

     fichero_grafo.open(nombrefichero);

    if (fichero_grafo.is_open())
    {
        fichero_grafo >> numeroNodos_;
         for (int i=1; i < numeroNodos_;i++)
         {

             grafo_.insert_tail_valor(); //crea nodo nuevo.
             grafo_.get_set_tail_valor().estado_=i;


             for (int j=0; j < numeroNodos_-i;j++)
             {
                 fichero_grafo >> temp; //leo el costo
                 if (temp!=-1) //si es igual a -1, valor escogido para infinito, o sea, inalcanzable.
                 {
                     grafo_.get_set_tail_valor().LS_.insert_tail_valor();
                     grafo_.get_set_tail_valor().LS_.get_set_tail_valor().estado_=i+j+1;
                     grafo_.get_set_tail_valor().LS_.get_set_tail_valor().costo_==temp;  //lo que costó ir hasta el siguiente

                 }

             }


         }

         grafo_.insert_tail_valor(); //crea nodo nuevo.
         grafo_.get_set_tail_valor().estado_=numeroNodos_;


         fichero_grafo.close();
        return true;

    }
      else return false;

}

template<class T>
bool GrafoIA_t<T>::empy()
{

    if (numeroNodos_==0)
        return 1;
    else return 0;
}

template<class T>
void GrafoIA_t<T>::limpiar()
{
    grafo_.limpiar();
    numeroNodos_=0;
}
