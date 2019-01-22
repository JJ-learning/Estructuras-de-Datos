#ifndef grafo_hpp
#define grafo_hpp
#include "lado.hpp"
#include <vector>

using std::vector;
namespace ed
{
	class Grafo
	{
		private:
			vector <Vertice> v_;//Vector de vertices donde almacenaré todas las ciudades con sus distintas etiquetas.
			double **m_;//Matriz de adyacencia del grafo
			bool dirigido_;//Variable donde almacenaremos si es dirigido o no. true si es dirigido. false si no.
			int a_;//Cursor para saber por donde vamos en el vector de vertices.
			int b_;//Cursor para saber por donde vamos en el vector de lador.
			int nvertices_;//Vector que dic eel número de vértices.
			int nlados_;//Numero de lados
			int capacidad_;//Capacidad de la matriz de adyacencia.
		public:
			Grafo(int capacidad=0, bool dirigido=true)
			{
				/*Para reservar memoria para la matriz de adyacencia*/
				assert(capacidad>0);
				m_=new double*[capacidad];
				for(int i=0;i<capacidad;i++)
				{
					m_[i]= new double[capacidad];
				}
				for(int i=0;i<capacidad;i++)
				{
					for(int j=0;j<capacidad;j++)
					{
						m_[i][j]=32000;//La inicializamos sin ninguna conexion
					}
				}
				nvertices_=0;
				nlados_=0;
				capacidad_=capacidad;
				dirigido_=dirigido;
			}

			inline int nVertices(){return nvertices_;};
			inline int nLados(){return nlados_;};
			inline int Capacidad(){return capacidad_;};

			bool isEmpty()
			{
				if(nVertices()==0 && nLados()==0)
				{
					return true;
				}
				else return false;
			}

			bool isDirected()
			{
				return dirigido_;
			}

			bool adyacent(Vertice u, Vertice v)
			{
				if(m_[u.getLabel()][v.getLabel()]==32000)
				{
					return false;
				}
				else return true;
			}

			bool hasCurVertex()
			{
				if(a_<nVertices())
				{
					return true;
				}
				else return false;
			}

			bool hasCurEdge()
			{
				if(b_<nLados())
				{
					return true;
				}
				else return false;
			}

			Vertice curVertice()
			{
				assert(hasCurVertex());
				return v_[a_];
			}

			Lado curLado()//Devuelve el lado diferenciado por los cursores
			{
				assert(hasCurEdge());

				Lado l;
				l.setDistancia(m_[a_][b_]);
				l.setInicio(v_[a_]);
				l.setDestino(v_[b_]);

				return l;
			}

			void makeDirected()
			{
				dirigido_=true;
			}

			void makeUndirected()
			{
				dirigido_=false;
			}

			void addVertex(string data)
			{
				Vertice v;
				v.setData(data);
				v.setLabel(nvertices_);
				nvertices_++;
				v_.push_back(v);
			}

			void addEdge(double distancia, Vertice u, Vertice v)
			{
				m_[u.getLabel()][v.getLabel()]=distancia;
				nlados_++;
				if(not isDirected())//Para poder rellenar la matriz de adyacencia
				{
					m_[v.getLabel()][u.getLabel()]=distancia;
				}
			}

			void buscarVertex(string data)//Posiciona el cursor en la etiqueta de esa ciudad
			{
				int enc=0, i;
				for(i=0;i<nVertices() && enc==0;i++)
				{
					if(v_[i].getData()==data)
					{
						a_=i;
						enc=1;
					}
				}
			}

			void goTo(Vertice v)//Lleva el cursor a ese vertice
			{
				assert(v.getLabel()<capacidad_);
				int enc=0, i;
				for(i=0;i<nVertices() && enc==0;i++)
				{
					if(v_[i]==v)
					{
						a_=i;
						enc=1;
					}
				}
			}

			void buscarEdge(Vertice u, Vertice v)
			{
				assert(u.getLabel()<nVertices());
				assert(v.getLabel()<nVertices());

				a_=u.getLabel();
				b_=v.getLabel();
			}

			void beginVertex()//Lleva el cursor al principio del vertice
			{
				a_=0;
			}

			Vertice beginVertexs()//Lleva el cursor al principio del vertice
			{
				return v_[0];
			}

			void nextVertex()//incrementa el cursor  del vertice
			{
				a_++;
			}

			Vertice nextVertexs()//Incrementa la posicion del vector
			{
				return v_[a_+1];
			}

			bool afterEndVertex()
			{
				if(a_==nVertices())
				{
					return true;
				}
				else return false;
			}

			void beginEdge(Vertice v)//Lleva el cursor al primer lado del vertice que recibes
			{
				a_= v.getLabel();
				b_=0;

				while(m_[a_][b_]==32000 and not afterEndEdge())
				{
					b_++;
				}
			}	

			Lado beginEdges(Vertice v)//Devuelve el primer lado que está conectado
			{
				a_= v.getLabel();
				b_=0;

				while(m_[a_][b_]==32000 and not afterEndedge())
				{
					b_++;
				}
				return m_[a_][b_];
			}				
	};					
			
}
#endif