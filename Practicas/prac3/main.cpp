#include "monticulo.hpp"
#include <time.h>

using namespace ed;
int main()
{
	Donante d;
	Monticulo m;
	string nombreF;
	clock_t start =clock();

	int op;
	system("clear");
	do
	{
		cout<<"Donantes 2.0"<<endl;
		cout<<"1. Comprobar si hay donantes."<<endl;
		cout<<"2. Cargar donantes en un fichero."<<endl;
		cout<<"3. Guardar donantes en un fichero."<<endl;
		cout<<"4. Añadir nuevos donantes."<<endl;
		cout<<"5. Simular donaciones."<<endl;
		cout<<"6. Mostrar los donantes."<<endl;
		cout<<"7. Mostrar el donante de la cima."<<endl;
		cout<<"8. Eliminar el donante de la cima."<<endl;
		cout<<"9. Salir del programa."<<endl;
		cout<<"Elige una opción:"<<endl;
		cin>>op;
		switch(op)
		{
			
			case 1:
				system("clear");
				if(m.isEmpty()==true)
				{
					cout<<"No hay donantes en estos momentos."<<endl;
				}
				else cout<<"Hay donantes en la lista."<<endl;
				break;
			
			case 2:
				system("clear");
				cout<<"Escribe el nombre del fichero donde quieres cargar los datos."<<endl;
				cin>> nombreF;
				m.cargarF(nombreF);
				break;	
			
			case 3:
				system("clear");
				cout<<"Escribe el nombre del fichero donde quieres cargar los datos."<<endl;
				cin>> nombreF;
				m.grabarF(nombreF);
				break;
		
			case 4:
				system("clear");
				d.leerDonante();
				m.insertar(d);
				break;
		
			case 5:
				system("clear");
				int don;
				cout<<"Introduce el número de donaciones"<<endl;
				cin>>don;
				m.simularDonaciones(don);
				printf("Tiempo transcurrido %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
				break;
		
			case 6:
				system("clear");
				m.mostrar();
				break;

			case 7:
				system("clear");
				cout<<m.cima();
				break;

			case 8:
				system("clear");
				m.remove();
				cout<<"El elemento de la cima está borrado"<<endl;
				break;
			
			default:
				system("clear");
				cout<<"Hasta la próxima!"<<endl;
				exit(0);
		}
	}while(op!=9);
	
}