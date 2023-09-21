# Source files
SOURCES = main.cpp ordenamiento/OrdenamientoBuques.cpp busqueda/BusquedaBuques.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE = main

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	clear
ifeq ($(OS),Windows_NT)
	$(EXECUTABLE)
else
	./$(EXECUTABLE)
endif

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all run clean
