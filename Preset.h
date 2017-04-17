#include "Arduino.h"

#ifndef PRESET
#define PRESET

class Preset
{
  public:
    Preset();
    Preset(char* presetName, char* presetData);
    char* getPresetName();
    char* getPresetData();
    
  private:
    char* _presetName;
    char* _presetData;
};

#endif
