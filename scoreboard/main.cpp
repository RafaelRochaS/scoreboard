#include <iostream>
#include <vector>

#include "consts.cpp"
#include "scoreboard.hpp"
#include "functionalUnitTypesEnum.hpp"
#include "instruction.hpp"
#include "defaultParameters.hpp"

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
