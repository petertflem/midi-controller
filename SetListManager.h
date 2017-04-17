#include "SetList.h"

#ifndef SET_LIST_MANAGER
#define SET_LIST_MANAGER

#define NUMBER_OF_SET_LISTS 2

class SetListManager
{
  public:
    SetListManager();

    void alterSetListsListIndex(int deltaIndex);
    SetList* getCurrentSetList();
    SetList** getAllSetLists();
    byte getMaxNumberOfSetLists();
    int getCurrentlySelectedSetListIndex();

  private:
    SetList* _setLists[NUMBER_OF_SET_LISTS];
    SetList* _currentlyActiveSetList;

    int _setListsListIndex;
};

#endif
