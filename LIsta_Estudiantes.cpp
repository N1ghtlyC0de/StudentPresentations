/*
Ingreso de estudiantes por Apellido Nombre 
-- El programa los ordena
-- El programa genera un reporte de los estudiantes   
   Ordenados Alfabeticamente
-- Y genera un Listado en orden de presentacion temas
-- el programa maneja una lista con doble apuntador o enlace Derecha e Izquierda
*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct lista
{ 
	string nombre;
	lista *ap_der; // apuntador Lista derecha
	lista *ap_izq; // apuntador lista izquierda
} *cola, *cab, *nuevo, *nuevo2, *cab2, *cola2;

void menu(void);
void ingresar(void);
void mostrar1(void);
void mostrar2(void);
void mostrar_temas(void);
void limpiar_lista(void);
void espera();

main()
{
	menu();
}

void menu(void)
{
	int y, opc;
	opc = 9;
	while ( opc != 0)
	{
		system("cls");
		cout<<"\n 1 Ingresar Nombres Estudiantes";
		cout<<"\n 2 Listar Estudiantes Orden ascendente  "; 
		cout<<"\n 3 Listar Estudiantes Orden descendente  ";
		cout<<"\n 4 Listar Por Orden Temas  "; 
		cout<<"\n ................          "; 
		cout<<"\n 5 Limpiar <Borrar> Lista  "; 
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar();
				break;
			case 2:
				mostrar1();	  //ascendente
				break;
			case 3:
				mostrar2();   //descendente
				break;
			case 4:
				mostrar_temas();
				break;
			case 5:
				limpiar_lista();
				break;
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
	}
}

void ingresar(void)
{
	// Ingresa estudiantes y los ordena 
	// en Una Lista de doble apuntador
	lista *bus1, *bus2;
	int sw;
    
	
	// PRIMERA PARTE	
	nuevo = new(lista); // creamos nuevo Nodo
	fflush(stdin); // funsion para liberar la memoria 
	
	cout<<"\n"<<"Digite el Apellidos y Nombres Estudiantes : ";
	getline(cin,nuevo->nombre);
	nuevo->ap_der = NULL;
	nuevo->ap_izq = NULL;
	// las variables apuntador las iniciamos en NULL ... 
	// y luego verificamos como insertamos el Nodo en la lista 
	fflush(stdin);
	
	//VERIFICAR SI HAY UNA LISTA CREADA
	if (!cab)
	{   // si la lista no esta creada ... la creamos
		// y asignamos los punteros a nuevo Nodo
		cab   = new(lista);
		cola  = new(lista);
		cab2  = new(lista);
		cola2 = new(lista);
		cab  = nuevo;  cab2  = nuevo;
		cola = nuevo;  cola2 = nuevo;
		cout <<"\n"<<"se creo la lista";
	}
    else
	{ 
	//  insertamos al inicio de la lista CAB "cabecera"
	    if ( nuevo->nombre <= cab->nombre )	
	    {
	    	if ( nuevo->nombre == cab->nombre )
	    	{	cout <<"Nombre ya existe en la Lista ";
			}
			else
			{	// insertamos el Nuevo Nodo
				// al inicio de la Lista 
	    		nuevo->ap_der = cab;
	    		cola2->ap_izq = nuevo;
	    		cab   = nuevo;
	    		cola2 = nuevo;
			}
		}
		else
		{
			// verificamos ahora si el nuevo Nodo 
			// lo insertamos al final de la Lista
			if ( nuevo->nombre >= cola->nombre )
			{
                if (nuevo->nombre == cola->nombre)
				{
					cout <<"Nombre ya existe en la Lista ";
				}
				else
				{ 	// insertamos el Nuevo Nodo
				 	// al Final de la Lista
					cola->ap_der  = nuevo;
					nuevo->ap_izq = cola;
					cola = nuevo;
					cab2 = nuevo;
				}
			}
			else
			{	// como no se inserto al inicio 
				// ni al final de la Lista
				// buscamos un espacio en el intermedio 
				// de esta "la Lista" 
				
				bus1 = new(lista);// creamos dos variables puntero
				bus2 = new(lista);// para recorrer la lista 
								  // e insertar el Nuevo Nodo
				
				sw = 0;
				// se crea una variable "sw" bandera para 
				// recorrer la lista e insertar el Nodo
				bus1 = cab;
				bus2 = cab->ap_der;
				while ( sw == 0 )
				{
					if ( bus2->nombre >= nuevo->nombre )
					{
						nuevo->ap_der = bus2;
						nuevo->ap_izq = bus1;
						cout <<"\n"<<"se adiciono un nodo en intermedio de la lista";
						bus1->ap_der  = nuevo;
						bus2->ap_izq  = nuevo;
						sw = 5; 
						// desactivamos la "sw" bandera de busqueda 
					}
					else
					{   // si no encontramos el espacio
						// seguimos recorriendo la Lista
						bus1 = bus2;
						bus2 = bus2->ap_der;
					}
				}
			}
		}
	}
	espera(); //funcio para dar <Enter>	
}

void mostrar1(void) //ascendente
{
   if (!cab)
   {
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab;
   	  cout <<"\n"<<" Reporte estudiantes Orden alfabetico Ascendente"<<endl;
   	  while (nuevo != NULL)
   	  {
		 cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
		 nuevo = nuevo->ap_der; 	
	  }
   }
   espera();   
}

void mostrar2(void) //descendente
{
   if (!cab)
   {
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab2;
   	  cout <<"\n"<<" Reporte estudiantes Orden alfabetico Descendente"<<endl;
	  while (nuevo != NULL)
   	  {
		 cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
		 nuevo = nuevo->ap_izq; 	
	  }
   }
   espera();   
}

void mostrar_temas(void)
{
   int sw;
   sw = 0;
   if (!cab)
   {
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab;
   	  
   	  nuevo2 = new(lista);
   	  nuevo2 = cab2;
   	  
   	  if (cab->nombre == cab2->nombre)
	  {
   		sw = 3; 	
	  } 
	  cout <<"\n"<<" Reporte estudiantes Orden por temas"<<endl;
	  while ( sw == 0 )
	  {
	  	 if ( nuevo->nombre != nuevo2->nombre )
		 {
		 	cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
		 	cout <<"\n"<<"Nombre  : "<<nuevo2->nombre;
		 	nuevo = nuevo->ap_der;
		 	
			if (nuevo->nombre == nuevo2->nombre)
			{
				sw = 2;
		    }
		    nuevo2 = nuevo2->ap_izq;
			if (nuevo->nombre == nuevo2->nombre)
			{
				sw = 3;	
			}
		}
	  }
	  if (sw == 3)
	  {
	  	cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
	  }
   }
   espera();   
}

void limpiar_lista(void)
{   //inicializamos los nodos de Inicio y Fin de la Lista
 	cab   = NULL;  	cola  = NULL;
	cab2  = NULL; 	cola2 = NULL; 			
}

void espera(void)
{
    cout <<"\n"<<"<Enter";
    getch();	
}
