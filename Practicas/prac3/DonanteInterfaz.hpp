/*!
	\file DonanteInterfaz.hpp
	\brief Programa para declarar las funciones virtuales que crearán un donante. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 26/04/2016
*/

#ifndef DonanteInterfaz_hpp
#define DonanteInterfaz_hpp
#include <string>

using std::string;
/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
namespace ed
{
	class DonanteInterfaz
	{
	public:
	/*!
		\name Funcion Observadora del nombre.
		\fn virtual string getNombre()const=0.
		\brief Método que devuelve el nombre del donante.
		\return Nombre del donante de tipo STRING.
		\param Ninguno.
	*/
		virtual string getNombre()const=0;
		/*!
		\name Funcion Modificadora del nombre.
		\fn virtual void setNombre(string nombre)=0.
		\brief Método que modifica el nombre del donante.
		\return Ninguno.
		\param nombre de tipo string.
	*/
		virtual void setNombre(string nombre)=0;
		
		/*!
		\name Funcion Observadora del apellido.
		\fn virtual string getApellido()const=0.
		\brief Método que devuelve el apellido del donante.
		\return Apellido del donante de tipo STRING.
		\param Ninguno.
	*/
		virtual string getApellidos()const=0;
			/*!
		\name Funcion Modificadora del Apellido.
		\fn virtual void setApellido(string apellido)=0.
		\brief Método que modifica el Apellido del donante.
		\return Ninguno.
		\param apellido de tipo string.
	*/
		virtual void setApellidos(string apellido)=0;
		/*!
		\name Funcion Observadora del Grupo.
		\fn virtual string getGrupo()const=0.
		\brief Método que devuelve el Grupo del donante.
		\return Grupo del donante de tipo STRING.
		\param Ninguno.
	*/
		virtual string getGrupo()const=0;
			/*!
		\name Funcion Modificadora del Grupo.
		\fn virtual void setGrupo(string grupo)=0.
		\brief Método que modifica el Grupo del donante.
		\return Ninguno.
		\param grupo de tipo string.
	*/
		virtual void setGrupo(string grupo)=0;
/*!
		\name Funcion Observadora del Factor.
		\fn virtual string getFactor()const=0.
		\brief Método que devuelve el Factor del donante.
		\return Factor del donante de tipo STRING.
		\param Ninguno.
	*/
		virtual string getFactor()const=0;
			/*!
		\name Funcion Modificadora del Factor.
		\fn virtual void setFactor(string factor)=0.
		\brief Método que modifica el Factor del donante.
		\return Ninguno.
		\param factor de tipo string.
	*/
		virtual void setFactor(string factor)=0;
/*!
		\name Funcion Observadora de las Donaciones.
		\fn virtual int getDonaciones()const=0.
		\brief Método que devuelve las donaciones del donante.
		\return donaciones del donante de tipo INT.
		\param Ninguno.
	*/
		virtual int getDonaciones()const=0;
					/*!
		\name Funcion Modificadora de las donaciones.
		\fn virtual void setDonaciones(int donaciones)=0.
		\brief Método que modifica las donaciones del donante.
		\return Ninguno.
		\param donaciones de tipo int.
	*/
		virtual void setDonaciones(int donaciones)=0;

		

		
	};
}




#endif