#include <string>
#include <cassert>

#include "instruction.hpp"
#include "instructionStateEnum.hpp"
#include "instructionOpcodeEnum.hpp"
#include "functionalUnitTypesEnum.hpp"
#include "register.hpp"

Instruction::Instruction(
    InstructionOpcode code,
    Register* destination,
    Operand* firstOperand,
    Operand* SecondOperand) {

  opcode = code;
  mDestination = destination;
  mFirstOperand = firstOperand;
  mSecondOperand = SecondOperand;

  currentState = InstructionState::IF;
  functionalUnit = getFunctionUnitTypeForInstruction(code);
};

Instruction::Instruction(
    InstructionOpcode code,
    Register* destination,
    Operand* firstOperand)
{

  opcode = code;
  mDestination = destination;
  mFirstOperand = firstOperand;
  mSecondOperand = nullptr;

  currentState = InstructionState::IF;
  functionalUnit = getFunctionUnitTypeForInstruction(code);
};

void Instruction::updateInstruction(InstructionState state) {
  assert(state >= currentState);
  currentState = state;
};

FunctionalUnitTypes getFunctionUnitTypeForInstruction(InstructionOpcode code) {
  switch (code) {
  case InstructionOpcode::fld:
  case InstructionOpcode::fsd:
    return FunctionalUnitTypes::INT;
    break;
  case InstructionOpcode::fadd:
  case InstructionOpcode::fsub:
    return FunctionalUnitTypes::F_ADD;
    break;
  case InstructionOpcode::fmul:
    return FunctionalUnitTypes::F_MULTIPLY;
    break;
  case InstructionOpcode::fdiv:
    return FunctionalUnitTypes::F_DIVISION;
    break;
  default:
    throw "No functional type known for given opcode" + code;
    break;
  }
};