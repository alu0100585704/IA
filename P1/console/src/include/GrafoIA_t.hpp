#pragma once
#include <utility>
#include <NodeIA_t.hpp>
#include <EstadoIA_t.hpp>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


class GrafoIA_t {

private:

 vector<NodeIA_t> grafo_;
 vector<NodeIA_t> caminoSolucion_;
 int numeroNodos_;
 int nodoOrigen_,nodoDestino_;
 bool solucionEncontrada_;
 bool version1_; //será true si se usa la version 1(default) o false si se usa la version 2


 //VERSION 1

 // atributos para version 1 de un conjunto de datos, en el que se agregan  los nodos y se
 //marcan como estudiados no o estudiados. Estos nodos tienen punteros a sus nodos padres
 //para trazar el camino solución y conocer antes de generar un nuevo nodo hijo, si en su
 //camino ese nodo ya existe. Esta implementación permite tener en el conjunto el mismo nodo
 //repetido,puesto que se puede encontrar el mismo nodo en caminos diferents.
 int nodosGenerados_,nodosInspeccionados_;
 set<NodeIA_t> nodos_;


 //VERSION 2

 //atributos para version 2 que consiste en dos conjuntos de datos, uno para nodos generados
 //y otro para nodos inspeccionados. No se puede repetir ningún nodo, puesto que antes de generarlo
 //se comprueba que no exista ya en ninguno de los conjuntos. Por lo tanto puede perder opciones
 //de otros caminos mejores, sobre todo en caso de que la función heurística sea mala, pero es
 //muy rápido y consume menos memoria. Puede fallar al no siempre obtener el camino óptimo.

 set<NodeIA_t> generados_; //aqui uso set para que siempre se ponga el primero el node de menor
                //f(n)
 set<NodeIA_t> inspeccionados_;

public:


    GrafoIA_t();
    GrafoIA_t(char nombrefichero[]);

    ~GrafoIA_t();

    bool actualizar(char nombrefichero[]);
    bool empy();
    void limpiar();    
    void limpiarArbol();
    bool aplicarHeuristica(char nombrefichero[]);
    bool aEstrella(int nodoOrigen, int nodoDestino,bool version1);
    ostream &mostrarCaminoSolucion(ostream &os);
    friend ostream & operator << (ostream & os, GrafoIA_t &valor);
    string nombreFichero_,nombreFicheroHeuristica_;
private:

    void generarSucesores(set<NodeIA_t>::iterator &valor); //para version 1
    void generarSucesores(NodeIA_t &valor); //para version 2
    bool existeNodo(set<NodeIA_t>::iterator &valor,int sucesor);  //para version 1. este método devuelve false si no encuentra un nodo en concreto por us ID ni en lista de generados ni en lista de inspeccionados.
    bool existeNodo(int valor); //para version 2
    void crearCaminoSolucion(set<NodeIA_t>::iterator &valor); //para version 1
    void crearCaminoSolucion(NodeIA_t &valor); //para version 2

};



GrafoIA_t::GrafoIA_t():
    numeroNodos_(0),
    solucionEncontrada_(false),
    version1_(true),
    nodosGenerados_(0),
    nodosInspeccionados_(0)
{

}

GrafoIA_t::GrafoIA_t(char nombrefichero[])
{
       actualizar(nombrefichero);
}


GrafoIA_t::~GrafoIA_t()
{
    limpiar();
}


//muestra el grafo (no el arbol de busqueda ) indicando los hijos de cada nodo.

ostream & operator << (ostream & os, GrafoIA_t & valor)
{

   for (int i=0; i < valor.grafo_.size(); i++)
   {
               os << endl << "El nodo : " << valor.grafo_[i].estado_.id_ << "es padre de : " << endl;

               for(int j=0; j< valor.grafo_[i].LS_.size();j++)
                   os << "Nodo : "<< valor.grafo_[i].LS_[j].first << " Costo: " <<valor.grafo_[i].LS_[j].second << endl;

    }


   return os;

}




bool GrafoIA_t::actualizar(char nombrefichero[])
{
    int i, j;
    double temp;
    ifstream fichero_grafo;
    NodeIA_t nodo;    
    pair<int,double> sucesor;

    limpiar(); //por si acaso ya se hab�a abierto alg�n fichero, libero las posibles bloques de memoria reservados.

    nombreFichero_=&nombrefichero[0];

     fichero_grafo.open(nombrefichero);

    if (fichero_grafo.is_open())
    {
        //version nodos entrelazados entre si

         fichero_grafo >> numeroNodos_;

         for (int i=1; i <= numeroNodos_;i++)
         {
                     nodo.estado_.id_=i;                     
                     grafo_.push_back(nodo);  //creo todos los nodos de entrada.
          }

         for (int i=1; i < numeroNodos_;i++)
         {
             for (int j=0; j < numeroNodos_-i;j++)
            {
                fichero_grafo >> temp; //leo el costo

                if (temp!=-1) //si es igual a -1, valor escogido para infinito, o sea, inalcanzable.
                {
                    sucesor.first=i+j+1; //numero de nodo sucesor
                    sucesor.second=temp; //costo para llegar a ese nodo                    
                    grafo_[i-1].LS_.push_back(sucesor);

                    sucesor.first=i;     //indico al sucesor que este nodo es predecesor
                    grafo_[i+j].LS_.push_back(sucesor);

                }

            }

           }


         fichero_grafo.close();
        return true;

    }
      else return false;

}


bool GrafoIA_t::empy()
{

    if (numeroNodos_==0)
        return 1;
    else return 0;
}


bool  GrafoIA_t::aplicarHeuristica(char nombrefichero[])
{

    int temp;
    ifstream fichero_grafo;

    if (numeroNodos_==0)  //REGRESO PORQUE NO SE HA CARGADO TODAVÍA NINGUN GRAFO.
        return false;

        fichero_grafo.open(nombrefichero);

       if (fichero_grafo.is_open())
       {
           fichero_grafo >> temp;
            if (temp!=numeroNodos_)
            {
                fichero_grafo.close();
                return false;
            }
            for (int i=1; i <= numeroNodos_;i++)
                    fichero_grafo >> grafo_[i-1].valorHeuristico_;


            fichero_grafo.close();
              nombreFicheroHeuristica_=&nombrefichero[0];
           return true;

       }
       else return false;
}

//
// Muestro tabla con informacion sobre la busqueda.
//
ostream & GrafoIA_t::mostrarCaminoSolucion(ostream &os)
{
set<NodeIA_t>::iterator itNodo;

 if (version1_)
 {
           os << endl << "------------------------------------------------------------" << endl;
           os << "Version 1 del algoritmo(Recomendado): Un solo Conjunto"<< endl;
           os << "Grafo                          : " << nombreFichero_ << endl;
           os << "Heuristica Aplicada            : " << nombreFicheroHeuristica_ << endl;
           os << "Numero de nodos                : " << numeroNodos_ << endl;
           os << "Nodo Origen                    : " << nodoOrigen_ << endl;
           os << "Nodo Destino                   : " << nodoDestino_ << endl;
           os << "Numero de nodos en la solucion : " << caminoSolucion_.size()<< endl;
           //os << "Cantidad Nodos Generados Total : " << nodosGenerados_+nodosInspeccionados_<< endl;
           os << "Cantidad Nodos Generados       : " << nodosGenerados_<< endl;
           os << "Cantidad Nodos Inspeccionados  : " << nodosInspeccionados_<< endl;
           os << "Cantidad Nodos Sin Inspeccionar: " << nodosGenerados_-nodosInspeccionados_<< endl;
           os << "Camino Solucion  Nodo(g(n))    : " ;
           //Muestro Camino solucion con su distancia.
           ///Aqui tengo que recorrer el vector caminoSolucion_ desde el final hacia el principio.
           for (int i=caminoSolucion_.size(); i >0;i--)
               //os <<  "Nodo => " << caminoSolucion_[i-1].estado_ << " - Coste g(n)=> " << caminoSolucion_[i-1].costoCamino_ << " - Valor Heuristico => " << caminoSolucion_[i-1].valorHeuristico_ << endl;
               os <<  caminoSolucion_[i-1].estado_ << "(" << caminoSolucion_[i-1].costoCamino_  << ") - ";


           os << endl << endl << endl <<  "- - -  FORMATO : Nodo=g(n)h(n)f(n) - - -" << endl << endl;
           os << "Generados Sin Inspeccionar     : " ;
           //
           // Muestro los nodos generados
           //
           for (itNodo=nodos_.begin();itNodo!= nodos_.end(); itNodo++)
               if (!itNodo->estudiado_)
                    os << itNodo->estado_.id_ << "(" << itNodo->costoCamino_ << ")" << "(" << itNodo->valorHeuristico_<< ")"<<"("<< itNodo->costoCaminoMasHeuristico_<< ")- ";


           os << endl<< endl;
           os << "Nodos Inspeccionados           : ";
           //
           // Muestro los nodos inespeccionados
           //
           for (itNodo=nodos_.begin();itNodo!= nodos_.end(); itNodo++)
               if (itNodo->estudiado_)
                    os << itNodo->estado_.id_ << "(" << itNodo->costoCamino_ << ")" << "(" << itNodo->valorHeuristico_<< ")"<<"("<< itNodo->costoCaminoMasHeuristico_<< ")- ";
 }
 else {
     os << endl << "------------------------------------------------------------" << endl;
     os << "Version 2 del algoritmo: Dos conjuntos, no se repiten nodos"<< endl;
     os << "Grafo                          : " << nombreFichero_ << endl;
     os << "Heuristica Aplicada            : " << nombreFicheroHeuristica_ << endl;
     os << "Numero de nodos                : " << numeroNodos_ << endl;
     os << "Nodo Origen                    : " << nodoOrigen_ << endl;
     os << "Nodo Destino                   : " << nodoDestino_ << endl;
     os << "Numero de nodos en la solucion : " << caminoSolucion_.size()<< endl;
     os << "Cantidad Nodos Generados       : " << generados_.size()+inspeccionados_.size()<< endl;
     os << "Cantidad Nodos Inspeccionados  : " << inspeccionados_.size()<< endl;
     os << "Cantidad Nodos Sin Inspeccionar: " << generados_.size()<< endl;
     os << "Camino Solucion  Nodo(g(n))    : " ;
     //Muestro Camino solucion con su distancia.
     ///Aqui tengo que recorrer el vector caminoSolucion_ desde el final hacia el principio.
     for (int i=caminoSolucion_.size(); i >0;i--)
         //os <<  "Nodo => " << caminoSolucion_[i-1].estado_ << " - Coste g(n)=> " << caminoSolucion_[i-1].costoCamino_ << " - Valor Heuristico => " << caminoSolucion_[i-1].valorHeuristico_ << endl;
         os <<  caminoSolucion_[i-1].estado_ << "(" << caminoSolucion_[i-1].costoCamino_  << ") - ";

     os << endl <<endl << endl <<  "FORMATO : Nodo=g(n)h(n)f(n) : " << endl << endl;
     os << "Generados Sin Inspeccionar     : " ;
     //
     // Muestro los nodos generados
     //
     for (itNodo=generados_.begin();itNodo!= generados_.end(); itNodo++)
         //os << itNodo->estado_.id_ << ",";
         os << itNodo->estado_.id_ << "(" << itNodo->costoCamino_ << ")" << "(" << itNodo->valorHeuristico_<< ")"<<"("<< itNodo->costoCaminoMasHeuristico_<< ")- ";

     os << endl<<endl;
     os << "Nodos Inspeccionados           : ";
     //
     // Muestro los nodos inespeccionados
     //
     for (itNodo=inspeccionados_.begin();itNodo!= inspeccionados_.end(); itNodo++)
         //os << itNodo->estado_.id_ << ",";
         os << itNodo->estado_.id_ << "(" << itNodo->costoCamino_ << ")" << "(" << itNodo->valorHeuristico_<< ")"<<"("<< itNodo->costoCaminoMasHeuristico_<< ")- ";

      os << endl;

//
// Muestro nombre de grafo, numero de nodos, tamaño de la solucion, nodo origen, nodo destino.
//
//os << nombreFichero_ << " | " << numeroNodos_ << " | " << caminoSolucion_.size() << " | " << nodoOrigen_ << " | " << nodoDestino_ << " | ";


 }

 os << endl<<endl;

return os;

}
//version 1
bool GrafoIA_t::existeNodo(set<NodeIA_t>::iterator &valor,int sucesor)
{


    NodeIA_t aux;
    bool existe=false;

    aux=*valor;

    while ((aux.padrePuntero_!=NULL) && (existe==false))
    {

        aux=*(aux.padrePuntero_);

        if (aux.estado_.id_==sucesor)
            existe=true;
      }

    return existe;
}

//version 2
bool GrafoIA_t::existeNodo(int valor)
{
   set<NodeIA_t>::iterator itNodo;
    bool encontrado=false;
    itNodo=generados_.begin();

    //busco nodo en generados
    while ((itNodo!=generados_.end()) && (encontrado==false))
          {
                if (itNodo->estado_.id_==valor)
                        encontrado=true;
                itNodo++;
           }

    itNodo=inspeccionados_.begin();

    //busco nodo en inspeccionados
    while ((itNodo!=inspeccionados_.end()) && (encontrado==false))
    {
            if (itNodo->estado_.id_==valor)
                encontrado=true;
          itNodo++;
    }

    return encontrado;
}

//version 1
void GrafoIA_t::crearCaminoSolucion(set<NodeIA_t>::iterator &valor)
{
    NodeIA_t aux;        

    caminoSolucion_.clear();
    aux=*valor;
    caminoSolucion_.push_back(aux);    //introduzco primero nodo objetivo.

    while (aux.padrePuntero_!=NULL)
    {
        aux=*(aux.padrePuntero_);
        caminoSolucion_.push_back(aux);
      }


}

//version 2
void GrafoIA_t::crearCaminoSolucion(NodeIA_t &valor)
{
    NodeIA_t aux;
    set<NodeIA_t>::iterator itNodo;
    bool encontrado;

    caminoSolucion_.clear();
    caminoSolucion_.push_back(valor);    //introduzco primero nodo objetivo.

    aux=valor;
    encontrado=false;

    while (aux.padre_!=0)
    {
        itNodo=inspeccionados_.begin();

        //busco nodo en inspeccionados
        while ((itNodo!=inspeccionados_.end()) && (encontrado==false))
        {
                if (itNodo->estado_.id_==aux.padre_)

                {
                       encontrado=true;
                       aux=*itNodo;
                       //inspeccionados_.erase(itNodo); //borro este nodo de la lista.
                }

                else
                    itNodo++;
        }


         if (encontrado)
         {
             caminoSolucion_.push_back(aux);
             encontrado=false;

         }


    }

    //inspeccionados_.clear(); //lebero ya  toda la memoria del set que no voy a utilizar.


}




void GrafoIA_t::generarSucesores(set<NodeIA_t>::iterator &valor)
{

        for (int i=0; i < valor->LS_.size();i++)
        {

            if (!existeNodo(valor,valor->LS_[i].first)) //compruebo si existe numero de nodo en su camino hacia el nodo raiz
            {


                NodeIA_t nodoNuevo;

                nodoNuevo=grafo_[valor->LS_[i].first-1];
                nodoNuevo.costoCamino_=valor->costoCamino_+valor->LS_[i].second;
                nodoNuevo.costoCaminoMasHeuristico_=nodoNuevo.costoCamino_+nodoNuevo.valorHeuristico_;
                nodoNuevo.padrePuntero_=valor->current(); //pongo direncción del nodo padre.
                nodos_.insert(nodoNuevo);
                nodosGenerados_++;  //lo descuento de nodos generados

            }
        }
        valor->estudiado_=true; // marco nodo como estudiado.
    nodosInspeccionados_++; //lo sumo a nodos inspeccionados


}

void GrafoIA_t::generarSucesores(NodeIA_t &valor)
{

    for (int i=0; i < valor.LS_.size();i++)
    {
        if (!existeNodo(valor.LS_[i].first))
        {

            //si el nodo no existe en generados ni inspeccionados guardo al nodo sucesor como
            //predecesor y lo agreo a la lista de generados.

            set<NodeIA_t>::iterator itNodo;
            NodeIA_t nodoNuevo;

            nodoNuevo=grafo_[valor.LS_[i].first-1];
            nodoNuevo.costoCamino_=valor.costoCamino_+valor.LS_[i].second;
            nodoNuevo.costoCaminoMasHeuristico_=nodoNuevo.costoCamino_+nodoNuevo.valorHeuristico_;
            nodoNuevo.padre_=valor.estado_.id_;
            //nodoNuevo.padrePuntero_=
            generados_.insert(nodoNuevo);

        }
    }
}


bool GrafoIA_t::aEstrella(int nodoOrigen, int nodoDestino, bool version1)
{
 set<NodeIA_t>::iterator itNodo;
 NodeIA_t aux;

    if (numeroNodos_==0)  //REGRESO PORQUE NO SE HA CARGADO TODAVÍA NINGUN GRAFO.
        return false;

       limpiarArbol();

    //actualizo los valores origen y destino para visualizacion posterior.
       nodoOrigen_=nodoOrigen;
       nodoDestino_=nodoDestino;

    version1_=version1;

    if (version1_)//a estrealla version 1
    {
        aux=grafo_[nodoOrigen-1]; //nodo raiz
       aux.padrePuntero_=NULL;
       nodos_.insert(aux); //inserto nodo en la lista
       nodosGenerados_=1;
   do{

           itNodo=nodos_.begin(); //me coloco en el primer nodo.
           while (itNodo->estudiado_==true)
               itNodo++;   //me salto los nodos ya estudiados.


       if (itNodo->estado_.id_==nodoDestino)
             {
               itNodo->estudiado_=true;
               nodosInspeccionados_++; //lo sumo a nodos inspeccionados
               solucionEncontrada_=true;
               crearCaminoSolucion(itNodo);
              }

       else
           generarSucesores(itNodo);


     }  while (!solucionEncontrada_);


    }
    else // a estrella version 2
    {
        aux=grafo_[nodoOrigen-1]; //nodo raiz
        aux.padre_=0; //este cero indica que es el nodo raiz, para cuando haya que volver sobre sus pasos para mostrar el camino obtenido

           generados_.insert(aux); //inserto origen en generados.
   do{

           if (generados_.empty())
               return false;

       itNodo=generados_.begin();
       aux=*itNodo;
       generados_.erase(itNodo); //lo quito de generados para ahorrar memoria,

       inspeccionados_.insert(aux);  //lo agrego a inspeccionados.


       if (aux.estado_.id_==nodoDestino)
             {
               solucionEncontrada_=true;
               crearCaminoSolucion(aux);
               //generados_.clear(); //libero esta memoria, pusto que el trazo es ya solo con nodos que estarán en inspeccionados.

              }

       else
           generarSucesores(aux);


     }  while (!solucionEncontrada_);


    }

    return solucionEncontrada_;
}

void GrafoIA_t::limpiar()
{
    grafo_.clear();
    limpiarArbol(); //limpia lo que tenga que ver solo con la busqueda y creacion del arbol de busqueda.
    numeroNodos_=0;
    solucionEncontrada_=false;
    version1_=true;


    //para version 1
    nodosGenerados_=0;
    nodosInspeccionados_=0;
}

void GrafoIA_t::limpiarArbol()
{
    nodos_.clear();    
    caminoSolucion_.clear();
    solucionEncontrada_=false;
    version1_=true;
    nodoDestino_=0;
    nodoOrigen_=0;

    //para version 2
    generados_.clear();
    inspeccionados_.clear();
}
