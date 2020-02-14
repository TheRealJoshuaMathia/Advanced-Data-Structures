#include "ListMyJosephus.h"

ListMyJosephus::ListMyJosephus()
{
    this->numOfPlayers = 0;
    this->elimCounter = 0;
    this->size = 0;
}

ListMyJosephus::ListMyJosephus(int N,int M)
{
   this->init(N, M);
}

ListMyJosephus::~ListMyJosephus()
{
    this->clear();
    this->numOfPlayers = 0;
    this->elimCounter = 0;
    this->size = 0;
}

void ListMyJosephus::init(int N,int M)
{
  this->numOfPlayers = N;
  this->elimCounter = M;
  this->size = this->numOfPlayers;

   for (int i = 0; i < this->numOfPlayers; i++) //fill list
    {
       this->circ.push_back(Person(i));
    }
}

void ListMyJosephus::clear()
{
    this->circ.clear();
    this->size = 0;
}
int ListMyJosephus::currentSize()
{
   return this->circ.size();
}

bool ListMyJosephus::isEmpty()
{
    return this->circ.empty();
}

Person ListMyJosephus::eliminateNext()
{
    int count = 0;
    Person elimPlayer;

    while (count < this->elimCounter)
    {
        if(listIterator == this->circ.end()) // Checks to see if the iterator equates to the end if true, returned to begining
        {
            listIterator = this->circ.begin();
        }
        count++;
        listIterator++; 
    }

    if(listIterator == circ.end())
    {
        listIterator = this->circ.begin();
    }
    //move the deleted person to the end of the loser list
    this->losers.push_back((*listIterator).getPostion());

    //push the found iterator to the front of the list and delete at front
    this->circ.push_front(*listIterator);
    this->circ.pop_front();

    listIterator = circ.erase(listIterator);

    this->size--;

    return *this->circ.begin();
}
void ListMyJosephus::printAll()
{
    listIterator = this->circ.begin();
    while (listIterator != this->circ.end())
    {
        cout << listIterator->getPostion() << ", ";
        listIterator++;
    }
    cout << endl;
}

void ListMyJosephus::gameLogic()
{
    listIterator = this->circ.begin();
    double time = 0.0, avg = 0.0;
    Person elimPlayer;
    list <Person> losers;

    // checks to see if the function has ended 
    bool isFinished = false;
    int count = 0;
    //starts clock for program run time
    auto startProgram = high_resolution_clock::now();
    while (isFinished != true)
    {   
        count = 0;
        auto startElimClock = high_resolution_clock::now();
        this->eliminateNext();
        // get elimination time
        auto stopElimClock = high_resolution_clock::now();

        // Ends execution clock
        auto duration = duration_cast<microseconds>(stopElimClock - startElimClock);
        time = duration.count() + time;
        //cout << "The Elimination time was " << duration.count() << " microseconds" << endl;
        //cout << "Players Remaining: ";
        //prints the list
        //this->printAll();
        //cout << endl;
        //checks to see if size of the list
        isFinished = this->isWinner();  
    }
    //end of the program
    auto endProgram = high_resolution_clock::now();

    //total program run time
    auto programRunTime = duration_cast<microseconds>(endProgram - startProgram);
    
    //average elimination time
    avg = time / (this->numOfPlayers - 1);
    cout << endl;
    cout << "The average time of elimination is: " << avg
         << " seconds" << endl;

    cout << "The total Program Run time: " << programRunTime.count() << endl;
    
    list <int>::iterator loser_it = this->losers.begin();
    
    //print elimination sequence
    while(loser_it != this->losers.end())
    {
       cout << *loser_it << ", ";
       loser_it++;
    }
    cout << "The winnner is: " << this->circ.begin()->getPostion() 
    << endl;
}

bool ListMyJosephus::isWinner() 
{
    if(this->circ.size() == 1)
    {
        cout << "Winner has been found... " << endl;
        return true;
    }
    else
    {
        return false;
    }
}