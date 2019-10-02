#pragma once
#include <QString>
#include <dll_t.hpp>
#include <EstadoIA_t.hpp>
template <class T>
class NodeIA_t {
private:
     EstadoIA_t * estado_;
     int profundidad_;
     double costo_;
     QString accion_;
     RMLIB::dll_t<NodeIA_t> * LS_; //hijos de este nodo.
     NodeIA_t *padre_; //puntero hacia un único padre."para los árboles de búsqueda"
     bool estudiado_;

public:
       NodeIA_t();
       ~NodeIA_t();
       void inicializar();
};
