#ifndef STORE_HPP
#define STORE_HPP

#include "Instruction.hpp"
#include <string>

using namespace std;

class STORE: public Instruction 
{
    private:
        int address;
        
    public:
        STORE();
        STORE(string theName, int theCode, int theLength, int theAddress);
        int getAddress();
};

#endif
