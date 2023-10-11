# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -Wall -std=c++11

# Define the executable name
EXEC = 2.3

# Define the source files
SRCS = main.cpp BST/BST.cpp

# Define the object files
OBJS = $(addprefix output/, $(notdir $(SRCS:.cpp=.o)))

# Rule to create the output folder if it doesn't exist
output:
ifeq ($(OS),Windows_NT)
	if not exist output mkdir output
else
	mkdir -p output
endif

# Rule to compile the program
$(EXEC): output $(OBJS)
	$(CXX) $(CXXFLAGS) -o output/$(EXEC) $(OBJS)

# Rule to run the program
run: output $(EXEC)
	cls || clear
	output/$(EXEC)

# Rule to clean object files and the output folder
clean:
ifeq ($(OS),Windows_NT)
	del /Q /F $(subst /,\,$(OBJS)) output/$(EXEC)
	rmdir output
else
	rm -f $(OBJS) output/$(EXEC)
	rmdir output
endif

# Rule to compile object files
output/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<  -o $@

output/%.o: BST/%.cpp
	$(CXX) $(CXXFLAGS) -c $<  -o $@

.PHONY: clean run output
