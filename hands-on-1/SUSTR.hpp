#ifndef SUSTR_HPP
#define SUSTR_HPP

#include "Instruction.hpp"
#include <string>

using namespace std;

class SUSTR: public Instruction 
{
    private:
        int operand1;
        int operand2;
        
    public:
        SUSTR();
        SUSTR(string theName, int theCode, int theLength, int theOperand1, int theOperand2);
        int getOperand1();
        int getOperand2();
};

#endif

