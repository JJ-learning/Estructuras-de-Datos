/*!
	\file monticulo.hpp
	\brief Programa para realizar las funciones correspondientes de un monticulo. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 26/04/2016
*/
#ifndef monticulo_hpp
#define monticulo_hpp

#include "monticuloInterfaz.hpp"

/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
namespace ed
{

	class Monticulo : public ed::MonticuloInterfaz 
	{

		private:
			
			vector<Donante> v_;//!<Vector de donantes.
		/*!
		\name Funcion hijo izquierdo.
		\fn int leftChild(int i).
		\brief Método que devuelve la posición en la que se encuentra el hijo izquierdo.
		\return i*2+1.
		\param i Tipo int.
	*/
			int leftChild(int i)
			{
				return i*2+1;
			}
					/*!
		\name Funcion hijo derecho.
		\fn int rightChild(int i).
		\brief Método que devuelve la posición en la que se encuentra el hijo derecho.
		\return i*2+2.
		\param i Tipo int.
	*/
			int rightChild(int i)
			{
				return i*2+2;
			}
					/*!
		\name Funcion padre.
		\fn int parent(int i).
		\brief Método que devuelve la posición en la que se encuentra el padre.
		\return (i-1)/2.
		\param i Tipo int.
	*/
			int parent(int i)
			{
				return (i-1)/2;
			}		
					/*!
		\name Funcion flotar.
		\fn void flotar(int i).
		\brief Método que flota un donante para colocarlo en su posición correcta.
		\return Ninguno.
		\param i Tipo int.
	*/
			void flotar(int i)
			{
				if((i>0) and (v_[i]<v_[parent(i)]))//Para no averiguar el padre de la raiz. Para que el padre nunca sea mayor que el hijo.
				{ 
					std::swap(v_[i],v_[parent(i)]);		
					flotar(parent(i));//llamada recursiva para comprobar que el padre es menor que el hijo				
				}
			}

	/*!
		\name Funcion flotar.
		\fn void hundir(int i).
		\brief Método que hunde un donante para colocarlo en su posición correcta.
		\return Ninguno.
		\param i Tipo int.
	*/
			void hundir(int i)
			{
				
				int n=i;

				int lc=leftChild(i);

				int rc=rightChild(i); 

				if((lc < v_.size()) and v_[lc] < v_[n])
				{
					n=lc;					
				}
				if((rc < v_.size()) and v_[rc]<v_[n])
				{
					n=rc;					
				}
				if(i!=n)
				{
					std::swap(v_[i],v_[n]);	
					hundir(n);					
				}	
			}
			/*!
		\name Funcion es último.
		\fn int isLast().
		\brief Método que devuelve la posición del último donante del montículo.
		\return v_.size()-1.
		*/
			int isLast()
			{
				return v_.size()-1;
			}
			

		public:	
			/*!
		\name Funcion cima.
		\fn Donante cima() const.
		\brief Método que devuelve el donante que se encuentra en la cima.
		\return v_.front() Donante que se encuentra en la primera posición del vector.
	*/		
			Donante cima() const
			{
				assert (!isEmpty());
				return v_.front();
			}
					/*!
		\name Funcion is empty.
		\fn bool isEmpty() const.
		\brief Método que si un montículo contiene datos o no.
		\return true si el monticulo está vacío, false si el montículo contiene donantes.
	*/
			bool isEmpty()const 
			{
				return v_.empty();
			}
								/*!
		\name Funcion find.
		\fn bool find(Donante d).
		\brief Método que devuelve si un donante exite o no.
		\return true si el donante existe, false si el donante no existe.
		\param d Tipo Donante.
	*/
			bool find(Donante d)
			{
				assert(!isEmpty());
			
				int i=0;

				while(i<isLast())
				{ 
					if(v_[i]==d)
					{
						return true;
					}
					i++;
				}
				return false;
			}
								/*!
		\name Funcion insertar.
		\fn void insertar(Donante d).
		\brief Método que inserta un donante en el montículo.
		\return Ninguno.
		\param d Tipo Donante.
	*/
			void insertar(Donante d)
			{
					
				if(isEmpty())
				{
					v_.push_back(d);
				}
				else
				{
					bool enc=find(d);
					if(not enc)
					{
						v_.push_back(d);
						flotar(isLast());
					}
					else cout<<"El donante insertado ya existe."<<endl;
				}
			}
					/*!
		\name Funcion cargar Donantes.
		\fn void cargarF(string nombreF).
		\brief Método que lee los donantes de un fichero.
		\return Ninguno.
		\param nombreF Tipo string.
	*/
			void cargarF(string nombreF)
			{

				ifstream entrada(nombreF.c_str());
				char nombre[50], apellidos[50], grupo[50], rh[50], donacion[50];				

				Donante d;

				while( entrada.getline(nombre,256,',') )
				{
					  entrada.getline(apellidos,256,',');
					  entrada.getline(grupo,256,',');
					  entrada.getline(rh,256,',');
					  entrada.getline(donacion,256,'\n');

					  d.setNombre(nombre);
					  d.setApellidos(apellidos);
					  d.setGrupo(grupo);
					  d.setFactor(rh);
				      d.setDonaciones(atoi(donacion));
					  insertar(d);
				}
				entrada.close();
			}
								/*!
		\name Funcion guardar Donantes.
		\fn void grabarF(string nombreF).
		\brief Método que guarda los donantes de un fichero.
		\return Ninguno.
		\param nombreF Tipo string.
	*/
			void grabarF(string nombreF)
			{

				ofstream salida(nombreF.c_str());
				Donante d;
				for(int i=0; i< v_.size(); i++){
				
				  	salida<<v_[i].getNombre()<<","<< v_[i].getApellidos()<<","<<v_[i].getGrupo()<<","<<v_[i].getFactor()<<","<<v_[i].getDonaciones()<<endl;
					 
				}
				salida.close();
			}
				/*!
		\name Función para imprimir un donante.
		\fn void mostrar().
		\brief Función que imprime el montículo de donantes por pantalla.
		\return Ninguno.

	*/
			void mostrar()
			{

				for(int i=0; i< v_.size(); i++){
				
				  	cout<<v_[i];
					 
				}
			}
										/*!
		\name Funcion remove.
		\fn void remove().
		\brief Método que borra la cima.
		\return Ninguno.
		\param d Tipo Donante.
	*/
			void remove()
			{
				assert(!isEmpty());
				if(isLast()>0)
				{
					v_[0]=v_[isLast()];
					v_.pop_back();
					hundir(0);
				}
				else if(isLast()==0)
				{
					v_.pop_back();
				}
			}
										/*!
		\name Funcion simular donaciones.
		\fn void simularDonaciones(int n).
		\brief Método que simula las donaciones.
		\return Ninguno.
		\param n Tipo int.
	*/
			void simularDonaciones(int n)
			{
				assert(not isEmpty());
				Donante d;

				for(int i=0;i<n;i++)
				{
					d=cima();
					remove(); //Borra la cima
					d.setDonaciones(d.getDonaciones()+1);
					insertar(d);
				}
			}
	};

}

#endif
