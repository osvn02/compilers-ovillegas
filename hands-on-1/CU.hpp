#ifndef CU_HPP
#define CU_HPP
#include <string>
#include <iostream>
#include "Instruction.hpp"
#include "ALU.hpp"
#include "ADD.hpp"
#include "SUSTR.hpp"
#include "MULT.hpp"
#include "DIV.hpp"
#include "STORE.hpp"
#include "MOV.hpp"
#include "Program.hpp"
#include "Memory.hpp"
#include "Registers.hpp"

using namespace std;
class CU
{
	private:
		string status;
		ALU alu;
		Registers* registers;
		Memory* memory;

	public:
		CU();
		CU(Registers* regs, Memory* mem);
		
		// Machine Cycle methods
		Instruction* fetch(Memory* memory, int address);
		int decode(Instruction* theInstruction);
		void execute(Instruction* theInstruction, Registers* registers, Memory* memory);
		
		// Display methods
		void displayFetchState(int pc);
		void displayDecodeState(string instructionName, int opcode);
		void displayExecuteState(string operation);
};
#endif
