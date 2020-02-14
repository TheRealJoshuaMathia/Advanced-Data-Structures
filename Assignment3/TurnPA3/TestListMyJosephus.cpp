#include "TestListMyJosephus.h"

TestListMyJosephus::TestListMyJosephus()
{

}

TestListMyJosephus:: ~TestListMyJosephus()
{

}

void TestListMyJosephus::runTest()
{
    int numberOfPlayers = -1;
    int elimInterval = -1;

    getUserInput(numberOfPlayers, elimInterval);
    ListMyJosephus run(numberOfPlayers, elimInterval); 
    cout << "Size of List: " << run.currentSize() << endl;
    cout << "These are the players: " << endl;
    run.printAll();
    cout << endl;
    cout << endl;
    run.gameLogic();
}

 void TestListMyJosephus::getUserInput(int &numberOfPlayers, int &elimInterval)
 {
    cout << "Please enter the number of Players:" << endl;
    do 
    {
        cin >> numberOfPlayers;
    }while(numberOfPlayers < 1);

    cout << "Please enter the Elimination Interval: " << endl;
    do 
    {
        cin >>elimInterval;
    }while(elimInterval < 0);
 }

