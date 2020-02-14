#include "VectorMyJosephus.h"

VectorMyJosephus::VectorMyJosephus()
{
    this->numOfPlayers = 0;
    this->elimCounter = 0;
    this->size = 0;
}

VectorMyJosephus::VectorMyJosephus(int N,int M)
{
    this->numOfPlayers = N;
    this->elimCounter = M;
    this->size = this->numOfPlayers;

    //Fill Vector
    for (int i = 0; i < this->numOfPlayers; i++) 
    {
        circ.push_back(Person(i));
    }
}

VectorMyJosephus::~VectorMyJosephus()
{
    this->clear();
    this->numOfPlayers = 0;
    this->elimCounter = 0;
    this->size = 0;
}

void VectorMyJosephus::init(int N,int M)
{
  this->numOfPlayers = N;
  this->elimCounter = M;
  this->size = this->numOfPlayers;
}

void VectorMyJosephus::clear()
{
    this->circ.clear(); 
    this->size = 0;
}
int VectorMyJosephus::currentSize()
{
    int currentSize = 0;

    currentSize = this->circ.size();

    return currentSize;
}

bool VectorMyJosephus::isEmpty()
{
    return this->circ.empty();
}

Person VectorMyJosephus::eliminateNext()
{
    Person elimPlayer;
    int count = 0;

    while (count < this->elimCounter)
    {
        if(vectorIterator ==circ.end()) // Checks to see if the iterator equates to the end if true, returned to begining
        {
            vectorIterator = this->circ.begin();
        }
        count++;
        vectorIterator++; 
    }

    if(vectorIterator == circ.end())
    {
        vectorIterator = this->circ.begin();
    }
    //pushes the eliminated person into the vector
    this->losers.push_back((*vectorIterator).getPostion());

    //person node is deleted
    vectorIterator = circ.erase(vectorIterator);
    //size of list decreased
    this->size--;

    return *this->circ.begin();
}

void VectorMyJosephus::printAll()
{
    //print the person position
    for(auto counter: this->circ)
    {
        counter.print();
    }
}


void VectorMyJosephus::gameLogic()
{
    vectorIterator = this->circ.begin();
    double time = 0.0, avg = 0.0;
    
    Person elimPlayer;
    vector <Person> losers;

    // checks to see if the function has ended 
    bool isFinished = false;

    //starts clock for program run time
    auto startProgram = high_resolution_clock::now();
    while (isFinished != true)
    {
        //Start elimination clock
        auto startElimClock = high_resolution_clock::now();
        //eliminate person from list
        this->eliminateNext();
        auto stopElimClock = high_resolution_clock::now();
        // Ends execution clock
        auto duration = duration_cast<microseconds>(stopElimClock - startElimClock);
        //cout << "The Elimination time was " << duration.count() << " microseconds" << endl;
        //cout << "Players Remaining: ";
        time = duration.count() + time;
        //this->printAll();
        cout << endl;
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
    cout << "The elimination sequence is : ";

    cout << "The total Program Run time: " << programRunTime.count() << endl;
    
    //losers iterator ("Elimination list")
    vector <int>::iterator loser_it = this->losers.begin();
    
    while(loser_it != this->losers.end())
    {
       cout << *loser_it << ", ";
       loser_it++;
    }
    cout << "The winnner is: " << this->circ.front().getPostion()
    << endl;
}

bool VectorMyJosephus::isWinner() 
{
    if(this->circ.size() == 1)
    {
        cout << "Winner has been found..." << endl;
        return true;
    }
    else
    {
        return false;
    }
}