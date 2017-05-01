#include "Arduino.h"

#ifndef MIDI_COMMAND
#define MIDI_COMMAND

class MIDICommand
{
  public:
    MIDICommand(byte channel, byte programChange);

    byte getChannel();
    byte getProgramChange();

  private:
    byte _channel;
    byte _programChange;
};
#endif
