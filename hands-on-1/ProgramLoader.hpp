#ifndef PROGRAMLOADER_HPP
#define PROGRAMLOADER_HPP

#include "Memory.hpp"
#include "Program.hpp"
#include <iostream>

using namespace std;

class ProgramLoader 
{
    public:
        ProgramLoader();
        void loadProgram(Program& program, Memory& memory);
        void displayLoadStatus(int instructionCount);
};

#endif

