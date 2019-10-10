#include "VectorMyJosephus.hpp"

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
    int count = 0;

    Person elimPlayer;

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
    
    this->losers.push_back((*vectorIterator).getPostion());
    vectorIterator = circ.erase(vectorIterator);
    this->size--;

    return *this->circ.begin();
}
void VectorMyJosephus::printAll()
{
    for(auto counter: this->circ)
    {
        counter.print();
    }
}

void VectorMyJosephus::gameLogic()
{
    double executionTime = 0.0, averageTime = 0.0;

    vectorIterator = this->circ.begin();
    
    Person elimPlayer;
    vector <Person> losers;

    clock_t runVector;

    bool isFinished = false;

    while (isFinished != true)
    {
        runVector = clock();
        this->eliminateNext();
        clock_t endVector = clock();
        cout << "Players Remaining: ";
        this->printAll();
        cout << endl;
       
       executionTime = double(endVector - runVector) + executionTime;
       isFinished = this->isWinner();
    }

    averageTime = executionTime / (this->numOfPlayers - 1);
    cout << endl;
    cout << "The average time of elimination is: " << double((averageTime/ CLOCKS_PER_SEC))
         << " seconds" << endl;
    cout << "The elimination sequence is : ";

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
        cout << "Winner has been found... " << endl;
        return true;
    }
    else
    {
        return false;
    }
}