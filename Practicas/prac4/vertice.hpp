#ifndef vertice_hpp
#define vertice_hpp
#include <cassert>
#include <string>

using std::string;
namespace ed
{
	class Vertice
	{
		private:
			string data_;//Ciudad
			int label_;//Nñumero identificador de cada ciudad
		public:
			Vertice();
			inline string getData()const{return data_;} ;
			inline void setData(string data)
			{			
				data_=data;
			};

			inline int getLabel()const{return label_;} ;
			inline void setLabel(int label)
			{			
				label_=label;
			};

			bool operator == (Vertice v)
			{
				if(getData()==v.getData())
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			bool operator != (Vertice v)
			{
				if(getData() !=v .getData())
				{
					return true;
				}
				else return false;
			}

				
	};
			
}
#endif