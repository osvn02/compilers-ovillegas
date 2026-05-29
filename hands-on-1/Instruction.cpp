#include "Instruction.hpp"
#include <iostream>

Instruction::Instruction() {}


Instruction::Instruction(string theName, short int theCode, short int theLength)
{
	name = theName;
	code = theCode;
	length = theLength;
}

Instruction::~Instruction() {}

void Instruction::display()
{
	cout << name <<"," << code << "," << length << endl;
}

int Instruction::getCode()
{
	return code;
}

string Instruction::getName()
{
	return name;
}





