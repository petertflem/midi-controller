#include "Arduino.h"
#include "ButtonsStateCodes.h"

#ifndef BUTTON_MANAGER
#define BUTTON_MANAGER

#define NUMBER_OF_BUTTONS 4
#define DEBOUNCE_DELAY 50
#define SAME_BUTTON_PRESS_TIME_LIMIT 250

class ButtonManager
{
  public:
    ButtonManager(byte buttonAPin, byte buttonBPin, byte buttonCPin, byte buttonDPin);
    byte getAccumulatedButtonState();
    
  private:
    /* Variables */
    byte _buttonPins[NUMBER_OF_BUTTONS];
    byte _previousButtonState;
    byte _lastValidButtonState;
    unsigned long _lastDebounceTime;
    unsigned long _timeOfLastValidButtonState;
    
    /* Functions */
    byte calculateAccumulatedButtonState(byte buttonAState, byte buttonBState, byte buttonCState, byte buttonDState);
    byte getCurrentAccumulatedButtonState();
};

#endif
