#Fichero makefile

#Macros:

CPPFLAGS = -g -Wall -ansi  
#El wall es para que te ponga los warning, ansi para ver si está escrito correctamente

G+ =g++
RUTA = main.cpp
OBJETO = main.o


#Creamos los ficheros objeto.
all: 
	clear
	@echo "Ceando los ficheros objeto..."
	$(G+) -c $(RUTA)
	$(G+) $(CPPFLAGS) -o donante $(OBJETO) 

	ls -l
#Creamos la configuración de doxygen
doxy: 
	@echo "Creando la configuración para el doxygen..."
	doxygen -g config

#Borramos los ficheros objeto
clean:
	clear
	@echo "Borrando los fichero objeto..."
	rm -f $(OBJETO)
	
	ls -l

#Borrado completo
allclean:
	clear
	@echo "Borrando todos los archivos Doxygen y Objetos creados..."
	rm -f $(OBJETO)
	rm -fr latex
	rm -f *.gch
	ls -l