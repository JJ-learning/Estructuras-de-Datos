/*!
	\file	nodo.hpp
	\brief Programa para realizar las funciones para la creación de un nodo. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 07/04/2016
*/

#ifndef nodo_hpp
#define nodo_hpp
#include "donante.hpp"
/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
namespace ed{
class Nodo
{
	private:
		Donante data_;//El conjunto de datos de un donante.
		Nodo *sig_;//Puntero que apunta a la siguiente posición de la lista.
	public:
		/*!
			\name Constructor de la clase Nodo.
			\fn Nodo (const Donante x).
			\brief Funcion que declara las variables de un nodo.
			\return Ninguno.
			\param d. Tipo Donante.
			
		*/
		Nodo (const Donante x)
		{
			data_=x;
			sig_=NULL;
		}
/*!
			\name Funcion siguiente.
			\fn Nodo * next().
			\brief Observador de la variable sig_
			\return sig_. Tipo Nodo.
			\param Ninguno.
			
		*/
		Nodo * next()
		{
			return sig_;
		}
/*!
			\name Funcion Modificadora siguiente.
			\fn void setNext(Nodo *aux)
			\brief Modificador de la variable sig_
			\return Ninguno.
			\param aux. Tipo Nodo.
			
		*/
		void setNext(Nodo *aux)
		{
			sig_=aux;
		}
/*!
			\name Funcion Observadora item.
			\fn Donante item()
			\brief Observador de la variable data_
			\return data_. Tipo Donante.
			\param Ninguno.
			
		*/
		Donante item()
		{
			return data_;
		}
/*!
			\name Funcion Modificadora item.
			\fn void setItem(Donante x)
			\brief Modificador de la variable data_.
			\return Ninguno.
			\param x. Tipo Donante.
			
		*/
		void setItem(Donante x)
		{
			data_=x;
		}
};

}

#endif