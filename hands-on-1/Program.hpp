
#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Instruction.hpp"
#include <string>

class Program
{
	private:
		Instruction* instructions[10];
		
	public:
		Program();
		~Program();
		void addInstruction(Instruction* theInstruction, int position);
		Instruction* getInstruction(int position);
};

#endif
