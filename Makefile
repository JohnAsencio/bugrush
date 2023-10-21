# Define the C++ compiler and flags
CXX = g++

# Define the source file and the executable name
SRC = bugrush.cpp
EXE = bugrush

# Build the executable

all: $(EXE)

$(EXE): $(SRC)
	$(CXX) -g -Wall -o $(EXE) $(SRC)

# Clean the generated files
clean:
	rm -f $(EXE)

# Define a target to run the program
run: $(EXE)
	./$(EXE) $(FILENAME)
