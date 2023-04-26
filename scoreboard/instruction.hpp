#ifndef INSTRUCTIONINTERFACEDEF
#define INSTRUCTIONINTERFACEDEF

#include <string>

#include "instructionStateEnum.hpp"
#include "instructionOpcodeEnum.hpp"
#include "functionalUnitTypesEnum.hpp"
#include "register.hpp"

typedef union Operand {
  std::string immediate;
  Register reg;

  Operand &operator=(const Operand &other) {
    immediate = other.immediate;
    reg = other.reg;

    return *this;
  }

  Operand() {};
  ~Operand() {};
};

class Instruction {
  public:
    InstructionState currentState;
    InstructionOpcode opcode;
    Register* mDestination;
    Operand* mFirstOperand;
    Operand* mSecondOperand;
    FunctionalUnitTypes functionalUnit;

    int cycleIssued;
    int cycleRead;
    int cycleStartExecution;
    int cycleFinishedExecution;
    int cycleWroteBack;

    Instruction(InstructionOpcode, Register*, Operand*, Operand*);
    Instruction(InstructionOpcode, Register*, Operand*);
    void updateInstruction(InstructionState);
};

FunctionalUnitTypes getFunctionUnitTypeForInstruction(InstructionOpcode);

#endif