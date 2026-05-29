# Virtual Machine Simulator - Complete Implementation

## Author Information

**Name**: Octavio Salvador Villegas Navarro  
**Email**: octavio.villegas7760@alumnos.udg.mx
**Student ID**: 221977608
**Course**: Compilers 


## Overview

This is a complete Virtual Machine (VM) simulator that implements all the requirements specified in the activity. The VM demonstrates fundamental computer architecture concepts including the fetch-decode-execute cycle, register management, memory operations, and instruction execution.

## Features Implemented

### Complete Instruction Set

The VM supports the following instructions:

| Instruction | Opcode | Arguments | Description |
|-------------|--------|-----------|-------------|
| START | 50 | 0 | Begin program execution |
| STOP | 51 | 0 | End program execution |
| ADD | 80 | 2 | Add two operands |
| SUSTR | 81 | 2 | Subtract two operands |
| MULT | 82 | 2 | Multiply two operands |
| DIV | 83 | 2 | Divide two operands |
| STORE | 90 | 1 | Store ACC value to memory address |
| MOV | 100 | 2 | Move value to register |

### Register System

**General Purpose Registers:**
- AL (Accumulator Low)
- AH (Accumulator High)
- BL (Base Low)
- BH (Base High)

**Special Purpose Registers:**
- PC (Program Counter) - Tracks current instruction
- IR (Instruction Register) - Holds current instruction name
- ACC (Accumulator) - Stores arithmetic operation results
- MAR (Memory Address Register) - Holds memory address being accessed
- MBR (Memory Buffer Register) - Holds data being transferred

### Memory System

- 256 addressable memory locations
- Separate instruction and data memory
- Memory validation and error handling

### Control Unit (CU)

Implements the complete machine cycle:

1. **FETCH Phase**
   - Retrieves instruction from memory at PC address
   - Updates MAR with current address
   - Loads instruction into IR
   - Updates MBR with opcode

2. **DECODE Phase**
   - Extracts opcode from instruction
   - Identifies instruction type
   - Prepares for execution

3. **EXECUTE Phase**
   - Performs the instruction operation
   - Updates registers (ACC for arithmetic operations)
   - Stores results in memory if needed
   - Displays operation details

### Arithmetic Logic Unit (ALU)

Supports four basic operations:
- Addition
- Subtraction
- Multiplication
- Division (with zero-division protection)

### Program Loader

- Loads programs from Program object into Memory
- Validates instruction placement
- Reports loading status

### Lexical Analyzer

Validates instruction syntax by tokenizing input:

**Token Types:**
- KEYWORD (reserved words: START, STOP, ADD, etc.)
- IDENTIFIER (variable names, register names)
- DIGIT (numeric values)
- DELIMITER (`,`, `;`, spaces)

**Validation:**
- Ensures instructions start with keywords
- Detects unknown tokens
- Provides detailed token analysis

## Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    Virtual Machine                       │
├─────────────────────────────────────────────────────────┤
│                                                          │
│  ┌──────────────┐      ┌──────────────┐                │
│  │   Registers  │      │    Memory    │                │
│  │  (9 total)   │      │  (256 addr)  │                │
│  └──────────────┘      └──────────────┘                │
│         ▲                      ▲                         │
│         │                      │                         │
│         └──────────┬───────────┘                         │
│                    │                                     │
│         ┌──────────▼──────────┐                         │
│         │   Control Unit (CU)  │                         │
│         │  - Fetch             │                         │
│         │  - Decode            │                         │
│         │  - Execute           │                         │
│         └──────────┬───────────┘                         │
│                    │                                     │
│         ┌──────────▼──────────┐                         │
│         │        ALU           │                         │
│         │  - Add, Sub          │                         │
│         │  - Mult, Div         │                         │
│         └──────────────────────┘                         │
│                                                          │
└─────────────────────────────────────────────────────────┘
```

## Compilation and Execution

### Prerequisites
- g++ compiler with C++11 support
- macOS, Linux, or Unix-like system

### Build

```bash
cd hands-on-1
make
```

### Run

```bash
./vm
```

### Clean

```bash
make clean
```

## Sample Program Output

The VM executes a sample program that demonstrates all instruction types:

```
1. START - Initialize execution
2. ADD 15, 25 → Result: 40 (stored in ACC)
3. STORE 100 → Store ACC (40) at memory address 100
4. MULT 6, 7 → Result: 42 (stored in ACC)
5. STORE 101 → Store ACC (42) at memory address 101
6. SUSTR 50, 20 → Result: 30 (stored in ACC)
7. DIV 100, 4 → Result: 25 (stored in ACC)
8. STOP - End execution
```

## Machine Cycle Display

For each instruction, the VM displays:

```
╔════════════════════════════════════╗
║         FETCH PHASE                ║
╚════════════════════════════════════╝
Fetching instruction at PC = X

[Register State Display]

╔════════════════════════════════════╗
║         DECODE PHASE               ║
╚════════════════════════════════════╝
Instruction: [NAME]
Opcode: [CODE]

[Register State Display]

╔════════════════════════════════════╗
║         EXECUTE PHASE              ║
╚════════════════════════════════════╝
Operation: [DESCRIPTION]
[Operation Result]

[Register State Display]
```

## File Structure

```
hands-on-1/
├── Makefile              # Build configuration
├── README.md            # This file
├── Main.cpp             # Main program and demonstration
├── Instruction.hpp/cpp  # Base instruction class
├── ADD.hpp/cpp          # Addition instruction
├── SUSTR.hpp/cpp        # Subtraction instruction
├── MULT.hpp/cpp         # Multiplication instruction
├── DIV.hpp/cpp          # Division instruction
├── MOV.hpp/cpp          # Move instruction
├── STORE.hpp/cpp        # Store instruction
├── Registers.hpp/cpp    # Register management
├── Memory.hpp/cpp       # Memory management
├── CU.hpp/cpp           # Control Unit
├── ALU.hpp/cpp          # Arithmetic Logic Unit
├── Program.hpp/cpp      # Program container
├── ProgramLoader.hpp/cpp # Program loader
├── InstructionSet.hpp/cpp # Instruction set container
└── LexicalAnalyzer.hpp/cpp # Token validation
```

