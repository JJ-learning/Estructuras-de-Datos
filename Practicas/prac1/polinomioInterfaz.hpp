/*!
	\file polinomioInterfaz.hpp
	\brief Programa para declarar las funciones virtuales para la creación de un polinomio
*/

/*!
	\author Juan José Méndez Torrero
	\date 08/03/2016
*/

#ifndef polinomioInterfaz_hpp
#define polinomioInterfaz_hpp
#include "monomio.hpp"
#include <list>

/*!
	\brief Espacio de nombre para la asginatura list y para endl
*/
using std::list;
using std::endl;

namespace ed
{
	/*!
		\brief Clase para definir los métodos virtuales que van a ser utilizados posteriormente para la formación de un polinomio.
	*/
	class PolinomioInterfaz
	{
		public:
			/*!
			\brief Modificador para la variable grado.
			\return grado_ Devuelve el grado máximo del polinomio
			*/
			virtual int getGrado()const=0;
			/*!
			\brief Observador para la variable grado.
			\param grado Es el grado máximo que tiene el polinomio.
			*/
			virtual void setGrado(int grado)=0;
			/*!
			\brief Modificador  para la variable numero
			\return numero_ Devuelve el numero de monomios del polinomio
			*/
			virtual int getNumero()const=0;
			/*!
			\brief Observador para la variable numero
			\param numero Es el número de monomios que forman el polinomio.
			*/
			virtual void setNumero(int numero)=0;
			/*!
			\brief Modificador para la variable tipo monomio
			\param aux Es una variable tipo Monomio que la utilizaremos para poder modificarla y posteriormente insertarta en la lista.
			\param grado Es el grado maximo que puede tener el polinomio.
			\return true si se ha podido insertar satisfactoriamente.
			*/
			virtual bool getMonomio(Monomio &aux, int grado)=0;
			/*!
			\brief Observador para la variable tipo monomio
			\param aux Es una variable tipo Monomio que la utilizaremos para poder modificarla y posteriormente insertarta en la lista.
			\return true si se ha podido insertar satisfactoriamente.
			*/
			virtual bool setMonomio(Monomio aux)=0;

			virtual bool listaVacia()=0;
	};
}

#endif