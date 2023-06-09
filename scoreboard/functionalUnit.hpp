#ifndef FUNCTIONALUNITINTERFACEDEF
#define FUNCTIONALUNITINTERFACEDEF

#include <string>

#include "functionalUnitTypesEnum.hpp"

class FunctionalUnit {
  public:
    FunctionalUnitTypes type;
    bool isBusy;
    std::string operation;
    std::string destinationRegister;
    std::string sourceOperand1;
    std::string sourceOperand2;
    std::string producingUnit1;
    std::string producingUnit2;
    bool isFirstOperandReady;
    bool isSecondOperandReady;
    int mCyclesToComplete;

    FunctionalUnit(FunctionalUnitTypes, int);
};

#endif