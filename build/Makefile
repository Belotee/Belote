# Compiler
CXX = g++

# Target
TARGET = Belote

# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = ../src/Belote.cpp ../src/menu.cpp ../src/main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build the target
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(SFML_LIBS) # Links the object files and SFML libraries

# Compile source files into object files
%.o: %.cpp
	$(CXX) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET) # Removes object files and the executable

.PHONY: clean