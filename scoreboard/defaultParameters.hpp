#ifndef DEFAULTPARAMSDEF
#define DEFAULTPARAMSDEF

#include <vector>

#include "instruction.hpp"

struct DefaultFunctionalUnit
{
  int amount;
  FunctionalUnitTypes type;
  int cyclesToComplete;
};

std::vector<DefaultFunctionalUnit> instantiateDefaultUnitsObject();
std::vector<Instruction *> instantiateDefaultInstructions();

#endif