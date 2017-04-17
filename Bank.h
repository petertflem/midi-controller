#include "Preset.h"

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

    void setPresetA(char* presetName, char* presetData);
    void setPresetB(char* presetName, char* presetData);
    void setPresetC(char* presetName, char* presetData);
    void setPresetD(char* presetName, char* presetData);

  private:
    Preset* _presetA;
    Preset* _presetB;
    Preset* _presetC;
    Preset* _presetD;

    char* _bankName;
};

#endif
