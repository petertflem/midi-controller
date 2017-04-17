#include "Preset.h"

Preset::Preset(char* presetName, char* presetData)
{
  _presetName = presetName;
  _presetData = presetData;
}

/* ========== PUBLIC FUNCTIONS ========== */
char* Preset::getPresetName()
{
  return _presetName;
}

char* Preset::getPresetData()
{
  return _presetData;
}


