/*!
	\file main.cpp
	\brief Programa principal para el uso de las funciones. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 07/04/2016
*/

#include "donante.hpp"

/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
using namespace ed;
int main()
{
	Donante d ,d1,d2;
	int op;
	do
	{
		cout<<"Donante 2.0"<<endl;
		cout<<"1. Leer un donante."<<endl;
		cout<<"2. Escribir un donante."<<endl;
		cout<<"3. Modificar un donante."<<endl;
		cout<<"4. Comparar lexicográficamente."<<endl;
		cout<<"5. Salir del programa."<<endl;
		cout<<"Elige una opción:"<<endl;
		cin>>op;
		switch(op)
		{
			/*!
				\brief caso 1. Opción para leer un donante por teclado.
			*/
			case 1:
				system("clear");
				cout<<"Escriba los datos del donante:"<<endl;
				d.leerDonante();
				break;
			/*!
				\brief caso 2. Opción para imprimir un donante por pantalla.
			*/
			case 2:
				system("clear");
				cout<<"Los datos son:"<<endl;
				d.imprimirDonante();
				break;
				/*!
				\brief caso 3. Opción para modificar un donante.
			*/
			case 3:
				system("clear");
				d.leerDonante();
				if(d.modificar(d))
				{
					cout<<"Donante modificado."<<endl;
				}
				else cout<<"Donante NO modificado."<<endl;
				break;
					/*!
				\brief caso 4. Opción para comparar lexicográficamente dos donantes.
			*/
			case 4:
				system("clear");
				cout<<"Escriba los datos del primer donante:"<<endl;
				d.leerDonante();
				cout<<"Escriba los datos del segundo donante:"<<endl;
				d1.leerDonante();
				if(d<=d1)
				{
					cout<<"El primer donante es mayor lexicográficamente."<<endl;
				}
				else cout<<"El segundo donante es mayor lexicográficamente."<<endl;
				break;
					/*!
				\brief default. Opción para salir del programa.
			*/
			default:
				system("clear");
				cout<<"Hasta la próxima!"<<endl;
				exit(0);
		}
	}while(op!=5);
}