#ifndef SCOREBOARDINTERFACEDEF
#define SCOREBOARDINTERFACEDEF

#include <vector>
#include <string>

#include "functionalUnitTypesEnum.cpp"
#include "functionalUnit.hpp"

class Scoreboard {
  private:
    std::vector<bool> registerAllocationVector;
    std::vector<std::vector<std::string>> instructionRecord;
    std::vector<FunctionalUnit*> functionalUnits;
    int clock;

  public:
    void createFunctionalUnits(int amount, FunctionalUnitTypes type);
    void printFunctionalUnits();
};

#endif