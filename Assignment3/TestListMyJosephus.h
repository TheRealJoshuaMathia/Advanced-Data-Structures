#ifndef TestListMyJosephus_h
#define TestListMyJosephus_h

#include "ListMyJosephus.h"

using std::cin;

class TestListMyJosephus 
{
    public: 

    TestListMyJosephus();
    ~TestListMyJosephus();
    void runTest();
    void getUserInput(int &numberOfPlayers, int &elimInterval);

};
#endif