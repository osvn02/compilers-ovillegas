#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <string>
#include <iostream>
#include "Instruction.hpp"

using namespace std;

class Memory 
{
    private:
        static const int MEMORY_SIZE = 256;
        Instruction* memory[MEMORY_SIZE];
        int data[MEMORY_SIZE];  // For storing data values
        
    public:
        Memory();
        ~Memory();
        
        // Instruction memory operations
        void storeInstruction(Instruction* instruction, int address);
        Instruction* loadInstruction(int address);
        
        // Data memory operations
        void storeData(int value, int address);
        int loadData(int address);
        
        // Utility methods
        void clear();
        void displayMemory(int start, int end);
        bool isValidAddress(int address);
};

#endif


