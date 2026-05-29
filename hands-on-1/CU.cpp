#include "CU.hpp"
#include "ADD.hpp"
#include "SUSTR.hpp"
#include "MULT.hpp"
#include "DIV.hpp"
#include "STORE.hpp"
#include "MOV.hpp"

CU::CU()
{
	status = "idle";
	registers = nullptr;
	memory = nullptr;
}

CU::CU(Registers* regs, Memory* mem)
{
	status = "idle";
	registers = regs;
	memory = mem;
}

Instruction* CU::fetch(Memory* memory, int address)
{
	displayFetchState(address);
	
	// Update MAR and MBR
	if (registers) {
		registers->setMAR(address);
	}
	
	Instruction* instruction = memory->loadInstruction(address);
	
	if (registers && instruction) {
		registers->setMBR(instruction->getCode());
		registers->setIR(instruction->getName());
	}
	
	return instruction;
}

int CU::decode(Instruction* theInstruction)
{
	if (!theInstruction) return 0;
	
	int opcode = theInstruction->getCode();
	displayDecodeState(theInstruction->getName(), opcode);
	
	return opcode;
}

void CU::execute(Instruction* theInstruction, Registers* registers, Memory* memory)
{
	if (!theInstruction) return;
	
	int opcode = theInstruction->getCode();
	
	switch (opcode) {
		
		case 50: // START
			displayExecuteState("START - Beginning program execution");
			cout << "Program execution started" << endl;
			break;

		case 51: // STOP
			displayExecuteState("STOP - Ending program execution");
			cout << "Program execution completed" << endl;
			break;

		case 80: { // ADD
			displayExecuteState("ADD - Addition operation");
			ADD* addInst = dynamic_cast<ADD*>(theInstruction);
			if (addInst) {
				int op1 = addInst->getOperand1();
				int op2 = addInst->getOperand2();
				int result = alu.add(op1, op2);
				registers->setACC(result);
				cout << "ADD: " << op1 << " + " << op2 << " = " << result << endl;
				cout << "Result stored in ACC" << endl;
			}
			break;
		}

		case 81: { // SUSTR
			displayExecuteState("SUSTR - Subtraction operation");
			SUSTR* subInst = dynamic_cast<SUSTR*>(theInstruction);
			if (subInst) {
				int op1 = subInst->getOperand1();
				int op2 = subInst->getOperand2();
				int result = alu.subtract(op1, op2);
				registers->setACC(result);
				cout << "SUSTR: " << op1 << " - " << op2 << " = " << result << endl;
				cout << "Result stored in ACC" << endl;
			}
			break;
		}

		case 82: { // MULT
			displayExecuteState("MULT - Multiplication operation");
			MULT* multInst = dynamic_cast<MULT*>(theInstruction);
			if (multInst) {
				int op1 = multInst->getOperand1();
				int op2 = multInst->getOperand2();
				int result = alu.multiply(op1, op2);
				registers->setACC(result);
				cout << "MULT: " << op1 << " * " << op2 << " = " << result << endl;
				cout << "Result stored in ACC" << endl;
			}
			break;
		}

		case 83: { // DIV
			displayExecuteState("DIV - Division operation");
			DIV* divInst = dynamic_cast<DIV*>(theInstruction);
			if (divInst) {
				int op1 = divInst->getOperand1();
				int op2 = divInst->getOperand2();
				int result = alu.divide(op1, op2);
				registers->setACC(result);
				cout << "DIV: " << op1 << " / " << op2 << " = " << result << endl;
				cout << "Result stored in ACC" << endl;
			}
			break;
		}

		case 90: { // STORE
			displayExecuteState("STORE - Store ACC to memory");
			STORE* storeInst = dynamic_cast<STORE*>(theInstruction);
			if (storeInst) {
				int addr = storeInst->getAddress();
				int value = registers->getACC();
				memory->storeData(value, addr);
				cout << "STORE: Value " << value << " stored at address " << addr << endl;
			}
			break;
		}

		case 100: { // MOV
			displayExecuteState("MOV - Move data to register");
			MOV* movInst = dynamic_cast<MOV*>(theInstruction);
			if (movInst) {
				int value = movInst->getValue();
				// For simplicity, store in AL register
				registers->setAL(value);
				cout << "MOV: Value " << value << " moved to AL register" << endl;
			}
			break;
		}

		default:
			displayExecuteState("UNKNOWN - Invalid instruction");
			cout << "Unknown instruction with opcode: " << opcode << endl;
			break;
	}
}

void CU::displayFetchState(int pc)
{
	cout << "\n╔════════════════════════════════════╗" << endl;
	cout << "║         FETCH PHASE                ║" << endl;
	cout << "╚════════════════════════════════════╝" << endl;
	cout << "Fetching instruction at PC = " << pc << endl;
}

void CU::displayDecodeState(string instructionName, int opcode)
{
	cout << "\n╔════════════════════════════════════╗" << endl;
	cout << "║         DECODE PHASE               ║" << endl;
	cout << "╚════════════════════════════════════╝" << endl;
	cout << "Instruction: " << instructionName << endl;
	cout << "Opcode: " << opcode << endl;
}

void CU::displayExecuteState(string operation)
{
	cout << "\n╔════════════════════════════════════╗" << endl;
	cout << "║         EXECUTE PHASE              ║" << endl;
	cout << "╚════════════════════════════════════╝" << endl;
	cout << "Operation: " << operation << endl;
}

