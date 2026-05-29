#include "ALU.hpp"
#include <iostream>

using namespace std;

ALU::ALU() {}

ALU::ALU(short int theOperand1, short int theOperand2)
{
	operand1 = theOperand1;
	operand2 = theOperand2;
}

int ALU::add(int theOperand1, int theOperand2)
{
	return theOperand1 + theOperand2;
}

int ALU::subtract(int theOperand1, int theOperand2)
{
	return theOperand1 - theOperand2;
}

int ALU::multiply(int theOperand1, int theOperand2)
{
	return theOperand1 * theOperand2;
}

int ALU::divide(int theOperand1, int theOperand2)
{
	if (theOperand2 == 0) {
		cout << "Error: Division by zero!" << endl;
		return 0;
	}
	return theOperand1 / theOperand2;
}

