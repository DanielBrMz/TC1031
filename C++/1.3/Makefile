# Archivos fuente
SOURCES = main.cpp ordenamiento/OrdenamientoBuques.cpp busqueda/BusquedaBuques.cpp

# Archivos objeto
OBJECTS = $(addprefix output/, $(notdir $(SOURCES:.cpp=.o)))

# Nombre del ejecutable
EXECUTABLE = main

# Compilador
CC = g++

# Flags del compilador
CFLAGS = -Wall -Wextra -std=c++11

all: output $(EXECUTABLE)

output:
	mkdir -p output

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o output/$(EXECUTABLE) $(OBJECTS)

output/%.o: ordenamiento/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

output/%.o: busqueda/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

output/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	clear

ifeq ($(OS),Windows_NT)
	$(EXECUTABLE)
else
	./$(EXECUTABLE)
endif


clean:
	rm -f output/*.o $(EXECUTABLE)

<<<<<<< HEAD
.PHONY: all run clean

# avoid closing the terminal after execution
.SILENT: run
=======
.PHONY: all run clean output
>>>>>>> c37c633d74d0873fa371d57a4d7291d34d5fead0
