# Definir el compilador
CXX = g++

# Definir los archivos de origen y de salida
SRC = main.cpp Fila/Fila.cpp Pila/Pila.cpp
OBJ = $(SRC:.cpp=.o)
OUT = programa

# Reglas para compilar el programa
all: $(OUT) run

$(OUT): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -c $<

# Regla para ejecutar el programa
run: $(OUT)
	./$(OUT)

# Regla para limpiar los archivos generados durante la compilación
clean:
	rm -f $(OBJ) $(OUT)
