/*Desarrollar un programa que permita ingresar clientes (El programa debe permitirme
          ingresar cuantos clientes debo de ingresar), posterior a ello, ingresar el nornbre y sueldo 
          de cada cliente, luego, calcular si el cliente es apto para el crédito o no. Si el sueldo es 
          mayor a 2500 soles, es apto, de lo contrario no es apto. finalmente mostrar el nombre, 
          sueldo y si es apto o no. */

#include <iostream>
#include <list>
using namespace std;

int
main () 
{
  
list < string > aptos_name;
  
list < double >aptos_sueldo;
  
list < string > no_aptos_name;
  
list < double >no_aptos_sueldo;
  
int N_clientes;
  
string name = "";
  
float sueldo;
  
int i = 1;
  
 
cout << "Ingrese numero de clientes" << endl;
  
cin >> N_clientes;
  
 
for (i; i <= N_clientes; i++)
    
    {
      
cout << "Ingrese nombre " << endl;
      
cin >> name;
      
cout << "Ingrese sueldo " << endl;
      
cin >> sueldo;
      
 
if (sueldo >= 2500.0)
	{
	  
aptos_name.push_back (name);
	  
aptos_sueldo.push_back (sueldo);
	}
      
      else
	{
	  
no_aptos_name.push_back (name);
	  
no_aptos_sueldo.push_back (sueldo);
	
}
    
}
  
 
 
cout << "-----informacion-----" << endl;
  
cout << "Nombre" << "\t\t" << "sueldo" << endl;
  
while (!aptos_name.empty ())
    
    {
      
name = aptos_name.front ();
      
sueldo = aptos_sueldo.front ();
      
 
cout << name << "\t\t" << sueldo << "\t\t" << "apto" << endl;
      
aptos_name.pop_front ();
      
aptos_sueldo.pop_front ();
    
}
  
while (!no_aptos_name.empty ())
    
    {
      
name = no_aptos_name.front ();
      
sueldo = no_aptos_sueldo.front ();
      
 
cout << name << "\t\t" << sueldo << "\t\t" << "no apto" << endl;
      
no_aptos_name.pop_front ();
      
no_aptos_sueldo.pop_front ();
    
}
  
cout << "----------" << endl;
  
 
return 0;

}
