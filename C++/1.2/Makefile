# Definir el compilador
CXX = g++

# Definir las banderas del compilador
CXXFLAGS = -Wall -std=c++11

# Definir los archivos objeto
OBJ = main.o OrdenaBurbuja.o OrdenaIntercambio.o OrdenaMerge.o BusquedaSecuencial.o BusquedaBinaria.o

# Regla por defecto
all: main

# Reglas para los archivos objeto
main.o: main.cpp ordenamiento/OrdenaBurbuja.h ordenamiento/OrdenaIntercambio.h ordenamiento/OrdenaMerge.h busqueda/BusquedaSecuencial.h busqueda/BusquedaBinaria.h
	$(CXX) $(CXXFLAGS) -c main.cpp

OrdenaBurbuja.o: ordenamiento/OrdenaBurbuja.cpp ordenamiento/OrdenaBurbuja.h
	$(CXX) $(CXXFLAGS) -c ordenamiento/OrdenaBurbuja.cpp

OrdenaIntercambio.o: ordenamiento/OrdenaIntercambio.cpp ordenamiento/OrdenaIntercambio.h
	$(CXX) $(CXXFLAGS) -c ordenamiento/OrdenaIntercambio.cpp

OrdenaMerge.o: ordenamiento/OrdenaMerge.cpp ordenamiento/OrdenaMerge.h
	$(CXX) $(CXXFLAGS) -c ordenamiento/OrdenaMerge.cpp

BusquedaSecuencial.o: busqueda/BusquedaSecuencial.cpp busqueda/BusquedaSecuencial.h
	$(CXX) $(CXXFLAGS) -c busqueda/BusquedaSecuencial.cpp

BusquedaBinaria.o: busqueda/BusquedaBinaria.cpp busqueda/BusquedaBinaria.h
	$(CXX) $(CXXFLAGS) -c busqueda/BusquedaBinaria.cpp

# Regla para el ejecutable
main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o main $(OBJ)

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	rm -f *.o main
