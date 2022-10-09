/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

Desarrollar un programa que sobre un arreglo de 20 elementos debe calcular lo siguiente: 
    o) Generar notas aleatorias entre 5 y 20
    b) Mostrar los resultados numero de alumno. nota y al costado de las notas aprobatorias el símbolo 
       Nro   Nota
       1     10
       2     14 
    c) Determinar el porcentaje de aprobados y desaprobados considerando corno nota mínima 
       aprobatoria 13 y mostrar sus resultados al final de la ejecución del programa
*******************************************************************************/
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
int notas[20];
int main()
{
    float c;
    int num , i;
    srand(time(NULL));
    i=0;
    for(c = 5; c < 20; c = c+0.75)
    {
        num = 1 + int(rand() % (20 - 1));
        //cout << num<< " ";
        notas[i]=num;
        i = i +1;
    }
    cout<<"Nro"<<"\t"<<"nota"<<endl;
    for(int j =0;j<20;j++){
        if(notas[j]>=13){
            cout<<j+1<<"\t"<<notas[j]<<"(*)"<<endl;
        }
        else{
            cout<<j+1<<"\t"<<notas[j]<<endl;
        }
    }
    int aprobados=0 ;
    for(int i =0;i<20;i=i+1){
    if(notas[i]>=13){
            aprobados = aprobados +1;
        }
    }
    cout<<aprobados<<endl;
    float pctaprob = 0;
    pctaprob = (aprobados/20.0)*100;
    cout<<"porcentaje de aprobados"<<pctaprob<<endl;
    cout<<"porcentaje de desaprobados"<<100.0-pctaprob<<endl;
    return 0;
}
