#include <QCoreApplication>
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <grafo.hpp>
#include <cstring>
#include <varias.hpp>

using namespace RMLIB;
//funcion prototipo
void menu(void);
void abrir_fichero(void);

//variables globales
int apertura=1; //parte de la base de que no hay fichero abiero
RMLIB::GRAFO migrafo;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc,argv);

    if (argc==2) migrafo.actualizar(argv[1],apertura);


    menu();

    return 0;
}


void abrir_fichero(void)
{
    char nombrefichero[80];

    borrar_pantalla();

    apertura=0;

        cout << "\n\nIntroduzca nombre de fichero con ruta completa: ";
        cin.clear();
        cin >> nombrefichero;
       migrafo.actualizar(nombrefichero,apertura);

       if (apertura==1)
    {
        cout << "Error,no se ha abierto fichero de grafos : " << nombrefichero << "\n\n Puede hacerlo desde el Menu\n" << endl;
        cout << "Presione ENTER para continuar" << endl;
        tecla();
    }

}
void menu(void)
{
    char opcion;

    borrar_pantalla();

   if (apertura==1)
    {
        cout << "Error,no se ha abierto fichero de grafos especificado : \n\n Puede hacerlo desde el Menu\n" << endl;
        cout << "Presione ENTER para continuar" ;
        tecla();
    }



do
{
    borrar_pantalla();
    cout << "\n\n Actividad III. Optimizacion. Caminos Mínimos\n\n";
    cout << "\n c. [c]argar grafo desde fichero";
    if (apertura==0)
    {
    cout << "\n i. Mostrar [i]nformacion basica del grafo";
    if (migrafo.Es_dirigido())
    {
           cout << "\n s. Mostar lista de [s]ucesores";
           cout << "\n p. Mostrar lista de [p]redecesores";
           cout << "\n d. Caminos Minimos [d]ijkstra";
           cout << "\n b. Caminos Minimos [b]ellman-For-Moore";
    }
    else {
            cout << "\n a. Mostrar lista de [a]dyacencias";
            cout << "\n o. Mostrar C[o]mponentes Conexas del grafo";
        }
    }
    cout << "\n q. Finalizar programa";


    cout << "Eliga un opcion : ";

    opcion=tecla();
    switch (opcion)
    {
        case 'c':
            abrir_fichero();
        case 'i':
            borrar_pantalla();
            migrafo.Info_Grafo();
            tecla();
            break;
        case 's':
            if (migrafo.Es_dirigido()!=1) break;
            migrafo.Mostrar_Listas(0);
            tecla();

            break;
        case 'p':
            if (migrafo.Es_dirigido()!=1) break;
            migrafo.Mostrar_Listas(1);
            tecla();
            break;
       case 'd':
            if (migrafo.Es_dirigido()!=1) break;
            migrafo.Dijkstra();
            tecla();
            tecla();
            break;
       case 'b':
            if (migrafo.Es_dirigido()!=1) break;
            migrafo.BellmanEndFord();
            tecla();
            tecla();
            break;
        case 'a':
            if (migrafo.Es_dirigido()!=0) break;
            migrafo.Mostrar_Listas(2);
            tecla();
            break;
        case 'o':
            if (migrafo.Es_dirigido()!=0) break;
            migrafo.ComponentesConexas();
            tecla();
            break;
    }

  }   while ((opcion!='q') && (opcion !='Q') );



}


