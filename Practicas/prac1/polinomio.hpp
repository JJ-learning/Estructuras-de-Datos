/*!
	\file polinomio.hpp
	\brief Programa para declarar la clase polinomio.
*/

/*!
	\author Juan José Méndez Torrero
	\date 08/03/2016
*/


#ifndef polinomio_hpp
#define polinomio_hpp
#include "polinomioInterfaz.hpp"

namespace ed
{
	class Polinomio : public PolinomioInterfaz
	{
		private:
			int grado_;
			int numero_;
			list <Monomio> l_;
		public:
			/*!
			\brief Constructor por defecto que asigna las variables a un estado inicial si no se han iniciado antes.
			\param grado Es el grado maximo que tiene el polinomio.
			\param numero Es el número de monomios que tiene el polinomio.
			*/
			Polinomio(int grado=0, int numero=0)
			{
				setGrado(grado);
				setNumero(numero);
			}
			/*!
			\brief Constructor de copia que asigna las variables a un estado inicial si no se han iniciado antes.
			\param p Es una variable de tipo Polinomio.
			*/
			Polinomio(const Polinomio &p)
			{
				setGrado(p.getGrado());
				setNumero(p.getNumero());
				if(!l_.empty())
				{
					l_.clear();
				}
				l_ =p.l_;
			}
			/*!
			\brief Modificador para la variable grado.
			\return grado_ Devuelve el grado máximo del polinomio
			*/
			inline int getGrado()const{return grado_;};
			/*!
			\brief Observador para la variable grado.
			\param grado Es el grado máximo que tiene el polinomio.
			*/
			inline void setGrado(int grado){grado_=grado;};
			/*!
			\brief Modificador  para la variable numero
			\return numero_ Devuelve el numero de monomios del polinomio
			*/
			inline int getNumero()const{return numero_;};
			/*!
			\brief Observador para la variable numero
			\param numero Es el número de monomios que forman el polinomio.
			*/
			inline void setNumero(int numero){numero_=numero;};

			inline bool listaVacia(){};
			/*!
			\brief Modificador para la variable tipo monomio
			\param aux Es una variable tipo Monomio que la utilizaremos para poder modificarla y posteriormente insertarta en la lista.
			\param grado Es el grado maximo que puede tener el polinomio.
			\return true si se ha podido insertar satisfactoriamente.
			*/
			bool getMonomio(Monomio &aux, int grado)
			{
				list <Monomio> :: iterator it;
				if(!l_.empty())
				{	
					for(it=l_.begin(); it!= l_.end();it++)
					{
						if(grado==it->getGrado())
						{
							aux=*it;
							return true;
						}
					}
					return false;

				}
				else return false;				
			}
			/*!
			\brief Observador para la variable tipo monomio
			\param aux Es una variable tipo Monomio que la utilizaremos para poder modificarla y posteriormente insertarta en la lista.
			\return true si se ha podido insertar satisfactoriamente.
			*/
			bool setMonomio(Monomio aux)
			{
				if(!getMonomio(aux, aux.getGrado()))
				{
					l_.push_back(aux);
					return true;
				}
				return false;
			}
				
			/*!
			\brief Función que lee un polinomio que es introducido por teclado.
			\post Si el grado introducido es mayor que el grado máximo del polinomio, se escribirá por pantalla un mensaje de error.
			\pre Si el número de polinomios es mayor que el grado, el programa debe enviar un mensaje de error.
			*/
			void leerPolinomio()
			{
				
				do
				{
					cout<<"Introduzca el grado del polinomio:"<<endl;
					cin>> grado_;

					cout<<"Introduzca el numero de monomios del polinomio:"<<endl;
					cin>> numero_;
					if(numero_>grado_)
					{
						cout<<"Error al introducir el grado y el número de monomios. Porfavor, introduzcalos denuevo."<<endl;
					}
				}while(numero_>grado_);

				if(!l_.empty())
				{
					l_.clear();
				}
				Monomio aux;
				bool esta;
				int i;
				for(i=0;i<numero_;i++)
				{
					do
					{
						do
						{
							cin>>aux;
							if(grado_<aux.getGrado())
							{
								cout<<"El grado introducido es mayor que el permitido, por favor, introduzcalo de nuevo."<<endl;
							}
						}while(aux.getGrado()>grado_);
						
						
						
						esta=setMonomio(aux);

					}while(!esta);
				}
				l_.sort();
			}
			/*!
			\brief Función que escribe un monomio por pantalla.
			\post Si la variable cont es 0 significa que estamos en el primer monomio, con lo que no debemos escribir un +, además de esa condición, el coeficiente del monomio debe de ser mayor que 0.
			*/
			void escribirPolinomio()
			{
				cout<<"Grado máximo del polinomio:"<<grado_<<endl;
				cout<<"El número de elementos del polinomio es:"<<numero_<<endl;
				list <Monomio> :: iterator i;
				int cont=0;
				for(i=l_.begin(); i!=l_.end(); i++)
				{
					if(cont!=0 && i->getCoeficiente()>0)
					{
						cout<<"+";
					}
					cout<<*i;
					cont++;
				}
				cout<<endl;
			}
			/*!
			\brief Es un operador que suma dos polinomios introducidos por teclado.
			\param p es una variable tipo Polinomio que se utilizará para poder acceder al grado y numero de monomios del polinomio para poder sumarlo con otro polinomio distinto.
			\return aux Variable de tipo Polinomio que contiene el resultado de la suma de los dos polinomios.
			*/
			Polinomio operator +(Polinomio p)
			{
				int enc;
				Polinomio aux;
				
				list<Monomio> :: iterator ip;//Iterador de la lista p.l_
				list<Monomio> :: iterator ia;//Iterador de la lista aux.l_

				if(getGrado() > p.getGrado())
				{
					aux.setGrado(getGrado());
				}
				else aux.setGrado(p.getGrado());

				aux.l_=l_;
				aux.setNumero(getNumero());
				for(ip=p.l_.begin(); ip!= p.l_.end(); ip++)
				{
					enc=0;
					for(ia= aux.l_.begin(); ia!=aux.l_.end(); ia++)
					{
						if(ip->getGrado()==ia->getGrado())
						{
							ia->setCoeficiente(ip->getCoeficiente()+ia->getCoeficiente());
							enc=1;
						}
						
					}
					if(enc==0)
						{
							aux.setMonomio(*ip);
							aux.numero_+=1;
						}
				}
				aux.l_.sort();
				aux.setNumero(aux.l_.front().getGrado());
				return	aux;
			}

			
			Polinomio operator= (Polinomio p)
			{
				grado_=p.getGrado();
				numero_=p.getNumero();

				if(!l_.empty())
				{
					l_.clear();
				}
				list<Monomio> ::iterator i;
				for(i=p.l_.begin(); i!= p.l_.end(); i++)
				{
					l_.push_back(*i);
				}
				return *this;
			}

			Polinomio operator *(Polinomio p)
			{
				
				Polinomio aux;
				
				list<Monomio> :: iterator ip;//Iterador de la lista p.l_
				list<Monomio> :: iterator ia;//Iterador de la lista aux.l_

				if(getGrado() > p.getGrado())
				{
					aux.setGrado(getGrado());
				}
				else aux.setGrado(p.getGrado());

				aux.l_=l_;
				aux.setNumero(getNumero());
				for(ip=p.l_.begin(); ip!= p.l_.end(); ip++)
				{
					
					for(ia= aux.l_.begin(); ia!=aux.l_.end(); ia++)
					{
							
						ia->setCoeficiente(ip->getCoeficiente()*ia->getCoeficiente());
						ia->setGrado(ip->getGrado()+ia->getGrado());
										
					}
					
				}
				aux.l_.sort();
				aux.setGrado(aux.l_.front().getGrado());
				return	aux;
			}
			

			/*!
			\brief Método que calcula el valor de un polinomio con un valor de la x definido.
			\param x Es una variable tipo entero que se pide al usuario para poder evaluar el polinomio con dicha x.
			\return suma Variable tipo double que contiene el valor del polinomio ya evaluado con un valor de x.
			*/
			double evaluarPolinomio(int x)
			{
				
				
				list<Monomio> :: iterator i;
				double suma=0;

				for(i=l_.begin(); i!= l_.end(); i++)
				{
					suma=suma + i->evaluarMonomio(x);
				}
				return suma;
			}
	
			/*Los operadores son lo mismo que leer y escribir polinomio pero cuando tengamos que escribir o leer tenemos que poner stream<< o stream>>
			Además, para todas las variables que eran de tipo this hay que poner un p. para que funciones
			*/

			/*!
			\brief Operador que sobrecarga la función >> que sirve para introducir los datos del correspondiente monomio.
			*/
			friend istream &operator>>(istream &stream, Polinomio &p)
			{
				do
				{
					cout<<"Introduzca el grado del polinomio:"<<endl;
					stream>> p.grado_;

					cout<<"Introduzca el numero de monomios del polinomio:"<<endl;
					stream>> p.numero_;
					if(p.numero_>p.grado_)
					{
						cout<<"Error al introducir el grado y el número de monomios. Porfavor, introduzcalos denuevo."<<endl;
					}
				}while(p.numero_>p.grado_);


				Monomio aux;
				bool esta;
				int i;
				for(i=0;i<p.numero_;i++)
				{
					do
					{
						do
						{
							cin>>aux;
							if(p.grado_<aux.getGrado())
							{
								cout<<"El grado introducido es mayor que el permitido, por favor, introduzcalo de nuevo."<<endl;
							}
						}while(aux.getGrado()>p.grado_);
						
						
						
						esta=p.setMonomio(aux);

					}while(!esta);
				}
				p.l_.sort();
			}
			/*!
			\brief Operador que sobrecarga el operador << que se utiliza para poder escribir por patalla dicho monomio.
		*/
			friend ostream &operator<<(ostream &stream, Polinomio &p)
			{
				cout<<"Grado máximo del polinomio:"<<p.grado_<<endl;
				cout<<"El número de elementos del polinomio es:"<<p.numero_<<endl;
				list <Monomio> :: iterator i;
				int cont=0;
				for(i=p.l_.begin(); i!=p.l_.end(); i++)
				{
					if(cont!=0 && i->getCoeficiente()>0)
					{
						stream<<"+";
					}
					stream<<*i;
					cont++;
				}
				cout<<endl;
			}
			
			

			

	};			
}


#endif