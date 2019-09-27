#pragma once
#include "vector_t.hpp"
#include "matricula_t.hpp"
//
// Los tamaños de secuencia se daran en su verdadero tamaño, independiente mente de si empiezan desde cero o no, el algoritmo lo adaptara segun sea necesario
//
using namespace std;
using namespace RMLIB;

void f_ordenacion_insercion(vector_t<matricula_t> & secuencia,int tamano);
void f_ordenacion_seleccion(vector_t<matricula_t> &  secuencia,int tamano);
template <class T>
void f_ordenacion_seleccion(T * secuencia,int tamano);
void f_ordenacion_sacudida(vector_t<matricula_t> & secuencia,int tamano);
template <class T>
void f_ordenacion_sacudida(T * secuencia,int tamano);
void f_ordenacion_burbuja(vector_t<matricula_t> & secuencia,int tamano);
void mezcla(vector_t<matricula_t> &secuencia, vector_t<matricula_t> &v_aux, int inicio,int cen,int fin);
void quicksort(vector_t<matricula_t> & secuencia,int inicio,int fin);
void f_ordenacion_shellsort(vector_t<matricula_t> & secuencia,double alfa,int tamano);
template <class T>
void f_ordenacion_shellsort(T * secuencia,int tamano);



void insertar(vector_t<matricula_t> & secuencia, matricula_t x,int i)
{
    int j=0;
    while (x>secuencia[j]) 
    {
        j++;
        if (paso_a_paso) {
                        tecla();
                        cout <<"Posicion " << j << " : " << secuencia[j].get_matricula() << endl;
                        }
    }
    if (paso_a_paso) tecla();
    for (int k=i-1; k>=j; k--)
        secuencia[k+1]= secuencia[k];
    
    secuencia[j]= x;
}
void f_ordenacion_insercion(vector_t<matricula_t> & secuencia,int tamano)
{
        
   for (int i=1; i < tamano; i++) 
   {    
             
       if (paso_a_paso) {
       cout << " ----------------------------------------------------------" << endl;
       cout << "Comparando : " << secuencia[i].get_matricula() << " en posicion " << i << " con : " << endl << "Posicion " << 0 << " : " << secuencia[0].get_matricula() << endl;
           
       }
       insertar(secuencia,secuencia[i],i);             
       if (paso_a_paso) {
       cout << "Resultado despues de esta ordenacion . . ." << endl;
       secuencia.write(cout);       
       cout << "-----------------------------------------------------------" << endl;
       tecla();
       }
   }
    
   

}

void f_ordenacion_seleccion(vector_t<matricula_t> &  secuencia,int tamano)
{
  int minimo;
  matricula_t aux(false); //creo matricula vacia como borrador
  matricula_t::n_comparacion_=0; //inicializo la variable estatica a cero, puesto que voy a comenzar un metodo de ordenacion
  
  for (int i=0; i < (tamano-1); i++) 
   {    
            minimo = i;
            for (int j = i+1; j < tamano; j++)
            { 
                       if (paso_a_paso) {
                                cout << " ----------------------------------------------------------" << endl;
                                cout << "Comparando : " << secuencia[j].get_matricula() << " en posicion " << j << " con : " << endl << "Posicion " << minimo << " : " << secuencia[minimo].get_matricula() << endl;
           
                                   }
                if (secuencia[j] < secuencia[minimo])
                    minimo = j ;
            }
            
                aux = secuencia[minimo] ;
                secuencia[minimo] = secuencia[i] ;
                secuencia[i] = aux;
                
        if (paso_a_paso) {
       cout << "Resultado despues de esta ordenacion . . ." << endl;
       secuencia.write(cout);       
       cout << "-----------------------------------------------------------" << endl;
       tecla();
       }        
       
   }
         
}  

template <class T>
void f_ordenacion_seleccion(T * secuencia,int tamano)
{
    
}
void f_ordenacion_sacudida(vector_t<matricula_t> & secuencia,int tamano)
{
  matricula_t aux(false); //creo matricula vacia como borrador
  matricula_t::n_comparacion_=0; //inicializo la variable estatica a cero, puesto que voy a comenzar un metodo de ordenacion
  int inicio,fin;
  bool cambios;
  inicio=1;
  fin=tamano-1;
  cambios=true;
  
  while ((inicio < fin)  && (cambios==true))
  {
      cambios=false;
      //igual que metodo de la burguja
        for (int j = fin; j >= inicio; j--)
        {
                       if (paso_a_paso) {
                                cout << " ----------------------------------------------------------" << endl;
                                cout << "Comparando : " << secuencia[j].get_matricula() << " en posicion " << j << " con : " << endl << "Posicion " << j-1 << " : " << secuencia[j-1].get_matricula() << endl;
           
                                   }
            if (secuencia[j] < secuencia[j-1])
                { 
                    cambios=true;
                    aux = secuencia[j-1] ;
                    secuencia[j-1] = secuencia[j] ;
                    secuencia[j] = aux ;
                }
        }
        if (paso_a_paso) {
       cout << "Resultado despues de esta ordenacion . . ." << endl;
       secuencia.write(cout);       
       cout << "-----------------------------------------------------------" << endl;
       tecla();                  
            } 
                      
       //metodo de la piedra(burbuja pero de izquierda a derecha.
        for (int j = inicio; j < fin; j++)
        {
                       if (paso_a_paso) {
                                cout << " ----------------------------------------------------------" << endl;
                                cout << "Comparando : " << secuencia[j].get_matricula() << " en posicion " << j << " con : " << endl << "Posicion " << j+1 << " : " << secuencia[j+1].get_matricula() << endl;
           
                                   }
            if (secuencia[j] > secuencia[j+1])
                { 
                    cambios=true;
                    aux = secuencia[j] ;
                    secuencia[j] = secuencia[j+1] ;
                    secuencia[j+1] = aux ;
                }
        }
  
        if (paso_a_paso) {
       cout << "Resultado despues de esta ordenacion . . ." << endl;
       secuencia.write(cout);       
       cout << "-----------------------------------------------------------" << endl;
       tecla();                  
            } 
    
  inicio++;      
  fin--;
    
    }   
}
void f_ordenacion_burbuja(vector_t<matricula_t> & secuencia,int tamano)
{
  matricula_t aux(false); //creo matricula vacia como borrador
  matricula_t::n_comparacion_=0; //inicializo la variable estatica a cero, puesto que voy a comenzar un metodo de ordenacion
  bool cambios;
  int i;
  
  i=1;
  cambios=true;
  
   // for (int i = 1; i < tamano; i++)
     // { 
        
   while ((i<tamano) && (cambios==true))
    {           
       cambios=false;
        for (int j = tamano-1; j >= i; j--)
        {                
                       if (paso_a_paso) {
                                cout << " ----------------------------------------------------------" << endl;
                                cout << "Comparando : " << secuencia[j].get_matricula() << " en posicion " << j << " con : " << endl << "Posicion " << j-1 << " : " << secuencia[j-1].get_matricula() << endl;
           
                                   }
            if (secuencia[j] < secuencia[j-1])
                { 
                cambios=true;
                    aux = secuencia[j-1];
                    secuencia[j-1] = secuencia[j] ;
                    secuencia[j] = aux ;
                }
        }
        if (paso_a_paso) {
       cout << "Resultado despues de esta ordenacion . . ." << endl;
       secuencia.write(cout);       
       cout << "-----------------------------------------------------------" << endl;
       tecla();
       }
       i++;
     }
}
template <class T>
void f_ordenacion_sacudida(T * secuencia,int tamano)
{
}
void mezcla(vector_t<matricula_t> &secuencia, vector_t<matricula_t> &v_aux, int inicio,int cen,int fin)
{
    int i,j,k;
    i = inicio ; 
    j = cen + 1 ; 
    k = inicio ;

    while ((i <= cen) && (j <= fin))
        { 
            if (secuencia[i] < secuencia[j])
                {
                v_aux[k] = secuencia[i] ;
                i++ ;
                }
            else
                { 
                v_aux[k] = secuencia[j] ;
                j++ ;
                }
                k++ ;
        }
            if (i > cen)
                while (j <= fin)
                    {
                        v_aux[k] = secuencia[j] ;
                        j++ ; 
                        k++ ;
                    }
             else
                while (i <= cen)
                    {
                    v_aux[k] = secuencia[i] ;
                    i++ ; 
                    k++ ;
                    } ;
            for (int k = inicio; k <= fin; k++)
                    secuencia[k] = v_aux[k] ;
    
}
void mergesort(vector_t<matricula_t> &secuencia, vector_t<matricula_t> &v_aux, int inicio,int fin)
{
    int cen;
    
    if (inicio < fin)
        { 
            cen = (inicio + fin) / 2 ;
            mergesort(secuencia, v_aux, inicio, cen) ;
            mergesort(secuencia,v_aux, cen+1, fin) ;
            mezcla(secuencia, v_aux, inicio, cen, fin) ;
        } 
}
void f_ordenacion_mergesort(vector_t<matricula_t> &secuencia,int inicio,int fin)
{
    vector_t<matricula_t> v_aux;
    matricula_t::n_comparacion_=0; //inicializo la variable estatica a cero, puesto que voy a comenzar un metodo de ordenacion  
    v_aux=secuencia;
    fin--;
    mergesort(secuencia,v_aux,inicio,fin);
}     

void quicksort(vector_t<matricula_t> & secuencia,int inicio,int fin)
{
    matricula_t aux(false),pivote(false); //creo matricula vacia como borrador
     int i,f;
  
i = inicio; 
f= fin;
pivote= secuencia[(i+f)/2];
 
    do{ 
                    if (paso_a_paso) {
                                cout << " ----------------------------------------------------------" << endl;
                                cout << "Comparando : " << secuencia[i].get_matricula() << " en posicion " << i << " si es MENOR que Pivote : " << pivote.get_matricula() << endl;
           
                                   }

        while( (secuencia[i] < pivote) && (f <= fin ))
        { 
            i++;
                                if (paso_a_paso) {
                                cout << " ----------------------------------------------------------" << endl;
                                cout << "Comparando : " << secuencia[i].get_matricula() << " en posicion " << i << " si es MENOR que Pivote : " << pivote.get_matricula() << endl;
           
                                   }

        } 
        
                    if (paso_a_paso) {
                                cout << " ----------------------------------------------------------" << endl;
                                cout << "Comparando : " << secuencia[f].get_matricula() << " en posicion " << f << " si es MAYOR que Pivote : "  << pivote.get_matricula() << endl;           
                                   }
        while( (secuencia[f] > pivote) && (f > inicio) )
        { 
            f--;
       
                    if (paso_a_paso) {
                                cout << " ----------------------------------------------------------" << endl;
                                cout << "Comparando : " << secuencia[f].get_matricula() << " en posicion " << f << " si es MAYOR que Pivote : "  << pivote.get_matricula() << endl;           
                                   }            
        } 
 
        if( i <= f )
        { 
            aux = secuencia[i];
            secuencia[i] = secuencia[f]; 
            secuencia[f] = aux; 
            i++;  f--; 
        }
         
    }while( i <= f ); 

    if (paso_a_paso) {
       cout << "Resultado despues de esta ordenacion . . ." << endl;
       secuencia.write(cout);       
       cout << "-----------------------------------------------------------" << endl;
       tecla();
       }  
    if( inicio < f ) 
        quicksort(secuencia, inicio, f); 
    if( i < fin ) 
        quicksort(secuencia, i, fin);
    
}
void f_ordenacion_quicksort(vector_t<matricula_t> &secuencia,int inicio,int fin)
{
    matricula_t::n_comparacion_=0; //inicializo la variable estatica a cero, puesto que voy a comenzar un metodo de ordenacion
    fin--;
    quicksort(secuencia,inicio,fin);
}
   
void shellsort(vector_t<matricula_t> &secuencia,int delta, int tamano)
{
 matricula_t aux(false); //creo matricula vacia como borrador
 int i,j;
 
           for (i=delta; i < tamano; i++)
          {
                j = i;                
                aux = secuencia[i] ;
                
                while ((j >= delta) && (secuencia[j-delta] > aux))
                {
    if (paso_a_paso) {
                        cout << " ----------------------------------------------------------" << endl;
                        cout << "Comparando : " << secuencia[j-delta].get_matricula() << " en posicion " << j-delta << " si es MAYOR que : "  << aux.get_matricula() << endl;           
                    }            
                 
                    secuencia[j] = secuencia[j - delta];
                    j = j - delta;
                }
       
                secuencia[j] = aux;
          }
 
}
//en caso de que alfa sea cero, utilizo incremenos decrecientes /2
void f_ordenacion_shellsort(vector_t<matricula_t> & secuencia,double alfa,int tamano)
{     
matricula_t::n_comparacion_=0; //inicializo la variable estatica a cero, puesto que voy a comenzar un metodo de ordenacion
int delta;
    
delta = tamano;
 
    while(delta > 0)
        { 
                shellsort(secuencia, delta, tamano) ;
    if (paso_a_paso) {
       cout << "Resultado despues de esta ordenacion . . ." << endl;
       secuencia.write(cout);       
       cout << "-----------------------------------------------------------" << endl;
       tecla();
       }                 
                if (alfa==0) delta = delta/2;
                if (alfa>0) delta = delta * alfa;           

        }

}
template <class T>
void f_ordenacion_shellsort(T * secuencia,int tamano)
{
    
}