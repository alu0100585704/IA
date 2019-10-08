#pragma once
#include <dll_t.hpp>
#include <EstadoIA_t.hpp>
#include <set>
#include <utility>
#include <vector>
template <class T>
class NodeIA_t {

public:

    T  estado_;
    vector<pair<pair<int,double>,NodeIA_t<T>*>> LS_; //conjunto de parejas.
     //pareja.first = pareja de numero de nodos y costo del nodo
    //pareja.second = puntero hacia nodo NodeIA_t<T> *, contendrá NULL en el grafo y
    //posición hacia un  nodo en memoria durante el arbol de busqueda IA.

    //atributos usados al crear el árbol de búsqueda
    int profundidad_;
    string accion_;
    NodeIA_t<T> * padre_; //puntero hacia un único padre."para los árboles de búsqueda"


    bool estudiado_;

       NodeIA_t();
       ~NodeIA_t();
       void limpiar();

       template <class U>
       friend ostream & operator << (ostream & os, NodeIA_t<U> & valor);

};

template <class T>
NodeIA_t<T>::NodeIA_t():
    profundidad_(0),
    accion_(""),
    padre_(NULL),
    estudiado_(false),
    estado_()
{


}
template <class T>
NodeIA_t<T>::~NodeIA_t()
{
    limpiar();
}
template <class T>
void NodeIA_t<T>::limpiar()
{
    padre_=NULL;
    LS_.clear();
    profundidad_=0;
    accion_="";
    padre_=NULL;
    estudiado_=false;
    estado_.limpiar();


}

template <class U>
ostream & operator << (ostream & os, NodeIA_t<U> &valor)
{
    os << valor.estado_;
return os;

}
