/*
 Funciones de árboles binarios de busqueda
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <nodoBB_t.hpp>
#include <ArbolBB_t.hpp>
#include <dll_t.hpp>
//#define TREE_EPS 1E-3

using namespace std;
namespace RMLIB {

template <class T>
ArbolBB_t<T>::ArbolBB_t(void):
raiz_(NULL)
{}
template <class T>
ArbolBB_t<T>::~ArbolBB_t(void)
{
    Podar(raiz_);
}
template <class T>
void ArbolBB_t<T>::Podar(nodoBB_t<T>* &nodo)
{
if (nodo == NULL) return ;
    Podar(nodo->get_set_left()); // Podar subarbol izquierdo
    Podar(nodo->get_set_right()); // Podar subarbol derecho
    delete nodo; // Eliminar nodo
    nodo = NULL;
}

template <class T>
bool ArbolBB_t<T>::EsVacio(nodoBB_t<T> *nodo) {
return nodo == NULL;
}
template <class T>
bool ArbolBB_t<T>::EsHoja(nodoBB_t<T> *nodo) {
return !nodo->get_right() && !nodo->get_left();
}
template <class T>
nodoBB_t<T>* ArbolBB_t<T>::Buscar(T & clave)
{
        return BuscarRama(raiz_,clave);
}
template <class T>
nodoBB_t<T>* ArbolBB_t<T>::BuscarRama( nodoBB_t<T>*& nodo,T & clave)
{
if (nodo == NULL)
return NULL ;
if (clave == nodo->get_set_clave())
return nodo ;
if (clave < nodo->get_set_clave() )
return BuscarRama(nodo->get_set_left(), clave);
return BuscarRama(nodo->get_set_right(), clave);
}

template <class T>
void ArbolBB_t<T>::Insertar(T & clave)
{
 InsertarRama(raiz_,clave,-1);
}

template <class T>
void ArbolBB_t<T>::InsertarRama( nodoBB_t<T>*& nodo,T & clave,int nivel)
{
    nivel++;
 if (nodo == NULL)
    {
        nodo = new nodoBB_t<T>(clave);
        nodo->get_set_nivel()=nivel;
    }
 else if (clave < nodo->get_set_clave())
     InsertarRama(nodo->get_set_left(), clave,nivel);
else
        InsertarRama(nodo->get_set_right(), clave,nivel);


}

template <class T>
void ArbolBB_t<T>::Eliminar( T &  clave)
{
    EliminarRama(raiz_, clave) ;
}
template <class T>
int ArbolBB_t<T>::EliminarRama( nodoBB_t<T> * & nodo,T  & clave)
{
    if (nodo == NULL)
        return 0;

        if (clave < nodo->get_set_clave())
                    EliminarRama(nodo->get_set_left(), clave);
            else if (clave > nodo->get_set_clave())
                    EliminarRama(nodo->get_set_right(), clave);
            else { //clave == nodo_clave
                    nodoBB_t<T> * Eliminado = nodo;
                            if (nodo->get_right() == NULL)
                                    nodo = nodo->get_left();
                            else if (nodo->get_set_left() == NULL)
                                    nodo = nodo->get_set_right();
                            else
                                sustituye(Eliminado, nodo->get_set_left());

                            delete (Eliminado);
                    }


}
template <class T>
void ArbolBB_t<T>::sustituye(nodoBB_t<T>* &eliminado,nodoBB_t<T>* &sust)
{
        if (sust->get_right() != NULL)
                sustituye(eliminado, sust->get_set_right());
         else {
//                eliminado->Info = sust->Info ;
                eliminado->get_set_clave() = sust->get_set_clave();
                eliminado = sust ;
                sust = sust->get_left();
                }
}

template <class T>
ostream & ArbolBB_t<T>::write(int modo,ostream& os)
{
    switch (modo)
    {
        case 0: //implementacion imprimir por niveles estilo arbol
            write_niveles(os);
            break;
        case 1:
            //impresion modo recorrido in-orden o simetrico
            write_inorden(raiz_,os);
            break;
    }

    return os;

}

template <class T>
ostream& ArbolBB_t<T>::write_inorden(nodoBB_t<T>* nodo, ostream& os)
{
if (nodo != NULL)
        {
                      write_inorden(nodo->get_left(),os);
                      nodo->write(os);
                      os << endl;
                       write_inorden(nodo->get_right(),os);

        }


        return os;
}

template <class T>
ostream & ArbolBB_t<T>::write_niveles( ostream & os )
{
 dll_t<nodoBB_t<T>*> Q;
 nodoBB_t<T> * nodo;

int nivel;
int Nivel_actual=0;
if (EsVacio(raiz_))
    os << "Arbol Vacio"<<endl;

Q.insert_tail_valor(raiz_,0);

    while (!Q.empty())
    {
    nodo=Q.extract_head_valor(nivel);


                if ((nivel > Nivel_actual) || (nivel==0))
                    {
                         Nivel_actual = nivel; //Incremento de nivel
                         os << endl;
                         os << "----------------------------------------------------------------------"<< endl;
                         os << "Nivel " << nivel << ": ";



                      }
        if (nodo != NULL)
        {


            os << "[";
            nodo->write(os);
            os << "]";
            Q.insert_tail_valor(nodo->get_left(),nivel+1);
            Q.insert_tail_valor(nodo->get_right(),nivel+1);
        }
        else
            os << "[.]";

    }
os << endl;
return os;
}
}

        
     
