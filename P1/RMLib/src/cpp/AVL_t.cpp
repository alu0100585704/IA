#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ArbolBB_t.hpp>
#include <cstdlib>
#include <nodoAVL_t.hpp>
#include <AVL_t.hpp>

using namespace RMLIB;
namespace RMLIB {
    

template <class T>
AVL_t<T>::AVL_t(void) : ArbolBB_t<T>()
{
    
}

template <class T>
AVL_t<T>::~AVL_t(void)
{
    
}

template <class T>
void AVL_t<T>::Insertar( T &clave) 
{
    nodoBB_t<T> * nuevo = new nodoAVL_t<T>( clave);
    bool crece = false;
    inserta_bal(this->raiz_, nuevo, crece);
}
template <class T>
void AVL_t<T>::inserta_bal( nodoBB_t<T>* &nodo,nodoBB_t<T>* nuevo, bool& crece)
{
if (nodo == NULL) 
{
nodo = nuevo;
crece = true;
}
else if (nuevo->get_set_clave() < nodo->get_set_clave())
        {
           inserta_bal(nodo->get_set_left(),nuevo,crece);
                   if (crece) insert_re_balancea_izda(nodo,crece);
        }
else 
    {
            inserta_bal(nodo->get_set_right(),nuevo,crece);
            if (crece) insert_re_balancea_dcha(nodo,crece);
    }
}

template <class T>
void AVL_t<T>::insert_re_balancea_izda(nodoBB_t<T> * &nodo,bool & crece) 
{
switch (nodo->get_set_bal()) {
case -1: nodo->get_set_bal() = 0;
crece = false;
break;
case 0: nodo->get_set_bal() = 1 ;
break;
case 1: nodoBB_t<T> * nodo1 = nodo->get_set_left();
if (nodo1->get_set_bal() == 1)
        rotacion_II(nodo);
    else rotacion_ID(nodo);
   crece = false;
}
}
template <class T>
void AVL_t<T>::insert_re_balancea_dcha (nodoBB_t<T> * &nodo, bool & crece)
{
    switch (nodo->get_set_bal()) 
        {
        case 1: nodo->get_set_bal() = 0;
            crece = false;
            break;
        case 0: 
                nodo->get_set_bal() = -1;
                break;
        case -1: 
                nodoBB_t<T> * nodo1 = nodo->get_set_right();
        if (nodo1->get_set_bal() == -1)
                rotacion_DD(nodo);
        else rotacion_DI(nodo);
             
          crece = false;
        }
}

template <class T>
void AVL_t<T>::rotacion_DD (nodoBB_t<T> * &nodo) 
{
nodoBB_t<T> * nodo1 = nodo->get_set_right();
nodo->get_set_right() = nodo1->get_set_left();
nodo1->get_set_left() = nodo ;
if (nodo1->get_set_bal() == -1) {
nodo->get_set_bal() = 0;
nodo1->get_set_bal() = 0;
}
else { // nodo1->bal == 0
nodo->get_set_bal() = -1;
nodo1->get_set_bal() = 1;
}
nodo = nodo1;
}

template <class T>
void AVL_t<T>::rotacion_II (nodoBB_t<T>* &nodo)
{
nodoBB_t<T> * nodo1 = nodo->get_set_left();
nodo->get_set_left() = nodo1->get_set_right();
nodo1->get_set_right() = nodo;
if (nodo1->get_set_bal() == 1) {
nodo->get_set_bal() = 0;
nodo1->get_set_bal() = 0;
}
else { // nodo1->bal == 0
nodo->get_set_bal() = 1;
nodo1->get_set_bal() = -1;
}
nodo = nodo1;
}

template <class T>
void AVL_t<T>::rotacion_ID (nodoBB_t<T> * &nodo) 
{
nodoBB_t<T> * nodo1 = nodo->get_set_left();
nodoBB_t<T> * nodo2 = nodo1->get_set_right();
nodo->get_set_left() = nodo2->get_set_right();
nodo2->get_set_right() = nodo;
nodo1->get_set_right() = nodo2->get_set_left();
nodo2->get_set_left() = nodo1;
    if (nodo2->get_set_bal() == -1)
            nodo1->get_set_bal() = 1;
    else nodo1->get_set_bal() = 0;

    if (nodo2->get_set_bal() == 1)
            nodo->get_set_bal() = -1;
    else nodo->get_set_bal() = 0;
    
nodo2->get_set_bal() = 0;
nodo = nodo2;
}

template <class T>
void AVL_t<T>::rotacion_DI (nodoBB_t<T> * &nodo) 
{
nodoBB_t<T> * nodo1 = nodo->get_set_right();
nodoBB_t<T> * nodo2 = nodo1->get_set_left();
nodo->get_set_right() = nodo2->get_set_left();
nodo2->get_set_left() = nodo;
nodo1->get_set_left()= nodo2->get_set_right();
nodo2->get_set_right() = nodo1;
    if (nodo2->get_set_bal() == 1)
            nodo1->get_set_bal() = -1;
    else nodo1->get_set_bal() = 0;

    if (nodo2->get_set_bal() == -1)
            nodo->get_set_bal() = 1;
    else nodo->get_set_bal() = 0;

nodo2->get_set_bal() = 0;
nodo = nodo2;
}

template <class T>
void AVL_t<T>::Eliminar( T & clave)
{
    bool decrece = false;
   elimina_rama( this->raiz_, clave, decrece);
}

template <class T>
void AVL_t<T>::elimina_rama( nodoBB_t<T>* &nodo,T clave, bool& decrece)
{
if (nodo == NULL) return;
    if (clave < nodo->get_set_clave()) 
    {
            elimina_rama(nodo->get_set_left(),clave,decrece);
    if (decrece)
          eliminar_re_balancea_izda(nodo,decrece);
     }
   else if (clave > nodo->get_set_clave()) 
    {
                elimina_rama(nodo->get_set_right(),clave,decrece);
            if (decrece)
                   eliminar_re_balancea_dcha(nodo,decrece);
    }
    else 
    {    
        nodoBB_t<T> * Eliminado = nodo;
            if (nodo->get_set_left() == NULL) 
                {
                nodo = nodo->get_set_right();
                decrece = true;
                }
            else if (nodo->get_set_right() == NULL) 
                 {
                    nodo = nodo->get_set_left();
                    decrece = true;
                   }
     else 
     {
        sustituye(Eliminado,nodo->get_set_left(),decrece);
            if (decrece)
                    eliminar_re_balancea_izda(nodo,decrece);
    }
    delete Eliminado;
    }
        
}



template <class T>
void AVL_t<T>::sustituye(nodoBB_t<T>* &eliminado,nodoBB_t<T>* &sust, bool &decrece) 
{
    if (sust->get_set_right() != NULL) 
    {
        sustituye(eliminado, sust->get_set_right(), decrece);
    if (decrece)
        eliminar_re_balancea_dcha(sust, decrece);
    }
    else 
        {
        eliminado->get_set_clave()= sust->get_set_clave();
        eliminado = sust;
        sust = sust->get_set_left();
        decrece = true;
        }
}

template <class T>
void AVL_t<T>::eliminar_re_balancea_izda (nodoBB_t<T>* &nodo, bool& decrece) 
{
    nodoBB_t<T>* nodo1 = nodo->get_set_right();

    switch (nodo->get_set_bal())    
{
        case 1: 
                nodo->get_set_bal() = 0;
                break;
        case 0: nodo->get_set_bal() = -1;
                decrece = false;
                break;

        case -1:                 
                    if (nodo1->get_set_bal() > 0)
                        rotacion_DI(nodo);
                    else 
                        {
                        if (nodo1->get_set_bal() == 0)
                            decrece = false;
                            rotacion_DD(nodo);
                         }
                break;
        
    }
}

template <class T>
void AVL_t<T>::eliminar_re_balancea_dcha (nodoBB_t<T>* &nodo, bool& decrece) 
{
nodoBB_t<T>* nodo1 = nodo->get_set_left();
    switch (nodo->get_set_bal())
           {
                case 1: 

                        if (nodo1->get_set_bal() < 0)
                            rotacion_ID(nodo);
                        else 
                            {
                            if (nodo1->get_set_bal() == 0)
                                decrece = false;
                                rotacion_II(nodo);
                            }
                        break ;
                case 0: 
                        nodo->get_set_bal() = 1;
                        decrece = false;
                        break;
                case -1: 
                        nodo->get_set_bal() = 0;
                        break;
                }
}

}
