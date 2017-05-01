#include "Arduino.h"
#include "MIDICommand.h"

#ifndef PRESET
#define PRESET

#define NUMBER_OF_MIDI_COMMANDS 2

class Preset
{
  public:
    Preset();
    Preset(char* presetName, MIDICommand** MIDICommands);
    char* getPresetName();
    MIDICommand* getMIDICommands();
    
  private:
    char* _presetName;
    MIDICommand* _MIDICommands[2];
};

#endif
