/*!
	\file monomio.hpp
	\brief Programa para declarar las funciones que crearán un monomio
*/

/*!
	\author Juan José Méndez Torrero
	\date 02/03/2016
*/

#ifndef monomio_hpp
#define monomio_hpp
#include "monomioInterfaz.hpp"
#include <iostream>
#include <cmath>

using namespace std;
namespace ed{
class Monomio : public MonomioInterfaz
{
	private:
		double coeficiente_;
		int grado_;
	public:
		/*!
			\brief Constructor por defecto que asigna las variables a un estado inicial si no se han iniciado antes.
			\param coeficiente Es el coeficiente del monomio.
			\param grado Es el grado del monomio.
		*/
		Monomio(double coeficiente=0, int grado=0)
		{
			coeficiente_=coeficiente;
			grado_=grado;
		}
		/*!
			\brief Constructor de copia que asigna las variables a un estado inicial si no se han iniciado antes.
			\param m Es una variable de tipo monomio.

		*/
		Monomio(const Monomio &m)
		{
			grado_=m.grado_;
			coeficiente_=m.coeficiente_;
		};
		/*!
			\brief Función que lee un monomio que es introducido por teclado.
		*/
		void leerMonomio()
		{
			cout<<"Rellene el monomio."<<endl;
			cout <<"Introduce el coeficiente:";
			cin >> coeficiente_;
			cout <<"Introduce el grado:";
			cin >> grado_;	
		};

		/*!
			\brief Función que escribe un monomio por pantalla.
			\post Si grado_ es distinto de 0, no debemos escribir una x. En caso contrario escribiremos la x con su grado correspondiente
		*/
		void imprimirMonomio()
		{
			
			cout<<""<<coeficiente_;
			if(grado_!=0)
			{
				cout<<"x^";
				cout<<""<<grado_;
			}
			cout<<endl;
			
		}
		/*!
			\brief Modificador para la variable coeficiente
			\return coeficiente_ Es el coeficiente que tiene el monomio.
		*/
		inline double getCoeficiente()const{return coeficiente_;} ;
		/*!
			\brief Observador para la variable coeficiente
			\param coeficiente Es el coeficiente que tiene el monomio.
		*/
		inline void setCoeficiente( double coeficiente){coeficiente_=coeficiente;};
		/*!
			\brief Modificador y observador para la variable grado
			\return grado_ Es el grado que tiene el monomio.
		*/
		inline int getGrado()const{return grado_;};
		/*!
			\brief Observador para la variable grado
			\param grado Es el grado que tiene el monomio.
			\pre Si el grado es <0 el programa ha de pedir un de nuevo el grado del monomio.
		*/
		inline void setGrado(int grado)
		{
			if(grado<=-1)
			{
				cout<<"El grado del monomio no es el correcto."<<endl;
				grado_=0;
			}
			else grado_=grado;
		}

		/*!
			\brief Es un operador que copia el grado y coeficiente de un monomio en otro.
			\param m es una variable tipo monomio que se utilizará para poder acceder al grado y coeficiente del monomio para poder copiarlo.
			\return *this Es una variable de tipo abstracto que contiene el valor del coeficiente y el grado del monomio que hemos copiado.
		*/
		Monomio  operator= (Monomio m)
		{
			grado_=m.getGrado();
			coeficiente_=m.getCoeficiente();

			return *this;
		}

		/*!
			\brief Es un operador que multiplica dos monomios cualquiera.
			\param m es una variable tipo monomio que se utilizará para poder acceder al grado y coeficiente del monomio para poder multiplicarlo por otro monomio diferente.
			\return aux Variable de tipo monomio que contiene el resultado de la multiplicación de los dos monomios.

		*/
		Monomio operator * (Monomio m)
		{
			Monomio aux;
			aux.coeficiente_= coeficiente_ * m.coeficiente_;
			aux.grado_= grado_ + m.grado_;

			return aux;
		}
		/*!
			\brief Es un operador que suma dos monomios cualquiera.
			\param m es una variable tipo monomio que se utilizará para poder acceder al grado y coeficiente del monomio para poder multiplicarlo por otro monomio diferente.
			\return aux Variable de tipo monomio que contiene el resultado de la suma de los dos monomios.
			\pre Se suman dos monomios solo si tienen el mismo grado.

		*/
		Monomio operator + (Monomio m)
		{
			Monomio aux;
			if(aux.grado_==m.grado_)
			{
				aux.coeficiente_= coeficiente_ + m.coeficiente_;
			}
			return aux;
		}


		/*!
			\brief Método que calcula el valor de un monomio con un valor de la x definido.
			\param x Es una variable tipo entero que se pide al usuario para poder evaluar el polinomio con dicha x.
			\return aux Variable tipo double que contiene el valor del monomio ya evaluado con un valor de x.
		*/
		double evaluarMonomio(int x)
		{
			
			double aux;
			aux= coeficiente_* pow(x, grado_);
			return aux;
		}

		/*!
			\brief Operador que sobrecarga la función >> que sirve para introducir los datos del correspondiente monomio.
		*/
		friend istream &operator >> (istream &stream, Monomio &m)
		{
			cout<<"Introduce el coeficiente:"<<endl;
			stream >> m.coeficiente_;
			cout<<"Introduce el grado:"<<endl;
			stream >> m.grado_;
		}
		/*!
			\brief Operador que sobrecarga el operador << que se utiliza para poder escribir por patalla dicho monomio.
		*/

		friend ostream &operator<<(ostream &stream, Monomio const &m)
		{
			cout<<""<<m.coeficiente_;
			if(m.grado_!=0)
			{
				if(m.grado_==1)
				{
					cout<<"x";
				}
				else
				{
					cout<<"x^";
					cout<<""<<m.grado_;
				}
			}
		}

		/*!
			\brief Esta función la hacemos ya que no es posible ordenar el polinomio con la función sort solo se ordenan enteros y por ello, hacemos esta función para comparar Monomios,
		*/
		bool operator <(Monomio aux) 
		{
			if(aux.getGrado()<getGrado())
			{
				return true;
			}
			return false;
		}
	
	
};
}

#endif