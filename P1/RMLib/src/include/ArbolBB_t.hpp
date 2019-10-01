/*
 Funciones de árboles binarios de busqueda
 */
#pragma once
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include "nodoBB_t.hpp"


//#define TREE_EPS 1E-3

using namespace std;
namespace RMLIB {

template <class T>
class ArbolBB_t {
   protected:

        nodoBB_t<T> * raiz_;

    ostream& write_inorden(nodoBB_t<T>* nodo, ostream& os);
    ostream & write_niveles(ostream & os);
    void sustituye(nodoBB_t<T> * & eliminado,nodoBB_t<T>* & sust);
public:
    ArbolBB_t(void);
    virtual ~ArbolBB_t(void);
    virtual void Eliminar( T &  clave);
    virtual void Insertar( T &clave);

    void Podar(nodoBB_t<T> * &nodo);
    bool EsVacio(nodoBB_t<T> *nodo);
    bool EsHoja(nodoBB_t <T>*nodo);
    nodoBB_t<T>* Buscar(T & clave);
    nodoBB_t<T>* BuscarRama( nodoBB_t<T>*& nodo,T & clave);
    void InsertarRama( nodoBB_t<T>* & nodo,T &clave,int nivel);
    int EliminarRama( nodoBB_t<T> * & nodo,T  & clave);
        ostream & write(int modo,ostream & os);

};
}
