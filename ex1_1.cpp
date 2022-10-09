/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
bool esPrimo(int numero);

using namespace std;
int N=0;

int main() {
    cout<<"ingresar N";
    std::cin >> N;
    cout<<N;
    float X[N];

    cout << "array size: " << sizeof X/sizeof X[0] << endl;
    int i = 0;
    while(i < sizeof X/sizeof X[0]){
        for(int j=1;j<50;j=j+1){
  if (esPrimo(j)) {
    //std::cout << "Es primo";
    X[i] = j;
    i=i+1;
  } else {
    //std::cout << "NO es primo";
  }
        }
    }
    for(int k=0;k<N;k=k+1){
    cout<< X[k]<<' ';
    }
}

bool esPrimo(int numero) {
  // Casos especiales
  if (numero == 0 || numero == 1 || numero == 4) return false;
  for (int x = 2; x < numero / 2; x++) {
    if (numero % x == 0) return false;
  }
  // Si no se pudo dividir por ninguno de los de arriba, sí es primo
  return true;
}