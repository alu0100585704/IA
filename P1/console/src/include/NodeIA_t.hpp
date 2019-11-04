#pragma once
#include <EstadoIA_t.hpp>
#include <set>
#include <utility>
#include <vector>

class NodeIA_t {

public:

    EstadoIA_t  estado_;

    //atributos usados al crear el árbol de búsqueda

    vector< pair<int,double> > LS_; //conjunto de parejas. numero de nodo y costo
    double  valorHeuristico_;  //h(n) valor heuristico hasta el nodo objetivo.
    double  costoCamino_;  //funcion g(n) //costo real del camino hasta el nodo
    double  costoCaminoMasHeuristico_; //funcion F(n)=g(n) +h(n)
    int profundidad_;    
    string accion_;

    const NodeIA_t * padrePuntero_; //usado por la version 1 del algoritmo
    int  padre_; //numero de nodo padre, solo usado por la version 2 del algoritmo
    mutable  bool estudiado_;


       NodeIA_t();
       ~NodeIA_t();
       void limpiar();
    bool operator < (const NodeIA_t &valor) const ; //comprobacion en base al al funcion f(n), o sea, valor atributo costoCaminoMasHeuristico_
    bool operator == (const NodeIA_t &valor)const ; //comprobacion en base al id_(numero de nodo de estado)

    const NodeIA_t * current() const; //devuelve un puntero hacia este objeto

       friend ostream & operator << (ostream & os, NodeIA_t & valor);

};

const NodeIA_t * NodeIA_t::current() const
{
    return this;
}


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
