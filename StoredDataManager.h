#include "Bank.h"
#include "SetListManager.h"

#ifndef STORED_DATA_MANAGER
#define STORED_DATA_MANAGER

#define NUMBER_OF_BANKS_IN_LIBRARY 10

class StoredDataManager
{
  public:
    StoredDataManager();

    void incrementLibraryBank();
    void decrementLibraryBank();

  private:
    Bank* _library[NUMBER_OF_BANKS_IN_LIBRARY];
    SetListManager* _setListsManager;

    void incrementBank(Bank* listOfBanks);
    void decrementBank(Bank* listOfBanks);

    byte _currentLibraryIndex;
};

#endif
