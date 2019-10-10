#pragma once
#include <dll_t.hpp>
#include <EstadoIA_t.hpp>
#include <set>
#include <utility>
#include <vector>

class NodeIA_t {

public:

    EstadoIA_t  estado_;
    //vector<pair<pair<int,double>,NodeIA_t<T>*>> LS_; //conjunto de parejas.
     //pareja.first = pareja de numero de nodos y costo del nodo
    //pareja.second = puntero hacia nodo NodeIA_t<T> *, contendrá NULL en el grafo y
    //posición hacia un  nodo en memoria durante el arbol de busqueda IA.

    //atributos usados al crear el árbol de búsqueda

    vector<pair<int,double>> LS_; //conjunto de parejas. numero de nodo y costo
    double  valorHeuristico_;  //h(n) valor heuristico hasta el nodo objetivo.
    double  costoCamino_;  //funcion g(n) //costo real del camino hasta el nodo
    double  costoCaminoMasHeuristico_; //funcion F(n)=g(n) +h(n)
    int profundidad_;
    string accion_;
    int  padre_; //numero de nodo padre.


    bool estudiado_;

       NodeIA_t();
       ~NodeIA_t();
       void limpiar();
    bool operator < (const NodeIA_t &valor) const ; //comprobacion en base al al funcion f(n).
    bool operator == (const NodeIA_t &valor)const ; //comprobacion en base al id_(numero de nodo de estado)


       friend ostream & operator << (ostream & os, NodeIA_t & valor);

};


NodeIA_t::NodeIA_t():
    profundidad_(0),
    accion_(""),
    padre_(0),
    estudiado_(false),
    estado_(),
    costoCamino_(0),
    valorHeuristico_(0),
    costoCaminoMasHeuristico_(0)
{


}


NodeIA_t::~NodeIA_t()
{
    limpiar();
}

void NodeIA_t::limpiar()
{
    padre_=0;
    LS_.clear();
    profundidad_=0;
    accion_="";    
    estudiado_=false;    
    costoCamino_=0;
    costoCaminoMasHeuristico_=costoCamino_+valorHeuristico_;
    estado_.limpiar();


}


bool NodeIA_t::operator <(const NodeIA_t & valor) const
{
    if (this->costoCaminoMasHeuristico_ < valor.costoCaminoMasHeuristico_)
        return 1;
    else return 0;
}


bool NodeIA_t::operator ==(const NodeIA_t &valor) const
{
    if (this->estado_== valor.estado_)
        return 1;
    else return 0;
}



ostream & operator << (ostream & os, NodeIA_t &valor)
{
    os << valor.estado_;
return os;

}
