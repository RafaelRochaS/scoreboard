#include <iostream>

#include "scoreboard.hpp"
#include "functionalUnit.hpp"
#include "functionalUnitTypesEnum.cpp"

void Scoreboard::createFunctionalUnits (int amount, FunctionalUnitTypes type) {
  for (int i = 0; i < amount; i++) {
    FunctionalUnit* fu = new FunctionalUnit(type);
    functionalUnits.push_back(fu);
  }
}

void Scoreboard::printFunctionalUnits () {
  std::cout << "Current state of functional units" << std::endl;

  for (size_t i = 0; i < functionalUnits.size(); i++) {
    std::cout << "Functional Unit: " << functionalUnits[i]->type << std::endl;
    std::cout << "\tBusy: " << functionalUnits[i]->isBusy << "\tOp: " << functionalUnits[i]->operation;
    std::cout << "\tFi: " << functionalUnits[i]->destinationRegister << "\tFj: " << functionalUnits[i]->sourceOperand1;
    std::cout << "\tFk: " << functionalUnits[i]->sourceOperand2 << "\tQj: " << functionalUnits[i]->producingUnit1;
    std::cout << "\tQk: " << functionalUnits[i]->producingUnit2 << "\tRj: " << functionalUnits[i]->isFirstOperandReady;
    std::cout << "\tRk: " << functionalUnits[i]->isSecondOperandReady << std::endl;
  }
}