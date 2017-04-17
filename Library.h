#include "Bank.h"

#ifndef LIBRARY
#define LIBRARY

#define NUMBER_OF_BANKS 10

class Library
{
  public:
    Library();
    Bank* getCurrentBank();
    void incrementBank();
    void decrementBank();
    void getSpecificBank(byte bankIndex);
    byte getCurrentBankIndex();

  private:
    Bank* _banks[NUMBER_OF_BANKS];
    byte _currentBankIndex;
};

#endif
