#ifndef INSTRUCTIONINTERFACEDEF
#define INSTRUCTIONINTERFACEDEF

#include <string>

#include "instructionStateEnum.cpp"
#include "instructionOpcodeEnum.cpp"

class Instruction {
  public:
    InstructionState currentState;
    InstructionOpcode opcode;
    std::string mFirstOperand;
    std::string mSecondOperand;
    std::string mThirdOperand;

    int cycleIssued;
    int cycleRead;
    int cycleStartExecution;
    int cycleFinishedExecution;
    int cycleWroteBack;

    Instruction(InstructionOpcode, std::string, std::string, std::string);
    void updateInstruction(InstructionState);
};

#endif