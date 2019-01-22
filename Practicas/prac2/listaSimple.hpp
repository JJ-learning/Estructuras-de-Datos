/*!
	\file	listaSimple.hpp
	\brief Programa para realizar las funciones para la creación de una lista simple de donantes. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 07/04/2016
*/
#ifndef listaSimple_hpp
#define listaSimple_hpp
#include "nodo.hpp"
#include <cassert>
/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
namespace ed{
class ListaSimple
{
	private:
		Nodo *cabeza_;//Puntero al primer elemento de la lista.

	public:
			/*!
			\name Constructor de la clase ListaSimple.
			\fn ListaSimple(const Donante &x).
			\brief Funcion que declara las variables de la lista.
			\return Ninguno.
			\param d. Tipo Donante.
			
		*/
		ListaSimple(const Donante &x)
			{
				cabeza_= new Nodo (x);//new es para reservar memoria, lo metemos en el constructor para lo mismo que las listas de MP
				
			}
			/*!
			\name Constructor de copia de la clase ListaSimple.
			\fn ListaSimple().
			\brief Funcion que declara las variables de la lista por copia.
			\return Ninguno.
			\param Ninguno.
			
		*/
		ListaSimple()
			{
				cabeza_=NULL;
			}
				/*!
		\name Funcion insertar.
		\fn void insert(const Donante &x).
		\brief Método que inserta un donante en la lista de donantes.
		\return Ninguno.
		\param d. Tipo Donante.
	*/
		void insert(const Donante &x)
			{
				Nodo  *nuevo=new Nodo  (x);//Creamos el elemento que queremos insertar, new es para reservar memoria.
				bool enc=false;
				if(empty())//Si está vacía apuntamos al primer dato de la lista
				{
					cabeza_=nuevo;
				}
				else
				{
					Nodo *aux= cabeza_;
					Nodo *ant;

					if(aux->item() <=x)//Si el dato es más grande que la cabeza, buscamos el sitio donde lo tenemos que insertar
					{
						while(aux && not enc)//Sirve para detectar si el nuevo va entre dos nodos o va al final.
						{
							if(aux->item() <=x)
							{
								ant=aux;
								aux=aux->next();
							}
							else
							{
								enc=true;
							}
						}
						ant->setNext(nuevo);
						nuevo->setNext(aux);
						
					}
					else//Si el dato es menos, lo insertamos en la cabeza.
					{
						nuevo->setNext(cabeza_);
						cabeza_=nuevo;
						
					}
				}
			}
							/*!
		\name Funcion empty.
		\fn bool empty()const.
		\brief Método que mira si en la lista hay donantes.
		\return true. Si la lista está vacía. false. Si en la lista hay algún donante.
		\param Ninguno.
	*/
		bool empty()const
		{
				if(cabeza_==NULL)
				{
					return true;
				}
				else return false;
		}
												/*!
		\name Funcion encontrar item.
		\fn int findItem(Donante d, int pos).
		\brief Método que devuelve la posicion en la que se encuentra un donante que el usuario pide por teclado.
		\pre Que la lista no esté vacia.
		\pre Que la posición sea válida.
		\return cont. Tipo INT.
		\param d. Tipo Donante.
		\param pos. Tipo INT.
	*/
		int findItem(Donante d, int pos)
		{
			assert(!empty());
			assert (isvalid(pos));
			Nodo *aux=cabeza_;//Devuelvo en aux la direccion de memoria del nodo que se encuentra en la cabeza
			int cont=0;

			while (aux)
			{
				if(cont>=pos)//Si 
				{
					if(d==aux->item())//Si encontramos el donante
					{
						//cont=pos;
						return cont;
					}

				}
				cont++;
				aux=aux->next();
			}
			return -1;//Devuelve -1 si no lo encuentra
		}
							/*!
		\name Funcion isValid.
		\fn bool isvalid(int pos).
		\brief Método que mira si la posición introducida es válida.
		\return true. Si la posicion es válida. false. Si en la posición no es válida.
		\param pos. Tipo INT.
	*/
		bool isvalid(int pos)
		{
			Nodo *aux=cabeza_;
			int cont=0;//Empieza en -1 para poder contemplar la posición 0

			while(aux)//Primero recorremos la lista para saber cuantos elementos tiene
			{
				cont++;
				aux=aux->next();
			}
			if(cont>=0 && pos <=cont)//Caso en el que la posición es válida
			{
				return true;
			}
			return false;
		}	
													/*!
		\name Funcion item.
		\fn Donante Item(int pos).
		\brief Método que devuelve la un donante.
		\pre Que la lista no esté vacia.
		\pre Que la posición sea válida.
		\return aux. Tipo Nodo.
		\param pos. Tipo INT.
	*/
		Donante Item(int pos)
		{
			assert(!empty());
			assert (isvalid(pos));//Si la condicion es válida
			Nodo *aux=cabeza_;
			int cont=0;

			while(aux)
			{
				if(cont==pos)
				{
					return aux->item();
				}
				cont++;
				aux=aux->next();
			}
		}
												/*!
		\name Funcion isLast.
		\fn bool isLast(int pos).
		\brief Método que devuelve si un donante es el último de la lista o no.
		\pre Que la lista no esté vacia.
		\pre Que la posición sea válida.
		\return true. Si es el último elemento de la lista. false. Si no es el último elemento de la lista.
		\param pos. Tipo INT.
	*/
		bool isLast(int pos)
		{
			assert(!empty());
			assert (isvalid(pos));//Si la condicion es válida
			Nodo *aux=cabeza_;

			int cont=0;
			while(aux)
			{
				cont++;
				aux=aux->next();
			}

			if(cont==pos) return true;
			else return false;	
		}
					/*!
		\name Funcion borrar.
		\fn void deletePos(int pos).
		\brief Método que borra un donante en la lista de donantes.
		\return Ninguno.
		\param pos. Tipo INT.
	*/
		void deletePos(int pos)
		{
			assert(!empty());
			assert (isvalid(pos));//Si la condicion es válida

			Nodo  *aux=cabeza_;
			int cont=0;
			bool enc=false;

				if(pos==0)//Si estamos en la primera posición
				{
					cabeza_=cabeza_->next();
					delete aux;
				}
				else
				{
					Nodo *ant=cabeza_;
					
					while(aux && not enc)//Recorremos hasta el final o lo haya encontrado
					{
						if(pos==cont)//Si lo he encontrado
						{
							enc=true;
						}
						else//Pasamos al siguiente, y dejamos el puntero anterior en aux. 
						{
							ant=aux;
							cont++;
							aux=aux->next();
						
						}
					}
					
					ant->setNext(aux->next());//Hacemos esto para que el siguiente se salte el item de aux y apunte al siguiente de aux.
					delete aux;
					
				}
		}
							/*!
		\name Funcion tamaño.
		\fn int tama().
		\brief Método que devuelve el número de donantes que hay en la lista.
		\return cont. Tipo INT.
		\param Ninguno.
	*/
		int tama()
		{
			Nodo *aux=cabeza_;
			int cont=0;

			while(aux)
			{
				cont++;
				aux=aux->next();
			}
			return cont;
		}
	
};

}

#endif