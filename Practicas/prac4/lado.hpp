#ifndef lado_hpp
#define lado_hpp
#include "vertice.hpp"

namespace ed
{
	class Lado
	{
		private:
			Vertice inicio_;//Ciudad donde empieza
			Vertice destino_;//Ciudad destino
			double distancia_;//Distancia de una ciudad a otra
		public:
			Lado();

			inline Vertice getInicio()const{return inicio_;} ;
			inline void setInicio(Vertice inicio)
			{			
				inicio_=inicio;
			};

			inline Vertice getDestino()const{return destino_;} ;
			inline void setDestino(Vertice destino)
			{			
				destino_=destino;
			};

			inline double getDistancia()const{return distancia_;} ;
			inline void setDistancia(double distancia)
			{			
				distancia_=distancia;
			};

			bool has(Vertice u)
			{
				if(u==getInicio() or u==getDestino())
				{
					return true;
				}
				else return false;
			}

			Vertice other(Vertice u)//Funciones para ver si tiene algún vertice conectado con el
			{
				assert(has(u));

				if(u==getInicio())
				{
					return getDestino();
				}
				else return getInicio();	
			}

			bool operator == (Lado l)
			{
				if(getInicio()==l.getInicio() && getDestino()==l.getDestino())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
				
	};
			
}

#endif