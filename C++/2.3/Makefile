# Definir el compilador
CXX = g++

# Definir los flags del compilador
CXXFLAGS = -Wall -std=c++11

# Definir el nombre del ejecutable
EXEC = 2.3

# Definir los archivos fuente
SRCS = main.cpp ListaEnlazada/ListaEnlazada.cpp Barco/Barco.cpp

# Definir los archivos objeto
OBJS = $(addprefix output/, $(notdir $(SRCS:.cpp=.o)))

# Regla para crear la carpeta output si no existe
output:
	if not exist output mkdir output || mkdir -p output

# Regla para compilar el programa
$(EXEC): output $(OBJS)
	$(CXX) $(CXXFLAGS) -o output/$(EXEC) $(OBJS)

# Regla para ejecutar el programa
run: output $(EXEC)
	cls || clear
	output/$(EXEC)

# Regla para limpiar los archivos objeto y la carpeta output
clean:
	if [ -z "$$OS" ]; then rm -f $(OBJS) output/$(EXEC) && rmdir output; else del /Q /F $(subst /,\,$(OBJS)) output/$(EXEC) && rmdir output; fi

# Regla para compilar los archivos objeto
output/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<  -o $@

output/%.o: ListaEnlazada/%.cpp
	$(CXX) $(CXXFLAGS) -c $<  -o $@

output/%.o: Barco/%.cpp
	$(CXX) $(CXXFLAGS) -c $<  -o $@

.PHONY: clean run output
