#include "Preset.h"
#include "MIDICommand.h"

#ifndef BANK
#define BANK

class Bank
{
  public:
    Bank(char* bankName);

    Preset* getPreset(char presetLocation);

    Preset* getPresetA();
    Preset* getPresetB();
    Preset* getPresetC();
    Preset* getPresetD();

    char* getBankName();

    void setPresetA(char* presetName, MIDICommand** MIDICommands);
    void setPresetB(char* presetName, MIDICommand** MIDICommands);
    void setPresetC(char* presetName, MIDICommand** MIDICommands);
    void setPresetD(char* presetName, MIDICommand** MIDICommands);

  private:
    Preset* _presetA;
    Preset* _presetB;
    Preset* _presetC;
    Preset* _presetD;

    char* _bankName;
};

#endif
