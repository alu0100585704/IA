#pragma once
#include <utility>
#include <dll_t.hpp>
#include <NodeIA_t.hpp>
#include <EstadoIA_t.hpp>
#include <dll_node_t.hpp>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class GrafoIA_t {

private:

 vector<NodeIA_t<T>> grafo_;
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

   for (int i=0; i < valor.grafo_.size(); i++)
   {
               os << endl << "El nodo : " << valor.grafo_[i].estado_.id_ << "es padre de : " << endl;

               for(int j=0; j< valor.grafo_[i].LS_.size();j++)
                   os << "Nodo : "<< valor.grafo_[i].LS_[j].first.first << " Costo: " <<valor.grafo_[i].LS_[j].first.second << endl;

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
    NodeIA_t<T> nodo;
    pair<pair<int,double>,NodeIA_t<T>*> sucesor;

    limpiar(); //por si acaso ya se hab�a abierto alg�n fichero, libero las posibles bloques de memoria reservados.

     fichero_grafo.open(nombrefichero);

    if (fichero_grafo.is_open())
    {
        //version nodos entrelazados entre si

         fichero_grafo >> numeroNodos_;

         for (int i=1; i <= numeroNodos_;i++)
         {
                     nodo.estado_.id_=i;
                     grafo_.push_back(nodo);  //creo todos los nodos de entrada.
          }

         for (int i=1; i < numeroNodos_;i++)
         {
             for (int j=0; j < numeroNodos_-i;j++)
            {
                fichero_grafo >> temp; //leo el costo

                if (temp!=-1) //si es igual a -1, valor escogido para infinito, o sea, inalcanzable.
                {
                    sucesor.first.first=i+j+1; //numero de nodo sucesor
                    sucesor.first.second=temp; //costo para llegar a ese nodo
                    sucesor.second=NULL; //inicialmente el puntero hacia el sucesor es  nulo, este valor lo modifica solo el arbol de búsqueda.
                    grafo_[i-1].LS_.push_back(sucesor);

                    sucesor.first.first=i;     //indico al sucesor que este nodo es predecesor
                    grafo_[i+j].LS_.push_back(sucesor);

                }

            }

           }


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
    grafo_.clear();
    numeroNodos_=0;
}
