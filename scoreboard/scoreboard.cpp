#include <iostream>
#include <map>

#include "scoreboard.hpp"
#include "functionalUnit.hpp"
#include "functionalUnitTypesEnum.hpp"

std::map<FunctionalUnitTypes, std::string> fuNames{
    {INT, "Integer"},
    {F_ADD, "Float Add"},
    {F_MULTIPLY, "Float Multiply"},
    {F_DIVISION, "Float Division"}};

std::string printBool (bool value) {
  return value ? "true" : "false";
}

void Scoreboard::createFunctionalUnits (int amount, FunctionalUnitTypes type) {
  for (int i = 0; i < amount; i++) {
    FunctionalUnit* fu = new FunctionalUnit(type);
    functionalUnits.push_back(fu);
  }
}

void Scoreboard::printFunctionalUnits () {
  std::cout << "Current state of functional units" << std::endl;

  for (size_t i = 0; i < functionalUnits.size(); i++) {
    const std::string unitName = fuNames[functionalUnits[i]->type];
    std::cout << "Functional Unit: " << unitName << std::endl;
    std::cout << "\tBusy: " << printBool(functionalUnits[i]->isBusy) << "\tOp: " << functionalUnits[i]->operation;
    std::cout << "\tFi: " << functionalUnits[i]->destinationRegister << "\tFj: " << functionalUnits[i]->sourceOperand1;
    std::cout << "\tFk: " << functionalUnits[i]->sourceOperand2 << "\tQj: " << functionalUnits[i]->producingUnit1;
    std::cout << "\tQk: " << functionalUnits[i]->producingUnit2 << "\tRj: " << printBool(functionalUnits[i]->isFirstOperandReady);
    std::cout << "\tRk: " << printBool(functionalUnits[i]->isSecondOperandReady) << std::endl;
  }
}