/*Desarrollar un programa en C++ que perrnita ingresar y almacenar el código, el nombre, 
          la nota, la nota2 y la nota3 de todos los estudiantes delón de clase.
   Posterior a ello, el programa debe mostrar un menú con las siguientes opciones:
   (1)    Ingresar datos
   (2)    Eliminar datos (Si elimina a un estudiante, se debe eliminar la notal, nota2 y nota3),
   (3)    Insertar datos de un estudiante nuevo (Al final)
   (4)    Promedio de notas de todos los estudiantes de un salón
   (5)    Número de estudiantes aprobados
   (6)    Número de estudiantes desaprobados
   (7)    Mostrar 
          La relación de estudiantes con el prornedio respectivo
   b.     La relación de estudiantes que aprobaron
   c.     La relación de estudiantes que desaprobaron
   d.     Estudiante con mejor promedio */

#include <iostream>

using namespace::std;

struct nodo{
	int codigo;
	char nombre[30];
	int nota1,nota2,nota3;
	nodo* siguiente;
} *primero, *ultimo;

void insertarNodo();
void eliminarNodo();
void desplegarLista();
void promedio();
void AproDesaprovado(int);

int main(){

	int opcion_menu = 0;

	do
	{
		cout << "\n|---------------------------------------|";
		cout << "\n|          ° LISTA DE ALUMNOS °         |";
		cout << "\n|-------------------|-------------------|";
		cout << "\n| 1. Insertar       | 2. Eliminar       |";
		cout << "\n| 3. Insertar Final | 4. Promedio       |";
		cout << "\n| 5. Aprobados      | 6. Desaprobados   |";
		cout << "\n| 7. Mostrar        | 8. Salir          |";
		cout << "\n|-------------------|-------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			cout << "\n\n INSERTA DATOS DEL ALUMNO \n\n";
			insertarNodo();
			break;
		case 2:
			cout << "\n\n ELIMINAR ALUMNO \n\n";
			eliminarNodo();
			break;
		case 3:
			cout << "\n\n INSERTAR ALUMNO AL FINAL \n\n";
			insertarNodo();

			break;
		case 4:
			cout << "\n\n PROMEDIO DE NOTAS DE TODOS LOS ALUMNOS\n";
            promedio();
			break;
		case 5:
			cout << "\n\n ALUMNOS APROBADOS \n";
            AproDesaprovado(1);
			break;
		case 6:
			cout << "\n\n ALUMNOS DESAPROBADOS\n";
			AproDesaprovado(0);
			break;
        case 7:
			cout << "\n\n MOSTRAR DATOS GENERALES.\n";
			desplegarLista();
			break;
        case 8:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 8);


	return 0;
}

void insertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el codigo: ";
	cin >> nuevo->codigo;
	cout << " Ingrese el nombre: ";
	cin >> nuevo->nombre;
	cout << " Ingrese la nota 1: ";
	cin >> nuevo->nota1;
	cout << " Ingrese la nota 2: ";
	cin >> nuevo->nota2;
	cout << " Ingrese la nota 3: ";
	cin >> nuevo->nota3;

	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << "\n Datos Ingresados\n\n";
}


void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el codigo del alumno a Buscar para Eliminar: ";
	cin >> nodoBuscado;
	if(primero != NULL){

		while(actual != NULL && encontrado != true){

			if(actual->codigo == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado\n\n";

				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}

				cout << "\n ALUMNO ELIMINADO pi pi pi ....\n";

				encontrado = true;
			}

			anterior = actual;
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Alumno NO Encontrado\n";
		}
	}else{
		cout  << "\n Lista de alumnos Vacia\n";
	}
}

void promedio(){
    nodo* actual = new nodo();
    actual=primero;
    double prom,sum1=0,sum2=0,sum3=0,total=0;
    if(primero!=NULL){
        while(actual!=NULL){
            sum1=sum1+actual->nota1;
            sum2=sum2+actual->nota2;
            sum3=sum3+actual->nota3;
            actual = actual->siguiente;
            total=total+1;
        }
        prom=(sum1+sum2+sum3)/(3*total);
        cout<<"--------------------------------------------------\n";
        cout<<"        ES: "<<prom<<endl;
        cout<<"--------------------------------------------------\n\n";
    }else{
        cout<<"No hay datos de alumnos\n";
    }
}


void AproDesaprovado(int valor){
    nodo* actual=new nodo();
    actual=primero;
    double prom,sum1=0,sum2=0,sum3=0,total=0;
    int aprobado=0;

    if(primero!=NULL){
        while(actual!=NULL){
            sum1=actual->nota1;
            sum2=actual->nota2;
            sum3=actual->nota3;
            prom=(sum1+sum2+sum3)/3;
            if(prom>10){
                aprobado=aprobado+1;
            }
            actual=actual->siguiente;
            total=total+1;
        }
        if(valor==1){
            cout<<"--------------------------------------------------\n";
            cout<<"   APROBADOS: "<<aprobado<<endl;
            cout<<"--------------------------------------------------\n";
        }else{
            cout<<"--------------------------------------------------\n";
            cout<<"   DESAPROBADOS: "<<total-aprobado<<endl;
            cout<<"--------------------------------------------------\n";
        }
    }else{
         cout<<"No hay datos de alumnos\n";
    }
}

void desplegarLista(){
	nodo* actual = new nodo();
	nodo* actual1 = new nodo();
	nodo* actual2 = new nodo();
	actual = primero;
	double Maxprom,sum1=0,sum2=0,sum3=0,total=0;
	double suma,sumb,sumc,prom;
    int aprobado=0;
	if(primero != NULL){
         cout<<"Alumnos de la Clase"<<endl;
                cout<<"\n";
                cout<<"      CODIGO      |";
                cout<<"      NOMBRE      |";
                cout<<"      NOTA1       |";
                cout<<"      NOTA2       |";
                cout<<"      NOTA3       |";
                cout<<"     PROMEDIO     |\n";
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
		while(actual != NULL){
            sum1=actual->nota1;
            sum2=actual->nota2;
            sum3=actual->nota3;
            prom=(sum1+sum2+sum3)/3;
			cout<< "       " << actual->codigo <<"    ";
			cout<< "           " << actual->nombre <<"     ";
			cout<< "            " << sum1 <<"      ";
			cout<< "            " << sum2 <<"      ";
			cout<< "            " << sum3 <<"      ";
            cout<< "            " << prom <<"      \n";
			actual = actual->siguiente;
		}
		    actual = primero;
		    cout<<"-------------------------------------------------------------------------------------------------------------------\n";
            cout<<"|    ALUMNOS QUE APROBARON        |\n";
         while(actual != NULL){
            sum1=actual->nota1;
            sum2=actual->nota2;
            sum3=actual->nota3;
            prom=(sum1+sum2+sum3)/3;
            if(prom>10){
                cout<< "      " << actual->nombre <<"    "<<endl;
            }
			actual = actual->siguiente;
		}
		    actual = primero;
		    cout<<"-------------------------------------------------------------------------------------------------------------------\n";
            cout<<"|    ALUMNOS QUE DESAPROBARON        |\n";
         while(actual != NULL){
            sum1=actual->nota1;
            sum2=actual->nota2;
            sum3=actual->nota3;
            prom=(sum1+sum2+sum3)/3;
            if(prom<=10){
                cout<< "      " << actual->nombre <<"    "<<endl;
            }
			actual = actual->siguiente;
		}
		 /*   actual1 = primero;
		    actual2 = primero->siguiente;
		    cout<<"-------------------------------------------------------------------------------------------------------------------\n";
            cout<<"|    ALUMNO CON MEJOR PROMEDIO        |\n";
         while(actual2 != NULL){
            sum1=actual1->nota1;
            sum2=actual1->nota2;
            sum3=actual1->nota3;
            Maxprom=(sum1+sum2+sum3)/3;

            suma=actual2->nota1;
            sumb=actual2->nota2;
            sumc=actual2->nota3;
            prom=(suma+sumb+sumc)/3;

            if(Maxprom>prom){
            actual1=actual2;
            sum1=actual1->nota1;
            sum2=actual1->nota2;
            sum3=actual1->nota3;
            Maxprom=(sum1+sum2+sum3)/3;
            cout<<"  "<<actual1->nombre<<"  |";
            cout<<"   "<<Maxprom<<"  \n";
            }
            actual2=actual2->siguiente;

		}

*/
            cout<<"-------------------------------------------------------------------------------------------------------------------\n\n";

	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}





}
