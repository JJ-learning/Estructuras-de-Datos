/*!
	\file monomioInterfaz.hpp
	\brief Programa para declarar las funciones virtuales para la creación de un monomio
*/

/*!
	\author Juan José Méndez Torrero
	\date 02/03/2016
*/

#ifndef monomioInterfaz_hpp
#define monomioInterfaz_hpp
/*!
	\brief Espacio de nombre para la asginatura Estructura de datos
*/
namespace ed
{
	/*!
		\brief Clase para definir los métodos virtuales que van a ser utilizados posteriormente para la formación de un monomio.
	*/
	class MonomioInterfaz
	{

	public:
		/*!
			\brief Modificador y observador para la variable coeficiente
			\param coeficiente Es el coeficiente que tiene el monomio.
		*/
		virtual double getCoeficiente()const=0;
		virtual void setCoeficiente(double coeficiente)=0;
		/*!
			\brief Modificador y observador para la variable grado
			\param grado Es el grado que tiene el monomio.
		*/
		virtual int getGrado()const=0;
		virtual void setGrado(int grado)=0;

	};


}




#endif