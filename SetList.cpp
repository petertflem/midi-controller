#include "SetList.h"

SetList::SetList(String setListName)
{
  /*for (byte i = 0; i < NUMBER_OF_BANKS_IN_SET_LIST; i++)
  {
    _banksInSetList[i] = new Bank("Bank");
  }*/

  _banksInSetList[0] = new Bank("Look to the son");
  _banksInSetList[1] = new Bank("Christ is enough");
  _banksInSetList[2] = new Bank("Alive");
  _banksInSetList[3] = new Bank("Behold");
  _banksInSetList[4] = new Bank("Du svikter aldri meg");
  _banksInSetList[5] = new Bank("Bare i deg");
  _banksInSetList[6] = new Bank("Verdens håp");
  _banksInSetList[7] = new Bank("Stor er din trofasthet");
  _banksInSetList[8] = new Bank("Lion and the lamb");
  _banksInSetList[9] = new Bank("Pieces");
  
  _name = setListName;

  _currentlySelectedBankIndex = 0;
}

/* ========== PUBLIC FUNCTIONS ========== */
String SetList::getName()
{
  return _name;
}

Bank* SetList::getCurrentBank()
{
  return _banksInSetList[_currentlySelectedBankIndex];
}

void SetList::alterBankListIndex(int deltaIndex)
{
  int newArrayIndex = _currentlySelectedBankIndex + deltaIndex;
  
  if (newArrayIndex < 0)
  {
    _currentlySelectedBankIndex = NUMBER_OF_BANKS_IN_SET_LIST - 1;
  } else if (newArrayIndex > NUMBER_OF_BANKS_IN_SET_LIST - 1)
  {
    _currentlySelectedBankIndex = 0;
  } else
  {
    _currentlySelectedBankIndex = newArrayIndex;
  }
}

byte SetList::getCurrentBankIndex()
{
  return _currentlySelectedBankIndex;
}

