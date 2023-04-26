#include "functionalUnit.hpp"
#include "functionalUnitTypesEnum.hpp"

FunctionalUnit::FunctionalUnit (FunctionalUnitTypes fuType, int cyclesToComplete) {
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
  mCyclesToComplete = cyclesToComplete;
}