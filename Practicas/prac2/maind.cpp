/*!
	\file maind.cpp
	\brief Programa principal para el uso de las funciones de donantes. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 07/04/2016
*/

#include "Donantes.hpp"

/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
using namespace ed;
int main()
{
	Donantes l;
	Donante d;
	string nombreF;
	
	int op;

	do
	{
		cout<<"Donantes 2.0"<<endl;
		cout<<"1. Comprobar si hay donantes."<<endl;
		cout<<"2. Cargar donantes en un fichero."<<endl;
		cout<<"3. Guardar donantes en un fichero."<<endl;
		cout<<"4. Añadir nuevos donantes."<<endl;
		cout<<"5. Modificar un donante."<<endl;
		cout<<"6. Borrar donante."<<endl;
		cout<<"7. Mostrar los donantes de la lista."<<endl;
		cout<<"8. Total de donantes en la lista."<<endl;
		cout<<"9. Salir del programa."<<endl;
		cout<<"Elige una opción:"<<endl;
		cin>>op;
		switch(op)
		{
			/*!
				\brief caso 1. Opción para ver si hay donantes en la lista.
			*/
			case 1:
				system("clear");
				if(l.vacia()==true)
				{
					cout<<"No hay donantes en estos momentos."<<endl;
				}
				else cout<<"Hay donantes en la lista."<<endl;
				break;
			/*!
				\brief caso 2. Opción que carga los datos desde un fichero.
			*/
			case 2:
				system("clear");
				cout<<"Escribe el nombre del fichero donde quieres cargar los datos."<<endl;
				cin>> nombreF;
				l.cargarF(nombreF);
				break;	
			/*!
				\brief caso 3. Opción que guarda los datos en un fichero.
			*/
			case 3:
				system("clear");
				cout<<"Escribe el nombre del fichero donde quieres cargar los datos."<<endl;
				cin>> nombreF;
				l.grabarF(nombreF);
				break;
				/*!
				\brief caso 4. Opción para añadir un donante a la lista.
			*/
			case 4:
				system("clear");
				d.leerDonante();
				l.insertar(d);
				
				break;
				/*!
				\brief caso 5. Opción para modificar un donante.
			*/
			case 5:
				system("clear");
				cout<<"Introduzca los datos del donante ha modificar."<<endl;
				d.leerDonante();
			
				if(l.buscar(d))
				{
					if(l.modificar(d))
					{
						cout<<"Persona modificada."<<endl;
					}
					else cout<<"Persona no modificada."<<endl;
				}
				else cout<<"El donante no existe."<<endl;
				
				break;
				/*!
				\brief caso 6. Opción para borrar un donante.
			*/
			case 6:
				system("clear");
				cout<<"Introduzca los datos del donante ha borrar."<<endl;
				d.leerDonante();

				if(l.buscar(d))
				{
					cout<<"El donante existe."<<endl;
					l.borrar(d);					
					cout<<"El donante ha sido borrado satisfactoriamente."<<endl;
					
				}
				else cout<<"El donante no existe."<<endl;
				break;
				/*!
				\brief caso 7. Opción para mostrar la lista por pantalla.
			*/
			case 7:
				system("clear");
				l.mostrar();
				break;
				/*!
				\brief caso 8. Opción para saber le número de donantes que hay en la lista.
			*/
			case 8:
				system("clear");
				cout<<"El tamaño de la lista de donantes es:";
				cout<<l.tam()<<endl;
				break;
						/*!
				\brief default. Opción para salir del programa.
			*/
			default:
				system("clear");
				cout<<"Hasta la próxima!"<<endl;
				exit(0);
		}
	}while(op!=9);
	
}