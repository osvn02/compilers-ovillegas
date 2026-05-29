#ifndef REGISTERS_HPP
#define REGISTERS_HPP

#include <string>
#include <iostream>

using namespace std;

class Registers 
{
    private:
        // General Purpose Registers
        int AL;  // Accumulator Low
        int AH;  // Accumulator High
        int BL;  // Base Low
        int BH;  // Base High
        
        // Special Purpose Registers
        int PC;  // Program Counter
        string IR;  // Instruction Register
        int ACC; // Accumulator
        int MAR; // Memory Address Register
        int MBR; // Memory Buffer Register
        
    public:
        Registers();
        
        // Getters for General Purpose Registers
        int getAL();
        int getAH();
        int getBL();
        int getBH();
        
        // Setters for General Purpose Registers
        void setAL(int value);
        void setAH(int value);
        void setBL(int value);
        void setBH(int value);
        
        // Getters for Special Purpose Registers
        int getPC();
        string getIR();
        int getACC();
        int getMAR();
        int getMBR();
        
        // Setters for Special Purpose Registers
        void setPC(int value);
        void setIR(string value);
        void setACC(int value);
        void setMAR(int value);
        void setMBR(int value);
        
        // Utility methods
        void incrementPC();
        void reset();
        void displayAll();
};

#endif


