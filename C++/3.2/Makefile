# Definir el compilador
CXX = g++

# Definir las banderas de compilación
CXXFLAGS = -Wall -std=c++11

# Definir el nombre del ejecutable
EXEC = main

# Definir los archivos fuente
SRCS = main.cpp PriorityQueue/priority_queue.cpp

# Definir los archivos objeto
OBJS = $(addprefix output/, $(notdir $(SRCS:.cpp=.o)))

# Regla para crear la carpeta de salida
output:
ifeq ($(OS),Windows_NT)
	if not exist output mkdir output
else
	mkdir -p output
endif

# Regla para compilar el programa
$(EXEC): output $(OBJS)
	$(CXX) $(CXXFLAGS) -o output/$(EXEC) $(OBJS)

# Regla para ejecutar el programa
run: output $(EXEC)
	cls || clear
	output/$(EXEC)

# Regla para limpiar los archivos objeto y el ejecutable
clean:
ifeq ($(OS),Windows_NT)
	del /Q /F $(subst /,\,$(OBJS)) output/$(EXEC).exe
	rmdir output
else
	rm -f $(OBJS) output/$(EXEC)
	rmdir output
endif

# Regla para compilar los archivos fuente
output/%.o: %.cpp output
	$(CXX) $(CXXFLAGS) -c $<  -o $@

output/%.o: PriorityQueue/%.cpp output
	$(CXX) $(CXXFLAGS) -c $<  -o $@

.PHONY: clean run output
