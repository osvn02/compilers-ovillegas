#ifndef MULT_HPP
#define MULT_HPP

#include "Instruction.hpp"
#include <string>

using namespace std;

class MULT: public Instruction 
{
    private:
        int operand1;
        int operand2;
        
    public:
        MULT();
        MULT(string theName, int theCode, int theLength, int theOperand1, int theOperand2);
        int getOperand1();
        int getOperand2();
};

#endif


