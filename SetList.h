#include "Arduino.h"
#include "Bank.h"

#ifndef SET_LIST
#define SET_LIST

#define NUMBER_OF_BANKS_IN_SET_LIST 10

class SetList
{
  public:
    SetList(String setListName);

    String getName();
    Bank* getCurrentBank();
    void alterBankListIndex(int deltaIndex);
    byte getCurrentBankIndex();
    
  private:
    String _name;
    Bank* _banksInSetList[NUMBER_OF_BANKS_IN_SET_LIST];

    byte _currentlySelectedBankIndex;
};

#endif
