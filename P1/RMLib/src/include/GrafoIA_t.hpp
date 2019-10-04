#pragma once

#include <dll_t.hpp>
#include <NodeIA_t.hpp>
#include <EstadoIA_t.hpp>
#include <dll_node_t.hpp>
#include <fstream>
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
    void limpiar();


};



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
    ifstream fichero_grafo;

    limpiar(); //por si acaso ya se hab�a abierto alg�n fichero, libero las posibles bloques de memoria reservados.

     fichero_grafo.open(nombrefichero);

    if (fichero_grafo.is_open())
    {
        fichero_grafo >> numeroNodos_;
         for (int i=1; i < numeroNodos_;i++)
         {
             grafo_.insert_tail_valor(); //crea nodo nuevo.
             grafo_.get_set_tail_valor().estado_=1;


             for (int j=0; j < numeroNodos_-i;j++)
             {
                 grafo_.get_set_tail_valor().LS_.insert_tail_valor();
                 grafo_.get_set_tail_valor().LS_.get_set_tail_valor().estado_=i+j+1;

                fichero_grafo >> grafo_.get_set_tail_valor().LS_.get_set_tail_valor().costo_;  //lo que costó ir hasta el siguiente
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
void GrafoIA_t<T>::limpiar()
{
    grafo_.limpiar();
    numeroNodos_=0;
}
