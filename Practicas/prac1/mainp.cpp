/*!
	\file mainp.cpp
	\brief Programa para comprobar si la clase polinomio realiza su función.
*/

/*!
	\author Juan José Méndez Torrero
	\date 08/03/2016
*/

#include "polinomio.hpp"
#include <cstdlib>
#include <cassert>
using namespace ed;
int main()
{
	Polinomio p1, p2, p3, p4;
	int op;
	int x;
	
/*
	assert(p1.getGrado()==0 and p1.getNumero()==0);
	cout<<"El ponomio del constructor por defecto no da fallo."<<endl;

	assert(p2.getGrado()==3 and p2.getNumero()==2);
	cout<<"El ponomio del constructor por copia no da fallo."<<endl;

	assert(p3.getGrado()==3 and p3.getNumero()==2);
	cout<<"El ponomio del constructor por copia2 no da fallo."<<endl;
*/


	/*!
		\brief En este caso hacemos un bucle para así poder realizar varias opciones sin tener que ejecutar de nuevo el programa. Cuando introducimos un número mayor que 2, el programa para su ejecución.
	*/
	do
	{
		cout<<endl;
		cout<<"---------------------------------------------------------"<<endl;
		cout<<"CALCULADORA DE POLINOMIOS:"<<endl;
		cout<<"1. Valor de un polinomio para un valor determinado de x."<<endl;
		cout<<"2. Sumar dos polinomio."<<endl;
		cout<<"3. Multiplicar dos polinomios"<<endl;
		cout<<"4. Uso de los operadores << y >>"<<endl;
		cout<<"5. Salir del programa."<<endl;
		cout<<"Introduzca la opción que desea:"<<endl;
		cin>>op;


		switch(op)
		{
			/*!
					\brief Primer caso que nos evalúa un polinomio para una x introducida por teclado por el usuario.
			*/
			case 1:
				system("clear");
				p1.leerPolinomio();
				p1.escribirPolinomio();
				cout<<"Introduce el valor de la x:"<<endl;
				cin >> x;
				cout<<"El valor del polinomio es:"<<p1.evaluarPolinomio(x)<<endl;
				break;
			/*!
					\brief Segundo caso que nos suma dos polinomios introducidos por teclado..
			*/	
			case 2:
				system("clear");
				cout<<"Introduzca el primer polinomio:"<<endl;
				p1.leerPolinomio();
				cout<<"Introduzca el segundo polinomio:"<<endl;
				p2.leerPolinomio();

				p1.escribirPolinomio();				
				p2.escribirPolinomio();

				p3=p1+p2;
				cout<<p3;
				break;
			case 3:
				system("clear");
				cout<<"Introduzca el primer polinomio:"<<endl;
				p1.leerPolinomio();
				cout<<"Introduzca el segundo polinomio"<<endl;
				p2.leerPolinomio();

				p1.escribirPolinomio();
				p2.escribirPolinomio();
				p3= p1*p2;
				cout<<p3;
				break;

			case 4:
				cin>>p4;
				cout<<p4;
				break;
			
			default: cout<<"¡Hasta pronto!"<<endl;

		}
	}while(op<5);

	
}