#include "MenuManager.h"

MenuManager::MenuManager(Adafruit_LiquidCrystal* lcd)
{
  _setListManager = new SetListManager();
  _printCurrentMenu = true;
  _currentMenu = SET_LIST_MENU;

  _lcd = lcd;
}

/* ========== PUBLIC FUNCTIONS ========== */
void MenuManager::handleInteraction(byte buttonsState)
{
  if (_currentMenu == SET_LIST_MENU)
  {
    if (_printCurrentMenu)
    {
      printSelectCurrentSetListMenu();
      _printCurrentMenu = false;
    }

    handleInteractionInSetListMenu(buttonsState);
  }
  else if (_currentMenu == PRESET_MENU)
  {
    if (_printCurrentMenu)
    {
      printPresetMenu();
      _printCurrentMenu = false;
    }

    handleInteractionInPresetMenu(buttonsState);
  }
}

/* ========== PRIVATE FUNCTIONS ========== */
void MenuManager::printSelectCurrentSetListMenu()
{
  SetList** allSetLists = _setListManager->getAllSetLists();
  byte maxNumberOfSetLists = _setListManager->getMaxNumberOfSetLists();
  byte currentlySelectedSetListIndex = _setListManager->getCurrentlySelectedSetListIndex();

  for (byte i = 0; i < maxNumberOfSetLists; i++) {
    _lcd->setCursor(0, i);
    
    if (currentlySelectedSetListIndex == i)
      _lcd->print("X " + allSetLists[i]->getName());
    else
      _lcd->print("  " + allSetLists[i]->getName());
  }
}

void MenuManager::handleInteractionInSetListMenu(byte buttonsState)
{
  if (buttonsState == BUTTONS_A_AND_B_PRESSED)
  {
    _setListManager->alterSetListsListIndex(1);
    _printCurrentMenu = true;
  }
  else if (buttonsState == BUTTONS_C_AND_D_PRESSED)
  {
    _setListManager->alterSetListsListIndex(-1);
    _printCurrentMenu = true;
  }
  else if (buttonsState == BUTTONS_A_AND_D_PRESSED)
  {
    _currentMenu = PRESET_MENU;
    _printCurrentMenu = true;
  }
}

void MenuManager::printPresetMenu()
{
  SetList* currentSetList = _setListManager->getCurrentSetList();
  Bank* currentBank = currentSetList->getCurrentBank();
  
  formatAndPrintBankName(currentSetList->getCurrentBankIndex() + 1, currentBank->getBankName(), 0, 0);

  formatAndPrintPresetOption("A", currentBank->getPresetA()->getPresetName(), 0, 1);
  formatAndPrintPresetOption("B", currentBank->getPresetB()->getPresetName(), 10, 1);
  formatAndPrintPresetOption("C", currentBank->getPresetC()->getPresetName(), 0, 2);
  formatAndPrintPresetOption("D", currentBank->getPresetD()->getPresetName(), 10, 2);

  clearLine(3);
  
  _printCurrentMenu = false;
}

void MenuManager::handleInteractionInPresetMenu(byte buttonsState)
{
  if (buttonsState == NO_BUTTONS_PRESSED)
    return;

  SetList* currentSetList = _setListManager->getCurrentSetList();
  Bank* currentBank = currentSetList->getCurrentBank();
  
  if (buttonsState == BUTTONS_A_AND_B_PRESSED)
  {
    currentSetList->alterBankListIndex(1);
    _printCurrentMenu = true;
  }
  else if (buttonsState == BUTTONS_C_AND_D_PRESSED)
  {
    currentSetList->alterBankListIndex(-1);
    _printCurrentMenu = true;
  }
  else if (buttonsState == BUTTON_A_PRESSED)
  {
    fromatAndPrintSentMIDICommandVerification("A");
  }
  else if (buttonsState == BUTTON_B_PRESSED)
  {
    fromatAndPrintSentMIDICommandVerification("B");
  }
  else if (buttonsState == BUTTON_C_PRESSED)
  {
    fromatAndPrintSentMIDICommandVerification("C");
  }
  else if (buttonsState == BUTTON_D_PRESSED)
  {
    fromatAndPrintSentMIDICommandVerification("D");
  }
  else if (buttonsState == BUTTONS_A_AND_D_PRESSED)
  {
    _currentMenu = SET_LIST_MENU;
    _printCurrentMenu = true;
    clearScreen();
    
  }
}

void MenuManager::formatStringForLCD(char* stringBuffer, char* result, byte width, bool singleDot)
{
  char line[width];

  if (strlen(stringBuffer) > width) {
    if (singleDot) {
      stringBuffer[width - 1] = '.';
      stringBuffer[width] = '\0';
    } else {
      stringBuffer[width - 3] = '.';
      stringBuffer[width - 2] = '.';
      stringBuffer[width - 1] = '.';
      stringBuffer[width] = '\0';
    }
    
    strcpy(line, stringBuffer);
  } else {
    sprintf(line, "%-*s", width, stringBuffer);
  }

  strcpy(result, line);
}

void MenuManager::formatAndPrintBankName(byte bankNumber, char* bankName, byte printX, byte printY)
{
  char stringBuffer[50];
  char sBankNumber[5];
  char line[20];
  
  itoa(bankNumber, sBankNumber, 10);

  strcpy(stringBuffer, sBankNumber);
  strcat(stringBuffer, ". ");
  strcat(stringBuffer, bankName);
  
  formatStringForLCD(stringBuffer, line, 20, false);
  
  _lcd->setCursor(printX, printY);
  _lcd->print(line);  
}

void MenuManager::formatAndPrintPresetOption(char* presetLocation, char* presetName, byte printX, byte printY)
{
  char stringBuffer[50];
  char line[20];
  
  strcpy(stringBuffer, presetLocation);
  strcat(stringBuffer, ": ");
  strcat(stringBuffer, presetName);
  
  formatStringForLCD(stringBuffer, line, 9, true);
  
  _lcd->setCursor(printX, printY);
  _lcd->print(line);
}

void MenuManager::fromatAndPrintSentMIDICommandVerification(char* presetLocation)
{
  char stringBuffer[50];
  char line[20];
  
  strcpy(stringBuffer, "MIDI preset sent: ");
  strcat(stringBuffer, presetLocation);
  
  formatStringForLCD(stringBuffer, line, 20, false);
  
  _lcd->setCursor(0, 3);
  _lcd->print(line);
}

void MenuManager::clearLine(byte y)
{
  _lcd->setCursor(0, y);
  _lcd->print("                    ");
}

void MenuManager::clearScreen()
{
  clearLine(0);
  clearLine(1);
  clearLine(2);
  clearLine(3);
}
