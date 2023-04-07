#include <string>

#include "instruction.hpp"
#include "instructionStateEnum.hpp"
#include "instructionOpcodeEnum.hpp"

Instruction::Instruction(
    InstructionOpcode code,
    std::string firstOperand,
    std::string secondOperand = "",
    std::string thirdOperand = "") {

  opcode = code;
  mFirstOperand = firstOperand;
  mSecondOperand = secondOperand;
  mThirdOperand = thirdOperand;

  currentState = InstructionState::IF;
};
