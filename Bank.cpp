#include "Bank.h"
#include "Preset.h"

Bank::Bank(char* bankName)
{
  _bankName = bankName;

  setPresetA("FLOW PART AWESOME", "Some data");
  setPresetB("BRI", "Some data");
  setPresetC("VER", "Some data");
  setPresetD("INT", "Some data");
}

/* ========== PUBLIC FUNCTIONS ========== */
Preset* Bank::getPresetA()
{
  return _presetA;
}

Preset* Bank::getPresetB()
{
  return _presetB;
}

Preset* Bank::getPresetC()
{
  return _presetC;
}

Preset* Bank::getPresetD()
{
  return _presetD;
}

char* Bank::getBankName()
{
  return _bankName;
}

void Bank::setPresetA(char* presetName, char* presetData)
{
  // Delete if existing preset?
  _presetA = new Preset(presetName, presetData);
}

void Bank::setPresetB(char* presetName, char* presetData)
{
  // Delete if existing preset?
  _presetB = new Preset(presetName, presetData);
}

void Bank::setPresetC(char* presetName, char* presetData)
{
  // Delete if existing preset?
  _presetC = new Preset(presetName, presetData);
}

void Bank::setPresetD(char* presetName, char* presetData)
{
  // Delete if existing preset?
  _presetD = new Preset(presetName, presetData);
}
