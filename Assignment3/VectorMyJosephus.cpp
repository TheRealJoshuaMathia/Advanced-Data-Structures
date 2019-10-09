#include "VectorMyJosephus.hpp"

VectorMyJosephus::VectorMyJosephus()
{
    this->numOfPlayers = 0;
    this->elimCounter = 0;
}

VectorMyJosephus::VectorMyJosephus(int N,int M)
{
    this->numOfPlayers = N;
    this->elimCounter = M;
}

VectorMyJosephus::~VectorMyJosephus()
{
    //Destructor
}

void VectorMyJosephus::init(int N,int M)
{
  this->numOfPlayers = N;
  this->elimCounter = M;
}

void VectorMyJosephus::clear()
{
    this->circ.clear();  
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

Person VectorMyJosephus::eliminateNext(int key)
{
    int position = 0;
    for(auto counter = this->circ.begin(); counter <= this->circ.end(); counter++)
    {
        if(position == key)
        {
            this->circ.erase(counter);
        }

        position++;
    }
}
void VectorMyJosephus::printAll()
{
    for(auto counter: this->circ)
    {
        counter.print();
    }
}