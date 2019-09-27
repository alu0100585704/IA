
#include <grafo.hpp>

namespace RMLIB {


GRAFO::GRAFO(char nombrefichero[], int &errorapertura)
{
   actualizar(nombrefichero,errorapertura);

}

GRAFO::GRAFO()
{

}

GRAFO::~GRAFO()
{
    liberar_memoria();
}

void GRAFO::liberar_memoria()
{
        int i;

if (dirigido) {
for (i=0;i<n;i++)  //sigo todos los nodos de las dos listas para irlas liberando sus respectivos vectores
        {
            LS[i].resize(0);
            LP[i].resize(0);

        }
        LS.resize(0);
        LP.resize(0);

}

if (!dirigido) {
for (i=0;i<n;i++)  //como es de adyacencias, solo libero el vector de sucesores que es donde se almacena los adyacentes.
        LS[i].resize(0);
        LS.resize(0);

}


}

 int GRAFO::actualizar (char nombrefichero[], int &errorapertura)
 {
    int i, j, contador;
    ElementoLista dummy;
    ifstream fichero_grafo;

    liberar_memoria(); //por si acaso ya se hab�a abierto alg�n fichero, libero las posibles bloques de memoria reservados.

        fichero_grafo.open(nombrefichero);
    if (fichero_grafo.is_open())
    {
        fichero_grafo >> n >> m >> dirigido;
        LS.resize(n);    //LISTA DE SUCESORES en base al numero de nodos. Esta lista ser� la de adyacencia en caso de grafos no dirigidos.
                visitado.resize(n);//vector de visitados igual al numero de nodos.

    if (dirigido) LP.resize(n);

if (dirigido)
    {
        //Comenzamos con la lectura de los sucesores, sabemos que hay m  aristas o arcos.
        for (contador=0;contador < m; contador++)
        {
            fichero_grafo >> i >> j ; //leo nodo i y su  j correspondiente.
            dummy.j=j-1; //puesto que este despues indicar� en nodo dentro del vector que comienzan desde cero
                        fichero_grafo >> dummy.c; //lee coste de este arco
                        LS[i-1].push_back(dummy);
        }

                   ListaPredecesores(); //creo la lista de predecesores a partir de la de sucesores.

    }
if (!dirigido)
    {
                //Comenzamos con la lectura de los sucesores, sabemos que hay m  aristas o arcos.
        for (contador=0;contador < m; contador++)
        {
            fichero_grafo >> i >> j; //leo nodo i y su  j correspondiente.
            dummy.j=j-1; //puesto que este despues indicar� en nodo dentro del vector que comienzan desde cero
                        fichero_grafo >> dummy.c; //lee coste de esta arista.
                        LS[i-1].push_back(dummy);

            if (i!=j)
            {
                        dummy.j=i-1;
                        LS[j-1].push_back(dummy);
            }
        }

    }

               fichero_grafo.close();
                errorapertura=0;
    }

            else errorapertura=1;
return errorapertura;

 }
     unsigned GRAFO::Es_dirigido()  //devuelve 0 si el grafo es no dirigido y 1 si es dirigido
     {
         return dirigido;
     }
     void GRAFO::Info_Grafo()
     {

         cout << "\n\nGrafo con  " << n << " NODOS | ";
         if (Es_dirigido())  cout << " Dirigido | " << m << " ARCOS | ";
         else cout << "NO Dirigido  | " << m << " ARISTAS |";


     }

     void GRAFO::ListaPredecesores()
     {
        ElementoLista dummy;

        LP.resize(n);//si es dirigido tambi�n prepara la lista de predecesores.
            for (int i=0;i < n; i++)
                {
                    for (int contador_nodo=0; contador_nodo < LS[i].size(); contador_nodo++)
                    {
                        dummy.j=i;
                        dummy.c=LS[i][contador_nodo].c;
                        LP[LS[i][contador_nodo].j].push_back(dummy);
                    }


        }

     }

      void GRAFO::Mostrar_Listas(int l)
     {
         int j,i;

         switch (l)
         {
             case 0:   //para mostrar lista de sucesores.
                 cout << "\nLista de Nodos o Vertices Sucesores : \n";
                 for (i=0; i < n; i++)
                 {

                     cout << "\n[" << i+1 << "] : ";
                     if (LS[i].size()==0) cout << "Sin Sucesores";
                     for (j=0; j < LS[i].size(); j++)
                         cout << (LS[i][j].j)+1 << " : " << LS[i][j].c << " | ";

                 }
                 break;

             case 1:
            cout << "\nLista de Nodos o Vertices Predecesores: \n";
                 for (i=0; i < n; i++)
                 {

                     cout << "\n[" << i+1 << "] : ";
                     if (LP[i].size()==0) cout << "Sin Predecesores";
                     for (j=0; j < LP[i].size(); j++)
                         cout << (LP[i][j].j)+1 << " : " << LP[i][j].c << " | ";

                 }
                 break;
             case 2:
                 cout << "\nLista de Nodos o Vertices Adyacentes : \n";
                 for (i=0; i < n; i++)
                 {
                     cout << "\n[" << i+1 << "] : ";
                    if (LS[i].size()==0)  cout << "Sin Adyacencias";
                     for (j=0; j < LS[i].size(); j++)
                             cout << (LS[i][j].j)+1 << " : " << LS[i][j].c << " | ";

                 }

                 break;
         }



     }

void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{
visitado[i] = true;
cout << i+1 << ", ";
for (unsigned j=0;j<LS[i].size();j++)
if (visitado[LS[i][j].j] == false)
dfs(LS[i][j].j, visitado);
}


void GRAFO::ComponentesConexas()
{
    int i,contador=0;

    for (i=0; i < n; i++)
        visitado[i]=false;

    cout << "\nNodos de los componentes conexas : \n" << endl;
    for (i=0; i < n; i++)
        if (visitado[i]==false)
        {
            contador++;
            cout << "Componente conexa " << contador << " : {";
            dfs(i,visitado);
            cout << "}" << endl;
        }

    if (contador>1) cout << "\nEl grafo NO es conexo" << endl;
    else cout << "\nEl grafo es conexo" << endl;



}

void MostrarCamino(unsigned s, unsigned i, vector<unsigned> & pred)
{
//if ((i != s) && (pred[i]!=UERROR))
    if (i != s)
{
   MostrarCamino(s,pred[i],pred);
    cout << pred[i]+1 << " -> ";
}

}

void GRAFO::Dijkstra()
{
vector<bool> PermanentementeEtiquetado;
vector<int> d;
vector<unsigned> pred;
int min;
unsigned s, candidato;
//Inicialmente no hay ningun nodo permanentemente etiquetado
PermanentementeEtiquetado.resize(n,false);
//Inicialmente todas las etiquetas distancias son infinito
d.resize(n,maxint);
//Inicialmente el pred es null
pred.resize(n,UERROR);
//Solicitamos al usuario nodo origen
cout << endl;
cout << "Caminos minimos: Dijkstra" << endl;
cout << "Nodo de partida? [1-"<< n << "]: ";
cin >> (unsigned &) s;
//La etiqueta distancia del nodo origen es 0, y es su propio pred
d[--s]=0; pred[s]=s;
candidato=s;

do
{
min=maxint;

 for (int i=0; i < n; i++)
  if ((PermanentementeEtiquetado[i]==false) && (d[i]<min))
    {
                min=d[i];
                candidato=i;

     }
    PermanentementeEtiquetado[candidato]=true;

                     for (int j=0; j < LS[candidato].size(); j++)
                        if ((PermanentementeEtiquetado[LS[candidato][j].j]==false) && (d[LS[candidato][j].j] > (d[candidato] + LS[candidato][j].c))) //con este if, no encontrarᡬa mejor ruta si hay costes negativos pero nunca quedaratrapado en un ciclo negativo.
                        //    if (d[LS[candidato][j].j] > (d[candidato] + LS[candidato][j].c)) //con este if, puedo encontrar la ruta optima con arcos negativos,pero puede quedar atrapado en ciclo negativo.
                            {
                            d[LS[candidato][j].j]=d[candidato] + LS[candidato][j].c;
                            pred[LS[candidato][j].j]=candidato;
                            }
 } while (min < maxint);
                     /*
- Buscamos un nodo candidato a ser permanentemente etiquedado: aquel de entre los no permanentemente etiquetados con menor etiqueta distancia no infinita.
- Si existe ese candidato, lo etiquetamos permanentemente y usamos los arcos de la lista de sucesores para buscar atajos.
- Esto lo hacemos mientras haya candidatos
*/

 //En esta parte del c󤩧o, mostramos los caminos mmos, si los hay

cout << "Soluciones:" << endl;
for (int i=0; i < n; i++)
{
    if (d[i]==maxint) cout << "No Hay camino mmo dedes el nodo " << s+1 << " al nodo " << i+ 1 << endl;
    else
    {
        if (s!=i) {
                    cout << "El camino desde el nodo " << s+1 << " al nodo " << i+1 << " es : ";
                    MostrarCamino(s,i, pred);
                    cout << " -> " << i+1;
                     cout << " de longitud " << d[i] << endl;
                    }
    }
}

}

void GRAFO::BellmanEndFord()
{

vector<int> d;
vector<unsigned> pred;
unsigned s, numeromejoras = 0;
bool mejora;
//Idem que en el algoritmo de Dijkstra
d.resize(n,maxint);
pred.resize(n,UERROR);
cout << endl;
cout << "Caminos minimos: Bellman ֠End - Moore" << endl;
cout << "Nodo de partida? [1-"<< n << "]: ";
cin >> (unsigned &) s;
d[--s]=0;
pred[s]=s;
do
{
// recorremos todos los arcos, y para cada (i, j), buscamos si d[j] > d[i] + cij, y actualizamos d y pred
//si al menos en una ocasion ha mejorado una etiqueta distancia, no hemos terminado; contabilizamos los ciclos en los que ha habido mejoras
 mejora=false;

 for (int i=0; i < n; i++)
       for (int j=0; j < LS[i].size(); j++)
            if (d[LS[i][j].j] > (d[i] + LS[i][j].c))
                            {
                            d[LS[i][j].j]=d[i] + LS[i][j].c;
                            pred[LS[i][j].j]=i;
                            mejora=true;
                            }

if (mejora==true) numeromejoras++;


} while ((numeromejoras < n) && (mejora == true));
//para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos realizado n+1 veces la relajacion con mejora; si mejora es false, pues tenemos solucion
//Mostramos los caminos mmos que se puedan haber encontrado, o advertimos de la existencia de un ciclo de coste negativo.

//En esta parte del c󤩧o, mostramos los caminos mmos, si los hay
if (mejora==false)
{
cout << "Soluciones:" << endl;
for (int i=0; i < n; i++)
{

    if (d[i]==maxint) cout << "No Hay camino mmo dedes el nodo " << s+1 << " al nodo " << i+ 1 << endl;
    else
    {
        if (s!=i){
                    cout << "El camino desde el nodo " << s+1 << " al nodo " << i+1 << " es : ";
                    MostrarCamino(s,i, pred);
                    cout << " -> " << i+1;
                     cout << " de longitud " << d[i] << endl;
                    }
    }
}
} else {
    cout << "\nNo hay soluciones factibles al detectarse un ciclo de coste negativo en el grafo\n";

}
}

}
