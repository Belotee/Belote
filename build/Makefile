# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I../include  # Enable warnings and specify include directory

# Target executable
TARGET = Belote

# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Source files
SRCS = ../src/Functions.cpp \
       ../src/Table.cpp \
       ../src/Equipe.cpp \
       ../src/Joueur.cpp \
       ../src/Paquet_cartes.cpp \
       ../src/Button.cpp \
	   ../src/EllipseButton.cpp \
	   ../src/menu.cpp \
	   ../src/RectButton.cpp \
	   ../src/Carte.cpp \
       ../main.cpp \
	   



# Object files (store in build directory)
OBJS = $(SRCS:../src/%.cpp=build/%.o)

# Build the target
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(SFML_LIBS) 

# Compile source files into object files
build/%.o: ../src/%.cpp
	mkdir -p build  # Ensure the build directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf build $(TARGET) 

.PHONY: clean
