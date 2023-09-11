# Definir el compilador
CXX = g++

# Definir las banderas del compilador
CXXFLAGS = -Wall -std=c++11

# Definir los archivos objeto
OBJ = main.o OrdenaBurbuja.o

# Regla por defecto
all: main run

# Reglas para los archivos objeto
main.o: main.cpp OrdenaBurbuja.h BusquedaBinaria.h BusquedaSecuencial.h OrdenaIntercambio.h OrdenaMerge.h
	$(CXX) $(CXXFLAGS) -c main.cpp

OrdenaBurbuja.o: OrdenaBurbuja.cpp OrdenaBurbuja.h
	$(CXX) $(CXXFLAGS) -c OrdenaBurbuja.cpp

# Regla para el ejecutable
main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o main $(OBJ)

# Regla para ejecutar el programa
run:
	./main

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	rm -f *.o main
