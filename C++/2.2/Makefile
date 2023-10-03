# Definir el compilador
CXX = g++

# Definir los archivos de origen y de salida
SRC = main.cpp Fila/Fila.cpp Pila/Pila.cpp
OBJ = $(addprefix $(OUT_DIR)/, $(SRC:.cpp=.o))
OUT_DIR = output
OUT = $(OUT_DIR)/programa

# Detect the Operating System
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname -s)
endif

# Reglas para compilar el programa
all: $(OUT) run

$(OUT): $(OBJ)
	$(CXX) -o $@ $^

$(OUT_DIR)/%.o: %.cpp
ifeq ($(detected_OS),Windows)
	mkdir $(dir $@)
else
	mkdir -p $(dir $@)
endif
	$(CXX) -c $< -o $@

# Regla para ejecutar el programa
run: $(OUT)
	./$(OUT)

# Regla para limpiar los archivos generados durante la compilación
clean:
	rm -f $(OBJ) $(OUT)
