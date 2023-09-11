# Definir el compilador
CXX = g++

# Definir las banderas del compilador
CXXFLAGS = -Wall -std=c++11

# Definir los archivos objeto
OBJ = output/main.o output/OrdenaBurbuja.o output/OrdenaIntercambio.o output/OrdenaMerge.o output/BusquedaSecuencial.o output/BusquedaBinaria.o

# Regla por defecto
all: main run

# Reglas para los archivos objeto
output/main.o: main.cpp ordenamiento/OrdenaBurbuja.h ordenamiento/OrdenaIntercambio.h ordenamiento/OrdenaMerge.h busqueda/BusquedaSecuencial.h busqueda/BusquedaBinaria.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o output/main.o

output/OrdenaBurbuja.o: ordenamiento/OrdenaBurbuja.cpp ordenamiento/OrdenaBurbuja.h
	$(CXX) $(CXXFLAGS) -c ordenamiento/OrdenaBurbuja.cpp -o output/OrdenaBurbuja.o

output/OrdenaIntercambio.o: ordenamiento/OrdenaIntercambio.cpp ordenamiento/OrdenaIntercambio.h
	$(CXX) $(CXXFLAGS) -c ordenamiento/OrdenaIntercambio.cpp -o output/OrdenaIntercambio.o

output/OrdenaMerge.o: ordenamiento/OrdenaMerge.cpp ordenamiento/OrdenaMerge.h
	$(CXX) $(CXXFLAGS) -c ordenamiento/OrdenaMerge.cpp -o output/OrdenaMerge.o

output/BusquedaSecuencial.o: busqueda/BusquedaSecuencial.cpp busqueda/BusquedaSecuencial.h
	$(CXX) $(CXXFLAGS) -c busqueda/BusquedaSecuencial.cpp -o output/BusquedaSecuencial.o

output/BusquedaBinaria.o: busqueda/BusquedaBinaria.cpp busqueda/BusquedaBinaria.h
	$(CXX) $(CXXFLAGS) -c busqueda/BusquedaBinaria.cpp -o output/BusquedaBinaria.o

# Regla para el ejecutable
main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o main $(OBJ)

# Regla para ejecutar el programa
run: main
	./main

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	rm -f output/*.o main
