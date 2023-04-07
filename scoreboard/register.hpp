#ifndef REGISTERDEF
#define REGISTERDEF

#include "functionalUnitTypesEnum.hpp"

enum RegisterType
{
  FLOAT,
  INT
};

struct Register
{
  RegisterType type;
  int registerNumber;
  FunctionalUnitTypes currentFunctionalUnit;
};

#endif