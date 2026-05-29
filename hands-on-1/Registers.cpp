#include "Registers.hpp"

Registers::Registers() 
{
    reset();
}

// Getters for General Purpose Registers
int Registers::getAL() { return AL; }
int Registers::getAH() { return AH; }
int Registers::getBL() { return BL; }
int Registers::getBH() { return BH; }

// Setters for General Purpose Registers
void Registers::setAL(int value) { AL = value; }
void Registers::setAH(int value) { AH = value; }
void Registers::setBL(int value) { BL = value; }
void Registers::setBH(int value) { BH = value; }

// Getters for Special Purpose Registers
int Registers::getPC() { return PC; }
string Registers::getIR() { return IR; }
int Registers::getACC() { return ACC; }
int Registers::getMAR() { return MAR; }
int Registers::getMBR() { return MBR; }

// Setters for Special Purpose Registers
void Registers::setPC(int value) { PC = value; }
void Registers::setIR(string value) { IR = value; }
void Registers::setACC(int value) { ACC = value; }
void Registers::setMAR(int value) { MAR = value; }
void Registers::setMBR(int value) { MBR = value; }

// Utility methods
void Registers::incrementPC() 
{
    PC++;
}

void Registers::reset() 
{
    AL = 0;
    AH = 0;
    BL = 0;
    BH = 0;
    PC = 0;
    IR = "";
    ACC = 0;
    MAR = 0;
    MBR = 0;
}

void Registers::displayAll() 
{
    cout << "\n=== REGISTER STATE ===" << endl;
    cout << "General Purpose Registers:" << endl;
    cout << "  AL: " << AL << endl;
    cout << "  AH: " << AH << endl;
    cout << "  BL: " << BL << endl;
    cout << "  BH: " << BH << endl;
    cout << "\nSpecial Purpose Registers:" << endl;
    cout << "  PC (Program Counter): " << PC << endl;
    cout << "  IR (Instruction Register): " << IR << endl;
    cout << "  ACC (Accumulator): " << ACC << endl;
    cout << "  MAR (Memory Address Register): " << MAR << endl;
    cout << "  MBR (Memory Buffer Register): " << MBR << endl;
    cout << "======================" << endl;
}


