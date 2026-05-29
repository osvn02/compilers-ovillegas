#include <stdlib.h>
#include <iostream>

#include "Instruction.hpp"
#include "InstructionSet.hpp"
#include "Program.hpp"
#include "MOV.hpp"
#include "CU.hpp"
#include "ADD.hpp"
#include "SUSTR.hpp"
#include "MULT.hpp"
#include "DIV.hpp"
#include "STORE.hpp"
#include "Registers.hpp"
#include "Memory.hpp"
#include "ProgramLoader.hpp"
#include "LexicalAnalyzer.hpp"

using namespace std;

void runMachineCycle(CU& cu, Memory& memory, Registers& registers, int programSize);
void demonstrateLexicalAnalysis();

int main(void)
{
    cout << "╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║          VIRTUAL MACHINE SIMULATOR                        ║" << endl;
    cout << "║          Complete Implementation                          ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝\n" << endl;

    // Initialize VM components
    Registers registers;
    Memory memory;
    CU controlUnit(&registers, &memory);
    ProgramLoader loader;
    LexicalAnalyzer lexer;

    cout << "=== INITIALIZING VIRTUAL MACHINE ===" << endl;
    cout << "Registers initialized" << endl;
    cout << "Memory initialized (256 addresses)" << endl;
    cout << "Control Unit initialized" << endl;
    cout << "Program Loader ready\n" << endl;

    // Demonstrate Lexical Analysis
    demonstrateLexicalAnalysis();

    // Create a sample program
    cout << "\n=== CREATING SAMPLE PROGRAM ===" << endl;
    
    Program program;
    
    // Instruction 0: START
    Instruction* start = new Instruction("START", 50, 0);
    program.addInstruction(start, 0);
    cout << "Added: START" << endl;
    
    // Instruction 1: ADD 15, 25 (15 + 25 = 40)
    ADD* add1 = new ADD("ADD", 80, 2, 15, 25);
    program.addInstruction(add1, 1);
    cout << "Added: ADD 15, 25" << endl;
    
    // Instruction 2: STORE result at address 100
    STORE* store1 = new STORE("STORE", 90, 1, 100);
    program.addInstruction(store1, 2);
    cout << "Added: STORE 100" << endl;
    
    // Instruction 3: MULT 6, 7 (6 * 7 = 42)
    MULT* mult1 = new MULT("MULT", 82, 2, 6, 7);
    program.addInstruction(mult1, 3);
    cout << "Added: MULT 6, 7" << endl;
    
    // Instruction 4: STORE result at address 101
    STORE* store2 = new STORE("STORE", 90, 1, 101);
    program.addInstruction(store2, 4);
    cout << "Added: STORE 101" << endl;
    
    // Instruction 5: SUSTR 50, 20 (50 - 20 = 30)
    SUSTR* sub1 = new SUSTR("SUSTR", 81, 2, 50, 20);
    program.addInstruction(sub1, 5);
    cout << "Added: SUSTR 50, 20" << endl;
    
    // Instruction 6: DIV 100, 4 (100 / 4 = 25)
    DIV* div1 = new DIV("DIV", 83, 2, 100, 4);
    program.addInstruction(div1, 6);
    cout << "Added: DIV 100, 4" << endl;
    
    // Instruction 7: STOP
    Instruction* stop = new Instruction("STOP", 51, 0);
    program.addInstruction(stop, 7);
    cout << "Added: STOP" << endl;

    int programSize = 8;

    // Load program into memory
    loader.loadProgram(program, memory);

    // Display initial register state
    cout << "\n=== INITIAL STATE ===" << endl;
    registers.displayAll();

    // Run the machine cycle
    cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║              STARTING MACHINE CYCLE                       ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    
    runMachineCycle(controlUnit, memory, registers, programSize);

    // Display final state
    cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║              FINAL STATE                                  ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    
    registers.displayAll();
    
    // Display memory contents where results were stored
    cout << "\n=== STORED RESULTS IN MEMORY ===" << endl;
    cout << "Memory[100] = " << memory.loadData(100) << " (Result of ADD 15, 25)" << endl;
    cout << "Memory[101] = " << memory.loadData(101) << " (Result of MULT 6, 7)" << endl;

    cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║          VIRTUAL MACHINE EXECUTION COMPLETED              ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;

    // Cleanup
    delete start;
    delete add1;
    delete store1;
    delete mult1;
    delete store2;
    delete sub1;
    delete div1;
    delete stop;

    return EXIT_SUCCESS;
}

void runMachineCycle(CU& cu, Memory& memory, Registers& registers, int programSize)
{
    registers.setPC(0);
    
    while (registers.getPC() < programSize) {
        int pc = registers.getPC();
        
        cout << "\n" << string(60, '=') << endl;
        cout << "MACHINE CYCLE - Instruction " << pc << endl;
        cout << string(60, '=') << endl;
        
        // FETCH
        Instruction* instruction = cu.fetch(&memory, pc);
        
        if (!instruction) {
            cout << "Error: Could not fetch instruction at PC = " << pc << endl;
            break;
        }
        
        // Display registers after FETCH
        registers.displayAll();
        
        // DECODE
        int opcode = cu.decode(instruction);
        
        // Display registers after DECODE
        registers.displayAll();
        
        // EXECUTE
        cu.execute(instruction, &registers, &memory);
        
        // Display registers after EXECUTE
        registers.displayAll();
        
        // Check if STOP instruction
        if (opcode == 51) {
            cout << "\nSTOP instruction encountered. Halting execution." << endl;
            break;
        }
        
        // Increment PC
        registers.incrementPC();
        
        cout << "\nPC incremented to: " << registers.getPC() << endl;
    }
}

void demonstrateLexicalAnalysis()
{
    cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║          LEXICAL ANALYSIS DEMONSTRATION                   ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    
    LexicalAnalyzer lexer;
    
    // Test instruction strings
    string instruction1 = "ADD 15, 25";
    string instruction2 = "MOVE AL, 100";
    string instruction3 = "STORE 200";
    
    cout << "\nAnalyzing: \"" << instruction1 << "\"" << endl;
    vector<Token> tokens1 = lexer.tokenize(instruction1);
    lexer.displayTokens(tokens1);
    
    cout << "Validation: " << (lexer.validateInstruction(instruction1) ? "VALID" : "INVALID") << endl;
    
    cout << "\nAnalyzing: \"" << instruction2 << "\"" << endl;
    vector<Token> tokens2 = lexer.tokenize(instruction2);
    lexer.displayTokens(tokens2);
    
    cout << "Validation: " << (lexer.validateInstruction(instruction2) ? "VALID" : "INVALID") << endl;
    
    cout << "\nAnalyzing: \"" << instruction3 << "\"" << endl;
    vector<Token> tokens3 = lexer.tokenize(instruction3);
    lexer.displayTokens(tokens3);
    
    cout << "Validation: " << (lexer.validateInstruction(instruction3) ? "VALID" : "INVALID") << endl;
}

// Made with 
