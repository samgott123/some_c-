/*Llenar una matriz de forma aleatoria y buscar un numero dentro de la matriz, si el
          numero existe lo vamos a mostrar tanto el numero como la ubicación del mismo, sino 
          decimos que no está dentro de la matriz.
*/

#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
int m;
int
main ()
{
  float c;
  int num, find;
  int N;
  cout << "ingrese tamaC1o de matriz cuadrada" << endl;
  cin >> N;
  int X[N][N];
  srand (time (NULL));
  // for(c = 1; c < 10; c = c+1)
  //{
  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
	{
	  num = 1 + int (rand () % (20 - 1));
	  X[i][j] = num;
    }}

//}    
  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
	{

	  cout << X[i][j] << "  ";
	}
      cout << endl;


    }

  cout << "Ingrese el numero a buscar" << endl;
  cin >> find;

  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
	{
	  if (find == X[i][j])
	    {
	      cout << "elmento encontrado" << endl;
	      cout << "posicion (i,j) =" << "(" << i << "," << j << ")" <<
		endl;
	      m = 1;
	    }

	}

    }

  if (m != 1)
    {
      cout << "no se encontro valor";
      cout << endl;
    }


  return 0;
}
