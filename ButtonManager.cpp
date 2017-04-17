#include "ButtonManager.h"

ButtonManager::ButtonManager(byte buttonAPin, byte buttonBPin, byte buttonCPin, byte buttonDPin)
{
  _previousButtonState = 0;
  _lastValidButtonState = 0;
  _timeOfLastValidButtonState = 0;
  
  _buttonPins[0] = buttonAPin;
  _buttonPins[1] = buttonBPin;
  _buttonPins[2] = buttonCPin;
  _buttonPins[3] = buttonDPin;

  for (byte i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    pinMode(_buttonPins[i], INPUT);
  }
}

/* ========== PUBLIC FUNCTIONS ========== */
byte ButtonManager::getAccumulatedButtonState()
{
  byte currentButtonState = getCurrentAccumulatedButtonState();
  
  if (currentButtonState != _previousButtonState)
  {
    _lastDebounceTime = millis();
  }

  _previousButtonState = currentButtonState;

  if ((millis() - _timeOfLastValidButtonState) > SAME_BUTTON_PRESS_TIME_LIMIT && _lastValidButtonState != NO_BUTTONS_PRESSED)
  {
    _timeOfLastValidButtonState = 0;
    _lastValidButtonState = 0;
  }

  if ((millis() - _lastDebounceTime) > DEBOUNCE_DELAY && currentButtonState != NO_BUTTONS_PRESSED && _lastValidButtonState != currentButtonState)
  {
    _lastValidButtonState = currentButtonState;
    _timeOfLastValidButtonState = millis();
    
    return currentButtonState;
  }

  return NO_BUTTONS_PRESSED;
}

/* ========== PRIVATE FUNCTIONS ========== */
byte ButtonManager::calculateAccumulatedButtonState(byte buttonAState, byte buttonBState, byte buttonCState, byte buttonDState)
{
  byte statePair1 = (buttonBState << 1) | buttonAState;
  byte statePair2 = (buttonDState << 1) | buttonCState;

  return (statePair2 << 2) | statePair1;
}

byte ButtonManager::getCurrentAccumulatedButtonState()
{
  byte currentButtonState[NUMBER_OF_BUTTONS];

  for (byte i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    currentButtonState[i] = digitalRead(_buttonPins[i]);
  }

  return calculateAccumulatedButtonState(currentButtonState[0], currentButtonState[1], currentButtonState[2], currentButtonState[3]);
}

