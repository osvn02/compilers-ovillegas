#include "STORE.hpp"

STORE::STORE() : Instruction()
{
    address = 0;
}

STORE::STORE(string theName, int theCode, int theLength, int theAddress)
    : Instruction(theName, theCode, theLength)
{
    address = theAddress;
}

int STORE::getAddress()
{
    return address;
}
