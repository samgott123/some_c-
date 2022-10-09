/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

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