# Nombre del archivo fuente
SOURCE = main.cpp

# Nombre del ejecutable
EXECUTABLE = main

# Compilador a usar
CC = g++

# Flags para el compilador
CFLAGS = -Wall -Wextra -std=c++11

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCE)

run: $(EXECUTABLE)
	clear
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean

# avoid closing the terminal after execution
.SILENT: run