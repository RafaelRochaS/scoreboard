#include <iostream>
#include <string>
#include <vector>

#include "consts.cpp"
#include "scoreboard.hpp"
#include "functionalUnitTypesEnum.hpp"
#include "instruction.hpp"

struct DefaultFunctionalUnit {
  int amount;
  FunctionalUnitTypes type;
  int cyclesToComplete;
};

std::vector<DefaultFunctionalUnit> instantiateDefaultUnitsObject () {
  std::cout << "[+] Instantiating default functional units..." << std::endl;
  std::vector<DefaultFunctionalUnit> defaultUnits;

  defaultUnits.push_back({
    amount : 1,
    type : FunctionalUnitTypes::INT,
    cyclesToComplete: 1
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

std::vector<Instruction*> instantiateDefaultInstructions () {
  std::cout << "[+] Instantiating default instructions..." << std::endl;
  std::vector<Instruction*> instructions;

  Register* reg1 = new Register{
      RegisterType::FLOAT,
      1,
      getFunctionUnitTypeForInstruction(InstructionOpcode::fld)};
  Operand* op1 = new Operand();
  op1->immediate = "100(x7)";
  Instruction *ins1 = new Instruction(
      InstructionOpcode::fld,
      reg1,
      op1);

  instructions.push_back(ins1);

  return instructions;
}

int main () {
  std::cout << STARS << std::endl << INITIAL_STRING <<  STARS << std::endl << std::endl;

  Scoreboard *scoreboard = new Scoreboard();

  std::cout << "[!] No functional units input detected, using default ones..." << std::endl;
  const std::vector<DefaultFunctionalUnit> defaultUnits = instantiateDefaultUnitsObject();

  std::cout << "[!] No instructions input detected, using default ones..." << std::endl;
  scoreboard->setInstructionRecord(instantiateDefaultInstructions());

  for (size_t i = 0; i < defaultUnits.size(); i++) {
    scoreboard->createFunctionalUnits(defaultUnits[i].amount, defaultUnits[i].type, defaultUnits[i].cyclesToComplete);
  }

  scoreboard->printFunctionalUnits();
}
