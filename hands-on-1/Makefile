# Makefile for Virtual Machine Simulator

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wno-deprecated-register
TARGET = vm
SOURCES = Main.cpp \
          Instruction.cpp \
          InstructionSet.cpp \
          Program.cpp \
          MOV.cpp \
          ADD.cpp \
          SUSTR.cpp \
          MULT.cpp \
          DIV.cpp \
          STORE.cpp \
          CU.cpp \
          ALU.cpp \
          Registers.cpp \
          Memory.cpp \
          ProgramLoader.cpp \
          LexicalAnalyzer.cpp

OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build successful! Run with: ./$(TARGET)"

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete"

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run


