#ifndef ALU_HPP
#define ALU_HPP

class ALU
{
	private:
		short int operand1;
		short int operand2;

	public:
		ALU();
		ALU(short int theOperand1, short int theOperand2);
		int add(int theOperand1, int theOperand2);
		int subtract(int theOperand1, int theOperand2);
		int multiply(int theOperand1, int theOperand2);
		int divide(int theOperand1, int theOperand2);
};

#endif

