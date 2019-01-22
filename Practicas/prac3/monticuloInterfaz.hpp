/*!
	\file monticuloInterfaz.hpp
	\brief Programa para declarar las funciones virtuales que crearán un monticulo. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 26/04/2016
*/
#ifndef monticuloInterfaz_hpp
#define monticuloInterfaz_hpp

#include "donante.hpp"
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;
/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
namespace ed{

	class MonticuloInterfaz{

		public:
		/*!
		\name Funcion is empty.
		\fn virtual bool isEmpty() const=0.
		\brief Método que si un montículo contiene datos o no.
		\return true si el monticulo está vacío, false si el montículo contiene donantes.
	*/
			virtual bool isEmpty() const=0;
	/*!
		\name Funcion cima.
		\fn virtual Donante cima() const=0.
		\brief Método que devuelve el donante que se encuentra en la cima.
		\return v_.front() Donante que se encuentra en la primera posición del vector.
	*/
			virtual Donante cima() const=0;
				/*!
		\name Funcion insertar.
		\fn virtual void insertar(Donante d)=0.
		\brief Método que inserta un donante en el montículo.
		\return Ninguno.
		\param d Tipo Donante.
	*/
			virtual void insertar(Donante d)=0;
							/*!
		\name Funcion remove.
		\fn virtual void remove()=0.
		\brief Método que borra la cima.
		\return Ninguno.
	*/
			virtual void remove()=0;



	};
}

#endif
