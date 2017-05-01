#include "MIDICommand.h"

MIDICommand::MIDICommand(byte channel, byte programChange)
{
  _channel = channel;
  _programChange = programChange;   
}

byte MIDICommand::getChannel()
{
  return _channel;
}

byte MIDICommand::getProgramChange()
{
  return _programChange;
}

