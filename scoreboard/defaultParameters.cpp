#include <iostream>
#include <vector>

#include "defaultParameters.hpp"

std::vector<DefaultFunctionalUnit> instantiateDefaultUnitsObject()
{
  std::cout << "[+] Instantiating default functional units..." << std::endl;
  std::vector<DefaultFunctionalUnit> defaultUnits;

  defaultUnits.push_back({
    amount : 1,
    type : FunctionalUnitTypes::INT,
    cyclesToComplete : 1
  });
  defaultUnits.push_back({
    amount : 1,
    type : FunctionalUnitTypes::F_ADD,
    cyclesToComplete : 2
  });
  defaultUnits.push_back({
    amount : 2,
    type : FunctionalUnitTypes::F_MULTIPLY,
    cyclesToComplete : 4
  });
  defaultUnits.push_back({
    amount : 1,
    type : FunctionalUnitTypes::F_DIVISION,
    cyclesToComplete : 10
  });

  return defaultUnits;
}

std::vector<Instruction *> instantiateDefaultInstructions()
{
  std::cout << "[+] Instantiating default instructions..." << std::endl;
  std::vector<Instruction *> instructions;

  Operand *op = new Operand();
  Operand *op2 = new Operand();
  op->immediate = "100(x7)";

  instructions.push_back(generateInstruction(RegisterType::FLOAT, 1, InstructionOpcode::fld, op));

  op->reg = {
    RegisterType::FLOAT,
    2,
    getFunctionUnitTypeForInstruction(InstructionOpcode::fmul)
  };
  op2->reg = {
    RegisterType::FLOAT,
    4,
    getFunctionUnitTypeForInstruction(InstructionOpcode::fmul)
  };
  instructions.push_back(generateInstruction(RegisterType::FLOAT, 2, InstructionOpcode::fmul, op, op2));

  return instructions;
}

Instruction* generateInstruction(RegisterType regType, int regNumber, InstructionOpcode opCode, Operand* operand, Operand* secondOperand = nullptr) {
  Register *reg = new Register{
      regType,
      regNumber,
      getFunctionUnitTypeForInstruction(opCode)};

  return new Instruction(
      InstructionOpcode::fld,
      reg,
      operand,
      secondOperand);
}