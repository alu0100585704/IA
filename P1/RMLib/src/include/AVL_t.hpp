#pragma once

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ArbolBB_t.hpp>
#include <cstdlib>


using namespace RMLIB;
namespace RMLIB {
    

template <class T>
class AVL_t : public ArbolBB_t<T>
{
    public:
    AVL_t(void);
    ~AVL_t(void);
    void Insertar( T &clave);
    void inserta_bal( nodoBB_t<T> * &nodo,nodoBB_t<T> * nuevo, bool& crece);
    void insert_re_balancea_izda(nodoBB_t<T> * &nodo,bool & crece);
    void insert_re_balancea_dcha (nodoBB_t<T> * &nodo, bool & crece);
    void rotacion_ID (nodoBB_t<T> * &nodo);
    void rotacion_DI (nodoBB_t<T> * &nodo); 
    void rotacion_II (nodoBB_t<T>* &nodo);
    void rotacion_DD (nodoBB_t<T> * &nodo);
    void eliminar_re_balancea_dcha (nodoBB_t<T>* &nodo, bool& decrece);
    void eliminar_re_balancea_izda (nodoBB_t<T>* &nodo, bool& decrece);
    void elimina_rama( nodoBB_t<T>* &nodo,T  clave, bool& decrece);
    void Eliminar( T & clave);
    void sustituye(nodoBB_t<T>* &eliminado,nodoBB_t<T>* &sust, bool &decrece);
    
};


}
