/*
 *  GRAFO.h - definicion de la clase GRAFO
 *
 *  Autor : Antonio Sedeno Noda, Sergio Alonso
 *  Curso 2012-2013
 */

#pragma once

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
namespace RMLIB {


const unsigned UERROR = 65000;
const int maxint = 1000000;

// definicion de un elemento de la lista de adyacencia

typedef struct
{
	unsigned j; // nodo
	int      c; // atributo para expresar el peso, la longitud, el coste, la inversin, etc...
} ElementoLista;

// definicion del tipo de una lista de adyacencia de un nodo

typedef vector<ElementoLista> LA_nodo;


class GRAFO
 {	
	unsigned            n;         // numero de NODOS //
	unsigned            m;         // numero de ARCOS //
	unsigned            dirigido;  //0 si el grafo es no dirigido y 1 si es dirigido
	vector<LA_nodo>     LS;        // Lista de adyacencia de los sucesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño//
	vector<LA_nodo>     LP;        // Lista de adyacencia de los predecesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño//
        vector<bool>        visitado;  //vector para almacenar informacion de visitado o no en caso de recorridos.
 public:
     GRAFO();
     GRAFO(char nombrefichero[], int &errorapertura);
     int actualizar(char nombrefichero[], int &errorapertura);
     unsigned Es_dirigido();  //devuelve 0 si el grafo es no dirigido y 1 si es dirigido
     void Info_Grafo();
     void Mostrar_Listas(int l);
     void ListaPredecesores();
     ~GRAFO();
     void liberar_memoria();
     void dfs(unsigned i, vector<bool> &visitado);
     void ComponentesConexas();
     void Dijkstra();
     void BellmanEndFord();
};

}

