#include "Program.hpp"

Program::Program()
{
	for (int i = 0; i < 10; i++) {
		instructions[i] = nullptr;
	}
}

Program::~Program()
{
	// Instructions are managed by caller, don't delete here
}

void Program::addInstruction(Instruction* theInstruction, int thePosition)
{
	if (thePosition >= 0 && thePosition < 10) {
		instructions[thePosition] = theInstruction;
	}
}

Instruction* Program::getInstruction(int thePosition)
{
	if (thePosition >= 0 && thePosition < 10) {
		return instructions[thePosition];
	}
	return nullptr;
}

