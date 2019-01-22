/*!
	\file	DonantesInterfaz.hpp
	\brief Programa para declarar las funciones virtuales que crearán un donante.
*/

/*!
	\author Juan José Méndez Torrero
	\date 07/04/2016
*/

#ifndef DonantesInterfaz_hpp
#define DonantesInterfaz_hpp
#include "donante.hpp"


/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
namespace ed
{
	
	class DonantesInterfaz
	{
	public:
					/*!
		\name Funcion insertar.
		\fn virtual void insertar(const Donante &x)= 0.
		\brief Método que inserta un donante en la lista de donantes.
		\return Ninguno.
		\param d. Tipo Donante.
	*/
		virtual void insertar(const Donante &x)= 0;
						/*!
		\name Funcion borrar.
		\fn virtual void borrar(const Donante &x)= 0.
		\brief Método que borra un donante en la lista de donantes.
		\return Ninguno.
		\param d. Tipo Donante.
	*/
		virtual void borrar(const Donante &x) = 0;
								/*!
		\name Funcion buscar.
		\fn virtual bool buscar(Donante &x)=0.
		\brief Método que busca un donante en la lista de donantes.
		\pre Que la lista no esté vacia.
		\return true. Si encuentra el donante en la lista. false. Si no encuentra el donante en la lista.
		\param d. Tipo Donante.
	*/
		virtual bool buscar(Donante &x)=0;
							/*!
		\name Funcion vacia.
		\fn virtual bool vacia()const=0.
		\brief Método que mira si en la lista hay donantes.
		\return true. Si la lista está vacía. false. Si en la lista hay algún donante.
		\param Ninguno.
	*/
		virtual bool vacia()const=0;
		
	};
}




#endif