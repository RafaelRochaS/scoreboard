#include <iostream>
#include <string>
#include <vector>

#include "consts.cpp"
#include "scoreboard.hpp"
#include "functionalUnitTypesEnum.cpp"

struct DefaultFunctionalUnit {
  int amount;
  FunctionalUnitTypes type;
};

std::vector<DefaultFunctionalUnit> instantiateDefaultUnitsObject () {
  std::cout << "[+] Instantiating default functional units..." << std::endl;
  std::vector<DefaultFunctionalUnit> defaultUnits;

  defaultUnits.push_back({
    amount : 3,
    type : FunctionalUnitTypes::INT
  });
  defaultUnits.push_back({
    amount : 2,
    type : FunctionalUnitTypes::F_ADD
  });
  defaultUnits.push_back({
    amount : 2,
    type : FunctionalUnitTypes::F_MULTIPLY
  });
  defaultUnits.push_back({
    amount : 2,
    type : FunctionalUnitTypes::F_DIVISION
  });

  return defaultUnits;
}

int main () {
  std::cout << STARS << std::endl << INITIAL_STRING <<  STARS << std::endl << std::endl;

  Scoreboard *scoreboard = new Scoreboard();

  std::cout << "[!] No functional units input detected, using default ones..." << std::endl;
  const std::vector<DefaultFunctionalUnit> defaultUnits = instantiateDefaultUnitsObject();

  for (size_t i = 0; i < defaultUnits.size(); i++) {
    scoreboard->createFunctionalUnits(defaultUnits[i].amount, defaultUnits[i].type);
  }

  scoreboard->printFunctionalUnits();
}
