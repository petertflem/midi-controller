#include "Bank.h"
#include "Preset.h"

Bank::Bank(char* bankName)
{
  _bankName = bankName;

  MIDICommand* one =  new MIDICommand(1, 2);
  MIDICommand* two =  new MIDICommand(2, 2);

  MIDICommand* MIDICommandsA[] = { one, two };
  //MIDICommand* MIDICommandsB[] = { new MIDICommand(3, 2), new MIDICommand(4, 2) };
  //MIDICommand* MIDICommandsC[] = { new MIDICommand(5, 2), new MIDICommand(6, 2) };
  //MIDICommand* MIDICommandsD[] = { new MIDICommand(7, 2), new MIDICommand(8, 2) };

  setPresetA("CHR", MIDICommandsA);
  setPresetB("BRI", MIDICommandsA);
  setPresetC("VER", MIDICommandsA);
  setPresetD("INT", MIDICommandsA);
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

void Bank::setPresetA(char* presetName, MIDICommand** MIDICommands)
{
  // Delete if existing preset?
  _presetA = new Preset(presetName, MIDICommands);
}

void Bank::setPresetB(char* presetName, MIDICommand** MIDICommands)
{
  // Delete if existing preset?
  _presetB = new Preset(presetName, MIDICommands);
}

void Bank::setPresetC(char* presetName, MIDICommand** MIDICommands)
{
  // Delete if existing preset?
  _presetC = new Preset(presetName, MIDICommands);
}

void Bank::setPresetD(char* presetName, MIDICommand** MIDICommands)
{
  // Delete if existing preset?
  _presetD = new Preset(presetName, MIDICommands);
}
