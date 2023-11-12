# Definir el compilador
CXX = g++

# Definir las banderas del compilador
CXXFLAGS = -Wall -std=c++11

# Definir los archivos fuente
SRCS = Grafo/Grafo.cpp appGrafo.cpp

# Definir el nombre del ejecutable
EXEC = main

# Definir la ruta de salida
OUTDIR = output

# Regla por defecto
all: directories $(EXEC)

# Crear el directorio de salida si no existe
directories: $(OUTDIR)

$(OUTDIR):
ifeq ($(OS),Windows_NT)
	if not exist $(OUTDIR) mkdir $(OUTDIR)
else
	mkdir -p $(OUTDIR)
endif

# Regla para crear el ejecutable
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(OUTDIR)/$(EXEC) $(SRCS)

# Regla para ejecutar el programa
run: $(EXEC)
ifeq ($(OS),Windows_NT)
	$(OUTDIR)/$(EXEC)
else
	./$(OUTDIR)/$(EXEC)
endif

# Regla para limpiar los archivos de salida
clean:
ifeq ($(OS),Windows_NT)
	del /Q /F $(OUTDIR)/$(EXEC).exe
	rmdir $(OUTDIR)
else
	rm -rf $(OUTDIR)
endif
