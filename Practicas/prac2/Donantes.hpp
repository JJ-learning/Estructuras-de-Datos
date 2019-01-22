/*!
	\file	Donantes.hpp
	\brief Programa para realizar las funciones correspondientes de varios donantes. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 07/04/2016
*/

#ifndef Donantes_hpp
#define Donantes_hpp
#include "DonantesInterfaz.hpp"
#include <iostream>
#include <cassert>
#include <fstream>
#include <list>
#include <cstdlib>
#include "listaSimple.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;
using std::ifstream;
using std::ofstream;
/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
namespace ed
{
	
	class Donantes: public DonantesInterfaz 
	{
		private:
			ListaSimple l_;//Lista de donantes.
			int tamanio_;//Número de donantes que se encuentran en la lista.
		public:
							/*!
		\name Contructor de la clase Donantes.
		\fn Donantes(){}.
		\return Ninguno.
		\param Ninguno.
	*/
			Donantes(){}

							/*!
		\name Funcion insertar.
		\fn virtual void insertar(const Donante &x).
		\brief Método que inserta un donante en la lista de donantes.
		\return Ninguno.
		\param d. Tipo Donante.
	*/
			void insertar(const Donante &d)
			{
				if(l_.empty())
				{
					l_.insert(d);
				}
				else
				{
					int pos=l_.findItem(d, 0);//Ponemos cero para que empiece desde el principio
					if(pos==-1)//Si no lo hemos encontrado
					{
						l_.insert(d);
					}
				}
				tamanio_++;
			}
						/*!
		\name Funcion mostrar.
		\fn void mostrar().
		\brief Método que imprime por pantalla la lista de donantes.
		\return Ninguno.
		\param Ninguno.
	*/
			void mostrar()
			{
				int pos=0;
				while(not l_.isLast(pos))//Recorremos la lista mientras que no sea el último
				{
					cout<<l_.Item(pos);
					pos++;
				}
			}
										/*!
		\name Funcion buscar.
		\fn virtual bool buscar(Donante &x)=0.
		\brief Método que busca un donante en la lista de donantes.
		\pre Que la lista no esté vacia.
		\return true. Si encuentra el donante en la lista. false. Si no encuentra el donante en la lista.
		\param d. Tipo Donante.
	*/
			bool buscar(Donante &d)
			{
				assert(not vacia());
				int pos=l_.findItem(d,0);
				if(pos==-1)
				{
					return false;
				}
				else
				{
					d=l_.Item(pos);
					return true;
				}
			}
					/*!
		\name Funcion leer Donantes.
		\fn void leerDonantes().
		\brief Método que lee por teclado un donante.
		\return Ninguno.
		\param Ninguno.
	*/
			void leerDonantes()
			{
				Donante d;
				int op;
				
				do{
					cout<<"Introduce un donante:"<<endl;
					cin>>d;

					cout<<"Pulse 0 para salir"<<endl;
					cin>>op;
				}while(op!=0);
			}
					/*!
		\name Funcion cargar Donantes.
		\fn void cargarF(string nombreF).
		\brief Método que lee los donantes de un fichero.
		\return Ninguno.
		\param nombreF. Tipo string.
	*/
			void cargarF(string nombreF)
			{
				Donante d;
				char  nombre[50], apellidos[50], grupo[50],factor[50];
								
				ifstream fich(nombreF.c_str()); 

				while (fich.getline(nombre,256,',')) 
			    { 
					
					fich.getline(apellidos,256,',');
					fich.getline(grupo,256,',');
					fich.getline(factor,256,'\n');
					d.setNombre(nombre);
					d.setApellidos(apellidos);					
					d.setGrupo(grupo);
					d.setFactor(factor);
			
					insertar(d);
				}

				fich.close();
			}
								/*!
		\name Funcion guardar Donantes.
		\fn void grabarF(string nombreF).
		\brief Método que guarda los donantes de un fichero.
		\return Ninguno.
		\param nombreF. Tipo string.
	*/
			void grabarF(string nombreF)
			{
				
				ofstream fich(nombreF.c_str()); 

				int pos=0;
				while(not l_.isLast(pos))//Recorremos la lista mientras que no sea el último
				{
					fich<<l_.Item(pos).getNombre()<<","<<l_.Item(pos).getApellidos()<<","<<l_.Item(pos).getGrupo()<<","<<l_.Item(pos).getFactor()<<"\n";
					pos++;
				}
				
	


				fich.close();
			}
						/*!
		\name Funcion borrar.
		\fn virtual void borrar(const Donante &x).
		\brief Método que borra un donante en la lista de donantes.
		\return Ninguno.
		\param d. Tipo Donante.
	*/
			void borrar(const Donante &d)
			{
				int pos=l_.findItem(d,0);
				l_.deletePos(pos);
				tamanio_--;
			}
/*!
		\name Funcion que modifica un donante.
		\fn bool modificar(Donante d).
		\brief Función que modifica un donante.
		\return true. Si el dato se ha modificado correctamente. false. Si el daot no se ha podido modificar.
		\param d. Tipo Donante.
	*/
			bool modificar(Donante d)
			{
                
                int op;
                string n;
                char cad[256],cad2[256];
                
              
                  borrar(d);
                    do{
                        op=ini();
                        switch(op){
                        case 1:
                        cout<<"Introduce nuevo nombre: "<<endl;
                        cin.ignore();
                        cin.getline(cad,256);
                        d.setNombre(cad);
                        break;
                        case 2:
                        cout<<"Introduce nuevos apellidos: "<<endl;
                        cin.ignore();
                        cin.getline(cad2,256);
                        d.setApellidos(cad2);
                        break;
                        case 3:
                        cout<<"Introduce nuevo grupo sanguineo: "<<endl;
                        cin>>n;
                        d.setGrupo(n);
                        break;
                        case 4:
                        cout<<"Introduce nuevo RH: "<<endl;
                        cin>>n;
                        d.setFactor(n);
                        break;
                        case 5:
                        cout<<"Ha elegido no modificar más"<<endl;
                        break;                        
                       }
                   }while(op!=5);
                    insertar(d);
                    return true;
               
            	return false;
            }
/*!
		\name Funcion menú.
		\fn  int ini().
		\brief Función que indica qué parte de un donante se desea modificar.
		\return x. Tipo entero.
		\param Ninguno.
	*/
            int ini()
            {
            	system("clear");
	            int x;
	            cout<<"--------------------------------------------"<<endl;
	            cout<<"---------------------MENU-------------------"<<endl;
	            cout<<"--------------------------------------------"<<endl;
	            cout<<"--------1.Modificar nombre del Donante------"<<endl;
	            cout<<"------2.Modificar apellido del Donante------"<<endl;
	            cout<<"---------3.Modificar grupo Sanguineo--------"<<endl;
	            cout<<"----------------4.Modificar RH--------------"<<endl;
	            cout<<"-------------5.Salir de modificar-----------"<<endl;
	            cout<<"--------------------------------------------"<<endl;

	            cout<<"Introduce opcion: "<<endl;
	            cin>>x;
	            return x;
			}
							/*!
		\name Funcion vacia.
		\fn virtual bool vacia()const.
		\brief Método que mira si en la lista hay donantes.
		\return true. Si la lista está vacía. false. Si en la lista hay algún donante.
		\param Ninguno.
	*/
			bool vacia() const
			{
				if(l_.empty())
				{
					return true;
				}
				else return false;
			}
							/*!
		\name Funcion tamaño.
		\fn int tam().
		\brief Método que devuelve el número de donantes que hay en la lista.
		\return tamanio_. Tipo INT.
		\param Ninguno.
	*/
			int tam()
			{
				tamanio_=l_.tama();
				return tamanio_;
			}

	};

}

#endif






