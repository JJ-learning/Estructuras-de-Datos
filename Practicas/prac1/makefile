#Fichero makefile

#Macros:

CPPFLAGS = -g -Wall -ansi  
#El wall es para que te ponga los warning, ansi para ver si está escrito correctamente
MTH = -lm
G+ =g++
RUTA = main.cpp
RUTA2 = mainp.cpp
OBJETO = main.o
OBJETO2 = mainp.o

#Creamos los ficheros objeto.
all: 
	clear
	@echo "Ceando los ficheros objeto..."
	$(G+) -c $(RUTA)
	$(G+) -c $(RUTA2)
	$(G+) $(CPPFLAGS) -o monomio $(OBJETO) $(MTH)
	$(G+) $(CPPFLAGS) -o polinomio $(OBJETO2) $(MTH)
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
	rm -f $(OBJETO2)
	ls -l

#Borrado completo
allclean:
	clear
	@echo "Borrando todos los archivos Doxygen y Objetos creados..."
	rm -f $(OBJETO)
	rm -f $(OBJETO2)
	rm -fr html
	rm -fr latex
	rm -f config
	rm -f *.gch
	ls -l