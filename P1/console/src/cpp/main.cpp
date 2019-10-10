#include <QCoreApplication>
#include <QDebug>
#include <GrafoIA_t.hpp>
#include <EstadoIA_t.hpp>

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <varias.hpp>

using namespace RMLIB;
//funcion prototipo
void menu(void);
void cargar_grafo(void);
void cargar_heuristica(void);
GrafoIA_t migrafo;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc,argv);

    menu();

    return 0;
}


void cargar_grafo(void)
{    

    char nombrefichero[80];

    borrar_pantalla();


        cout << "\n\nIntroduzca nombre de fichero con ruta completa: ";
        cin.clear();
        cin >> nombrefichero;
     if (!migrafo.actualizar(nombrefichero))
        {

        cout << "Error,no se ha abierto fichero de grafos : " << nombrefichero << "\n\n Puede hacerlo desde el Menu\n" << endl;
        cout << "Presione ENTER para continuar" << endl;
        tecla();tecla();
       }

}
void cargar_heuristica(void)
{

    char nombrefichero[80];

    borrar_pantalla();


        cout << "\n\nIntroduzca nombre de fichero con ruta completa: ";
        cin.clear();
        cin >> nombrefichero;
     if (!migrafo.aplicarHeuristica(nombrefichero))
        {

        cout << "Error,no se ha abierto fichero de heuristica : " << nombrefichero << "\n\n Puede hacerlo desde el Menu\n" << endl;
        cout << "Presione ENTER para continuar" << endl;
        tecla();tecla();
       }

}

void menu(void)

{
    char opcion;

    borrar_pantalla();

   do
{
    borrar_pantalla();
    cout << "\n\n Practica 1. Inteligencia Artificial \n\n";
    cout << "\n c. [c]argar grafo desde fichero";
    cout << "\n h. [h]argar heuristica del grafo desde fichero";
    cout << "\n m. [m]mostrar fichero cargado";
    cout << "\n b. [b]Buscar solucion opotima";
    cout << "\n q. Finalizar programa";


    cout << "Eliga un opcion : ";

    opcion=tecla();

    switch (opcion)
    {
        case 'c':
            cargar_grafo();
            tecla();
            tecla();

        break;
    case 'm':
        if (!migrafo.empy())
             cout << migrafo;
        else {
            cout << "Grafo no cargado o vacío" << endl;
        }
         tecla();
         tecla();

    break;

    case 'h':
        if (!migrafo.empy())
                 cargar_heuristica();

            else
            cout << "Grafo no cargado o vacío" << endl;

         tecla();
         tecla();

    break;
    case 'b':

        if (migrafo.aEstrella(1,5))
          {
            migrafo.mostrarCaminoSolucion(cout);
            cout << "hola";
        }
        else {
            cout << endl<< "Solucion no Encontrada" << endl;
        }
        tecla();
         tecla();

    break;

    }

  }   while ((opcion!='q') && (opcion !='Q') );



}



