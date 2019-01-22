/*!
	\file main.cpp
	\brief Programa principal para poder comprobar si el programa funciona correctamente
*/

/*!
	\author Juan José Méndez Torrero
	\date 02/03/2016
*/


#include "monomio.hpp"
#include <cstdlib>
#include <cassert>

using namespace ed;
int main()
{
	Monomio m1, m2(3,2), m3(m2);
	int op;
	int x;

	
	/*!
		\brief En este caso hacemos un bucle para así poder realizar varias opciones sin tener que ejecutar de nuevo el programa. Cuando introducimos un número mayor que 2, el programa para su ejecución.
	*/
	do
	{

		cout<<"Monomios 2.0"<<endl;
		cout<<"1. Evaluar un monomio"<<endl;
		cout<<"2. Multiplicar dos monomios."<<endl;
		cout<<"3. Salir del programa."<<endl;
		cout<<"Elige una opción:"<<endl;
		cin>>op;
		
		switch(op)
		{
			case 1: 
				/*!
					\brief Primer caso que nos evalúa un monomio para una x introducida por teclado por el usuario.
				*/
				
				system("clear");
				m1.leerMonomio();
				m1.imprimirMonomio();
				cout<<"Introduce el valor de la x:"<<endl;
				cin >> x;
				cout<< "El valor del polinomio es:"<< m1.evaluarMonomio(x)<<endl;
				break;

			case 2:
				/*!
					\brief Segundo caso para poder comprobar que los operadores = y * funcionan correctamente.
				*/
				system("clear");
				cout<<"Introduzca el primer monomio:"<<endl;
				m1.leerMonomio();
				cout<<"Introduzca el segundo monomio"<<endl;
				m2.leerMonomio();

				m1.imprimirMonomio();
				m2.imprimirMonomio();		
				m3=m1*m2;
				//system("clear");
				cout<<m3<<endl;
				break;
				
			default:
				/*!
					\brief Ultimo caso para poder salir del programa sin tener que abortarlo.
				*/
				cout<<"Hasta la próxima!"<<endl;
				exit(0);
		}
	}while(op!=3);
}