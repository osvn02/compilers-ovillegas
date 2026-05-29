#include "Memory.hpp"

Memory::Memory() 
{
    clear();
}

Memory::~Memory()
{
    // Instructions are managed by Program, don't delete here
}

void Memory::storeInstruction(Instruction* instruction, int address) 
{
    if (isValidAddress(address)) {
        memory[address] = instruction;
    } else {
        cout << "Error: Invalid memory address " << address << endl;
    }
}

Instruction* Memory::loadInstruction(int address) 
{
    if (isValidAddress(address)) {
        return memory[address];
    } else {
        cout << "Error: Invalid memory address " << address << endl;
        return nullptr;
    }
}

void Memory::storeData(int value, int address) 
{
    if (isValidAddress(address)) {
        data[address] = value;
    } else {
        cout << "Error: Invalid memory address " << address << endl;
    }
}

int Memory::loadData(int address) 
{
    if (isValidAddress(address)) {
        return data[address];
    } else {
        cout << "Error: Invalid memory address " << address << endl;
        return 0;
    }
}

void Memory::clear() 
{
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = nullptr;
        data[i] = 0;
    }
}

void Memory::displayMemory(int start, int end) 
{
    cout << "\n=== MEMORY CONTENTS ===" << endl;
    for (int i = start; i <= end && i < MEMORY_SIZE; i++) {
        if (memory[i] != nullptr) {
            cout << "Address " << i << ": " << memory[i]->getName() << endl;
        }
        if (data[i] != 0) {
            cout << "Data[" << i << "]: " << data[i] << endl;
        }
    }
    cout << "======================" << endl;
}

bool Memory::isValidAddress(int address) 
{
    return address >= 0 && address < MEMORY_SIZE;
}


