/*!
	\file donante.hpp
	\brief Programa para realizar las funciones correspondientes de un Donante. 
*/

/*!
	\author Juan José Méndez Torrero
	\date 07/04/2016
*/



#ifndef donante_hpp
#define donante_hpp
#include "DonanteInterfaz.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
/*!
	\brief Espacio de nombre para la asginatura de ED.
*/
namespace ed
{
		class Donante: public DonanteInterfaz
	{
		private:
			string nombre_;//Nombre de un donante.
			string apellidos_;//Apellido de un donante.
			string grupo_;//Grupo sanguineo del donante. Posibilidades: 0,A,B,AB.
			string factor_;//Factor del donante. Posibilidades: positivo-negativo
		public:
		/*!
			\name Constructor de la clase Donante.
			\fn Donante(string nombre="", string apellidos="", string grupo="0", string factor="positivo").
			\brief Funcion que declara las variables por defecto.
			\return Ninguno.
			\param nombre. Tipo string.
			\param apellidos. Tipo string.
			\param grupo. Tipo string.
			\param factor. Tipo string.
		*/
			Donante(string nombre="", string apellidos="", string grupo="0", string factor="positivo")
			{
				nombre_=nombre;
				apellidos_=apellidos;
				if(grupo =="0" || grupo =="A" || grupo =="B" || grupo =="AB")
				{
					grupo_="0";
				}
				else grupo_=grupo;
				
				if(factor=="positivo" || factor=="negativo")
				{
					factor_="positivo";
				}
				else factor_=factor;
			}
				/*!
			\name Constructor de la clase Donante.
			\fn Donante(string nombre="", string apellidos="", string grupo="0", string factor="positivo").
			\brief Funcion que declara las variables por copia.
			\return Ninguno.
			\param d. Tipo Donante.
			
		*/
			Donante(const Donante &d)
			{
				nombre_=d.nombre_;
				apellidos_=d.apellidos_;
				grupo_=d.grupo_;
				factor_=d.factor_;
			}
				/*!
		\name Funcion Observadora del nombre.
		\fn inline string getNombre()const{return nombre_;}.
		\brief Método que devuelve el nombre del donante.
		\return Nombre del donante de tipo STRING.
		\param Ninguno.
	*/
			inline string getNombre()const{return nombre_;};
	/*!
		\name Funcion Modificadora del nombre.
		\fn inline void setNombre( string nombre){nombre_=nombre;}.
		\brief Método que modifica el nombre del donante.
		\return Ninguno.
		\param nombre de tipo string.
	*/
			inline void setNombre(string nombre){nombre_=nombre;};

	/*!
		\name Funcion Observadora del apellido.
		\fn inline string getApellidos()const{return apellidos_;}.
		\brief Método que devuelve el apellido del donante.
		\return Apellido del donante de tipo STRING.
		\param Ninguno.
	*/
			inline string getApellidos()const{return apellidos_;} ;
					/*!
		\name Funcion Modificadora del Apellido.
		\fn inline void setApellidos( string apellidos){apellidos_=apellidos;}.
		\brief Método que modifica el Apellido del donante.
		\return Ninguno.
		\param apellido de tipo string.
	*/
			inline void setApellidos(string apellidos){apellidos_=apellidos;};
					/*!
		\name Funcion Observadora del Grupo.
		\fn inline string getGrupo()const{return grupo_;} .
		\brief Método que devuelve el Grupo del donante.
		\return Grupo del donante de tipo STRING.
		\param Ninguno.
	*/
			inline string getGrupo()const{return grupo_;} ;
						/*!
		\name Funcion Modificadora del Grupo.
		\fn inline void setGrupo(string grupo).
		\brief Método que modifica el Grupo del donante.
		\return Ninguno.
		\param grupo de tipo string.
	*/
			inline void setGrupo(string grupo)
			{			
				if(grupo =="0" || grupo =="A" || grupo =="B" || grupo =="AB")
				{
					grupo_=grupo;
				}
			};
/*!
		\name Funcion Observadora del Factor.
		\fn inline string getFactor()const{return factor_;} .
		\brief Método que devuelve el Factor del donante.
		\return Factor del donante de tipo STRING.
		\param Ninguno.
	*/
			inline string getFactor()const{return factor_;} ;
					/*!
		\name Funcion Modificadora del Factor.
		\fn inline void setFactor(string factor).
		\brief Método que modifica el Factor del donante.
		\return Ninguno.
		\param factor de tipo string.
	*/
			inline void setFactor(string factor)
			{			
				if(factor=="positivo" || factor=="negativo")
				{
					factor_=factor;
				}
				
			}
	/*!
		\name Función para leer un donante.
		\fn void leerDonante().
		\brief Función que lee un donante por teclado.
		\return Ninguno.
		\param Ninguno.
	*/
			void leerDonante()
			{
				string g,f;
				char n[256], a[256];

				cout<<"Introduzca su nombre:"<<endl;
				getchar();
				cin.getline(n,256);
				setNombre(n);
				cout<<"Introduzca sus apellidos:"<<endl;
				cin.getline(a,256);
				setApellidos(a);
				cout<<"Introduzca el tipo de grupo sanguineo:"<<endl;
				cin>>g;
				setGrupo(g);
				cout<<"Introduzca el factor RH"<<endl;
				cin>>f;
				setFactor(f);
			}
	/*!
		\name Función para imprimir un donante.
		\fn void imprimirDonante().
		\brief Función que imprime un donante por pantalla.
		\return Ninguno.
		\param Ninguno.
	*/
			void imprimirDonante()
			{
				cout<<"-----------------------------"<<endl;
				cout<<"Nombre:"<<nombre_<<endl;
				cout<<"Apellidos:"<<apellidos_<<endl;
				cout<<"Grupo:"<<grupo_<<endl;
				cout<<"Factor:"<<factor_<<endl;
				cout<<"-----------------------------"<<endl;
			}
	/*!
		\name Operador =.
		\fn Donante operator = (Donante d).
		\brief Sobrecarga del operador = para la lectura de un donante.
		\return *this.
		\param d. Tipo Donante.
	*/
			Donante operator = (Donante d)
			{
				nombre_=d.nombre_;
				apellidos_=d.apellidos_;
				grupo_=d.grupo_;
				factor_=d.factor_;

				return *this;
			}
	/*!
		\name Operador ==.
		\fn bool operator == (Donante d).
		\brief Sobrecarga del operador == para la comparación entre dos donantes.
		\return true. Si son iguales. false. Si no son iguales.
		\param d. Tipo Donante.
	*/
			bool operator == (Donante d)
			{
				if(getNombre()==d.getNombre() && getApellidos()== d.getApellidos())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
	/*!
		\name Operador <=.
		\fn bool operator <= (Donante d).
		\brief Sobrecarga del operador <= para la comparación lexicográfica entre dos donantes.
		\return true. Si son el donante introducido es mayor. false. Si el donante con el que comprarar es mayor.
		\param d. Tipo Donante.
	*/
			bool operator <=(Donante d)
			{
				if(getApellidos()>d.getApellidos())
				{
					return false;
				}
				else if(getApellidos()<d.getApellidos())
				{
					return true;
				}
				else//Los apellidos son iguales
				{
					if(getNombre()>d.getNombre())
					{
						return false;
					}
					else
					{
						return true;
					}
				}
			}
	/*!
		\name Operador >>.
		\fn friend istream &operator>>(istream &stream, Donante &d).
		\brief Sobrecarga del operador >> para que lea un donante por teclado.
		\return stream. Tipo stream
		\param stream. Tipo stream.
		\param d. Tipo Donante.
	*/
			friend istream &operator>>(istream &stream, Donante &d)
			{
				string g,f;
				char n[256], a[256];
				cout<<"Introduzca su nombre:"<<endl;
				getchar();
				stream.getline(n,256);
				d.setNombre(n);
				cout<<"Introduzca sus apellidos:"<<endl;
				stream.getline(a,256);
				d.setApellidos(a);
				cout<<"Introduzca el tipo de grupo sanguineo:"<<endl;
				stream>>g;
				d.setGrupo(g);
				cout<<"Introduzca el factor RH"<<endl;
				stream>>f;
				d.setFactor(f);
				return stream;
			}
/*!
		\name Operador >>.
		\fn friend ostream &operator<<(ostream &stream, Donante d).
		\brief Sobrecarga del operador << para que imprima un donante por pantalla.
		\return stream. Tipo stream
		\param stream. Tipo stream.
		\param d. Tipo Donante.
	*/
			friend ostream &operator<<(ostream &stream, Donante d)
			{
				cout<<"-----------------------------"<<endl;
				stream<<"Nombre:"<<d.getNombre()<<endl;
				stream<<"Apellidos:"<<d.getApellidos()<<endl;
				stream<<"Grupo:"<<d.getGrupo()<<endl;
				stream<<"Factor:"<<d.getFactor()<<endl;
				return stream;
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
				do
				{
	               op=ini();
	               switch(op)
	               {
	                        case 1:
	                        cout<<"Introduce nuevo nombre: "<<endl;
	                        cin.ignore();
	                        cin.getline(cad,256);
	                        setNombre(cad);
	                        break;
	                        case 2:
	                        cout<<"Introduce nuevos apellidos: "<<endl;
	                        cin.ignore();
	                        cin.getline(cad2,256);
	                        setApellidos(cad2);
	                        break;
	                        case 3:
	                        cout<<"Introduce nuevo grupo sanguineo: "<<endl;
	                        cin>>n;
	                        setGrupo(n);
	                        break;
	                        case 4:
	                        cout<<"Introduce nuevo RH: "<<endl;
	                        cin>>n;
	                        setFactor(n);
	                        break;
	                        case 5:
	                        cout<<"Ha elegido no modificar más"<<endl;
	                        break;                        
	               }
	            }while(op!=5);
	                   
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
	            int x;
	            system("clear");
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
		
	};
}


#endif