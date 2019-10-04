#pragma once
#include <dll_t.hpp>
#include <EstadoIA_t.hpp>

template <class T>
class NodeIA_t {

public:

    T  estado_;
    int profundidad_;
    double costo_;
    string accion_;
    RMLIB::dll_t<NodeIA_t<T>> LS_; //hijos de este nodo.
    NodeIA_t<T> * padre_; //puntero hacia un único padre."para los árboles de búsqueda"
    bool estudiado_;

     NodeIA_t();
       ~NodeIA_t();
       void limpiar();
};

template <class T>
NodeIA_t<T>::NodeIA_t():
    profundidad_(0),
    costo_(0),
    accion_(""),
    padre_(NULL),
    estudiado_(false),
    estado_()
{


}
template <class T>
NodeIA_t<T>::~NodeIA_t()
{
    padre_=NULL;
}
template <class T>
void NodeIA_t<T>::limpiar()
{
   profundidad_=0;
   costo_=0;
   accion_="";
   padre_=NULL;
   estudiado_=false;
   estado_.limpiar();
   LS_.limpiar();

}
