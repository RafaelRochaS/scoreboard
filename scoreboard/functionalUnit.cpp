#include "functionalUnit.hpp"
#include "functionalUnitTypesEnum.cpp"

FunctionalUnit::FunctionalUnit (FunctionalUnitTypes fuType) {
  type = fuType;
  isBusy = false;
  operation = "-";
  destinationRegister = "-";
  sourceOperand1 = "-";
  sourceOperand2 = "-";
  producingUnit1 = "-";
  producingUnit2 = "-";
  isFirstOperandReady = false;
  isSecondOperandReady = false;
}