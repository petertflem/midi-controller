#include "Preset.h"

Preset::Preset(char* presetName, MIDICommand** MIDICommands)
{
  Serial.println(MIDICommands[0]->getProgramChange());
  
  _presetName = presetName;
  _MIDICommands = MIDICommands;

  Serial.println(_MIDICommands[0]->getProgramChange());
}

/* ========== PUBLIC FUNCTIONS ========== */
char* Preset::getPresetName()
{
  return _presetName;
}

MIDICommand* Preset::getMIDICommands()
{
  return *_MIDICommands;
}


