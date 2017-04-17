#include "Arduino.h"
#include "SetListManager.h"
#include "ButtonsStateCodes.h"
#include "Adafruit_LiquidCrystal.h"

#ifndef MENU_MANAGER
#define MENU_MANAGER

#define PRESET_MENU 0
#define SET_LIST_MENU 1

class MenuManager
{
  public:
    MenuManager(Adafruit_LiquidCrystal* lcd);

    void handleInteraction(byte buttonsState);
    
  private:
    SetListManager* _setListManager;
    bool _userInteractionReceived;
    bool _printCurrentMenu;
    byte _currentMenu;
    Adafruit_LiquidCrystal* _lcd;
    
    void printSelectCurrentSetListMenu();
    void handleInteractionInSetListMenu(byte buttonsState);

    void printPresetMenu();
    void handleInteractionInPresetMenu(byte buttonsState);
    void formatStringForLCD(char* stringBuffer, char* result, byte width, bool singleDot);

    void formatAndPrintBankName(byte bankNumber, char* bankName, byte printX, byte printY);
    void formatAndPrintPresetOption(char* presetLocation, char* presetName, byte printX, byte printY);
    void fromatAndPrintSentMIDICommandVerification(char* presetLocation);
    void clearLine(byte y);
    void clearScreen();
};

#endif
