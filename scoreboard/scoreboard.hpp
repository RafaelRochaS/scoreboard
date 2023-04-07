#ifndef SCOREBOARDINTERFACEDEF
#define SCOREBOARDINTERFACEDEF

#include <vector>
#include <string>
#include <map>

#include "functionalUnitTypesEnum.hpp"
#include "functionalUnit.hpp"
#include "instruction.hpp"
#include "register.hpp"

class Scoreboard {
  private:
    std::vector<Register> registerAllocationVector;
    std::vector<Instruction> instructionRecord;
    std::vector<FunctionalUnit*> functionalUnits;
    int clock;

  public:
    void createFunctionalUnits(int amount, FunctionalUnitTypes type);
    void printFunctionalUnits();
};

#endif