#include "ProgramLoader.hpp"

ProgramLoader::ProgramLoader() {}

void ProgramLoader::loadProgram(Program& program, Memory& memory)
{
    cout << "\n=== LOADING PROGRAM INTO MEMORY ===" << endl;
    
    int instructionCount = 0;
    for (int i = 0; i < 10; i++) {
        Instruction* inst = program.getInstruction(i);
        if (inst != nullptr && inst->getCode() != 0) {
            // Store the instruction pointer directly in memory
            memory.storeInstruction(inst, i);
            cout << "Loaded instruction at address " << i << ": " << inst->getName() << endl;
            instructionCount++;
        }
    }
    
    displayLoadStatus(instructionCount);
}

void ProgramLoader::displayLoadStatus(int instructionCount)
{
    cout << "\nProgram loaded successfully!" << endl;
    cout << "Total instructions loaded: " << instructionCount << endl;
    cout << "===================================\n" << endl;
}

