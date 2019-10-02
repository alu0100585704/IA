#include <GrafoIA_t.hpp>
#include <iostream>
#include <fstream>


template<class T>
GrafoIA_t<T>::GrafoIA_t():
    grafo_(new RMLIB::dll_t<NodeIA_t>)
{

}

template<class T>
GrafoIA_t<T>::GrafoIA_t(char nombrefichero[], int &errorapertura)
{
       actualizar(nombrefichero,errorapertura);
}

template<class T>
GrafoIA_t<T>::~GrafoIA_t()
{
    liberarMemoria();
}

template<class T>
int GrafoIA_t<T>::actualizar(char nombrefichero[], int &errorapertura)
{
    int i, j, contador;
    NodeIA_t nodoBorrador;
    NodeIA_t nodoBorradorSucesores;
    ifstream fichero_grafo;

    liberar_memoria(); //por si acaso ya se hab�a abierto alg�n fichero, libero las posibles bloques de memoria reservados.

     fichero_grafo.open(nombrefichero);

    if (fichero_grafo.is_open())
    {
        fichero_grafo >> numeroNodos_;
         for (int i=1; i < numeroNodos_;i++)
         {
             nodoBorrador.inicializar();
             nodoBorrador.estado_->ID_=i;  //identificador, número del nodo.

              nodoBorradorSucesores.inicializar();
             for (int j=0; j < numeroNodos_-i;j++)
             {
                nodoBorradorSucesores.estado_->ID_=i+j+1;
                fichero_grafo >> nodoBorradorSucesores.costo_; //lo que costó ir hasta el siguiente
                nodoBorrador.LS_->insert_tail_valor(nodoBorradorSucesores);
             }


             grafo_->insert_tail_valor(nodoBorrador);

         }

         nodoBorrador.inicializar();
         nodoBorrador.estado_->ID_=numeroNodos_;
         grafo_->insert_tail_valor(nodoBorrador);

         fichero_grafo.close();

    }
      else errorapertura=1;

    return errorapertura;

}

template<class T>
void GrafoIA_t<T>::liberarMemoria()
{
    delete grafo_;
}
