#pragma once
//
// Los tamaños de secuencia se daran en su verdadero tamaño, independiente mente de si empiezan desde cero o no, el algoritmo lo adaptara segun sea necesario
//
using namespace std;
//
 // fichero con funciones varias
//

//funciones  prototipo
unsigned char tecla(void);
void borrar_pantalla(void);


unsigned char tecla(void)
{
	  char c;
	  c=cin.get();

	  if (c !='\n')  while (getchar() != '\n');

	  return c;

}
void borrar_pantalla(void)
{

#ifdef _WIN32
	system("cls");
#endif

#ifdef __linux__
	system("clear");
#endif

}
//
//Algoritmos de ordenacion
//

