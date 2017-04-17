#include "SetListManager.h"

SetListManager::SetListManager()
{
  _setListsListIndex = 0;

  /*for (byte i = 0; i < NUMBER_OF_SET_LISTS; i++)
  {
    _setLists[i] = new SetList("SetList");
  }*/

  _setLists[0] = new SetList("R11");
  _setLists[1] = new SetList("R18");
}

/* ========== PUBLIC FUNCTIONS ========== */
SetList* SetListManager::getCurrentSetList()
{
  return _setLists[_setListsListIndex];
}

SetList** SetListManager::getAllSetLists()
{
  return _setLists;
}

void SetListManager::alterSetListsListIndex(int deltaIndex)
{
  int newArrayIndex = _setListsListIndex + deltaIndex;
  
  if (newArrayIndex < 0)
  {
    _setListsListIndex = NUMBER_OF_SET_LISTS - 1;
  } else if (newArrayIndex > NUMBER_OF_SET_LISTS - 1)
  {
    _setListsListIndex = 0;
  } else
  {
    _setListsListIndex = newArrayIndex;
  }
}

byte SetListManager::getMaxNumberOfSetLists()
{
  return NUMBER_OF_SET_LISTS;
}

int SetListManager::getCurrentlySelectedSetListIndex()
{
  return _setListsListIndex;
}
