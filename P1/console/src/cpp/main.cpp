#include <QCoreApplication>
#include <QDebug>
#include <GrafoIA_t.hpp>
#include <EstadoIA_t.hpp>

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <varias.hpp>

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
        tecla();
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
    int nodoOrigen,nodoDestino;

    borrar_pantalla();

   do
{
    borrar_pantalla();
    cout << "\n\n Practica 1. Inteligencia Artificial \n\n";
    cout << "\n [c]argar grafo desde fichero";
    cout << "\n [h]argar heuristica del grafo desde fichero";
    cout << "\n [m]ostrar fichero cargado";
    cout << "\n [a]A* version 1";
    cout << "\n [A]A* version 2";
    cout << "\n [F]inalizar programa";


    cout << "Eliga un opcion : ";

    opcion=tecla();

    switch (opcion)
    {
        case 'c':
            cargar_grafo();
            tecla();            

        break;
    case 'm':
        if (!migrafo.empy())
             cout << migrafo;
        else {
            cout << "Grafo no cargado o vacío" << endl;
        }
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
         //version original
    /*case 'a':

        borrar_pantalla();
        cout << "Version 1 algoritmo: Un solo conjunto " << endl;
        cout << "\n\nIntroduzca Número de nodo/estado  origen: ";
        cin.clear();
        cin >> nodoOrigen;

        cout << "\n\nIntroduzca Número de nodo/estado  destino (deberia coincidir con valor cero en su funcion heuristica): ";
        cin.clear();
        cin >> nodoDestino;


        if (migrafo.aEstrella(nodoOrigen,nodoDestino,true))
          {
            migrafo.mostrarCaminoSolucion(cout);
            cout << endl << "Volcando resultados a resultado.txt del directorio actual. . ."<< endl;
            ofstream fichero_resultados;
            fichero_resultados.open("resuldato.txt",std::ios_base::app);
            migrafo.mostrarCaminoSolucion(fichero_resultados);
            fichero_resultados.close();
            cout << "Terminado";
        }
        else {
            cout << endl<< "Solucion no Encontrada" << endl;
        }
        tecla();
        tecla();

        break;*/

         //version modificada para la práctica.
    case 'a':
srand(time(NULL)); //inicializo semilla
            borrar_pantalla();
            cout << "Version 1 algoritmo: Un solo conjunto " << endl;
            cout << "\n\nIntroduzca Número de nodo/estado  origen: ";
            cin.clear();
            cin >> nodoOrigen;

            cout << "\n\nIntroduzca Número de nodo/estado  destino (deberia coincidir con valor cero en su funcion heuristica): ";
            cin.clear();
            cin >> nodoDestino;

    for (int i=0; i<10; i++) //para repetir la prueba 10 veces
    {
            if (migrafo.aEstrella_mod(nodoOrigen,nodoDestino))
              {
                migrafo.mostrarCaminoSolucion(cout);
                cout << endl << "Volcando resultados a resultado.txt del directorio actual. . ."<< endl;
                ofstream fichero_resultados;
                fichero_resultados.open("resuldato.txt",std::ios_base::app);
                migrafo.mostrarCaminoSolucion(fichero_resultados);
                fichero_resultados.close();
                cout << "Terminado";
            }
            else {
                ofstream fichero_resultados;
                fichero_resultados.open("resuldato.txt",std::ios_base::app);
                fichero_resultados  << endl << endl << "Solucion no Encontrada" << endl << endl;
                fichero_resultados.close();

                cout << endl<< "Solucion no Encontrada" << endl;
            }
            tecla();
            tecla();
       }
            break;

    case 'A':

        borrar_pantalla();
        cout << "Version 2 algoritmo: Dos conjuntos " << endl;
        cout << "\n\nIntroduzca Número de nodo/estado  origen: ";
        cin.clear();
        cin >> nodoOrigen;

        cout << "\n\nIntroduzca Número de nodo/estado  destino (deberia coincidir con valor cero en su funcion heuristica): ";
        cin.clear();
        cin >> nodoDestino;


        if (migrafo.aEstrella(nodoOrigen,nodoDestino,false))
          {
            migrafo.mostrarCaminoSolucion(cout);
            cout << endl << "Volcando resultados a resultado.txt del directorio actual. . ."<< endl;
            ofstream fichero_resultados;
            fichero_resultados.open("resuldato.txt",std::ios_base::app);
            migrafo.mostrarCaminoSolucion(fichero_resultados);
            fichero_resultados.close();
            cout << "Terminado";
        }
        else {
            cout << endl<< "Solucion no Encontrada" << endl;
        }
        tecla();
        tecla();

    break;


    }

  }   while ((opcion!='f') && (opcion !='F') );



}



