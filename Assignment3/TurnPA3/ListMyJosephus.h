#ifndef ListMyJosephus_h
#define ListMyJosephus_h

//Header Files
#include "Person.h"
#include <list>
#include <chrono>

//Using & Namespace
using namespace std::chrono;
using std::list;
using std::endl;
using std::iterator;

//Class for the implementation of a List Josephus solution
class ListMyJosephus {

public:
	// Constructors:
	// 		Provide a default empty playing circle constructor 
	ListMyJosephus();

	//		- a constructor that initializes a playing circle of N people who 
	//				will play this game
	//		- both N and M are to be specified at input (during construction) and cannot change during the game.
	//		- position values should be system assigned (i.e., by your code) in the order of insertion
	//			for example, if N=5, then people {0,1,2,3,4} in the circle should be assigned positions:
	//						{0,1,2,3,4} in that order respectively.
	
	ListMyJosephus(int N,int M);


	// Destructor: make sure you free everything you allocated.
	~ListMyJosephus();

	// Public methods:

	//		This init function does the same thing as the argument constructor above.
	//		This function is provided for convenience purposes:
	//			To support the user code specifying either ListMyJosephus(N,M) <or> ListMyJosephus() first and then init(N,M). 
	//			Both should achieve the same effect of initializing the game with N people and set M as the interval of elimination.
	void init(int N,int M);

	//	makes the circle empty 
	void clear();

	//	prints the number of people still playing the game (i.e., not yet eliminated) 
	int currentSize();

	//	returns true if circle is empty
	bool isEmpty();

	// eliminates the next person as per the game's rule
	Person eliminateNext();

	// prints the current content of circle in sequence starting from the person with the least position number
	void printAll();

	// any other member functions of your choice
	// ....

    void gameLogic();
    bool isWinner();

private:

//The Circle List
list <Person> circ;
//List Iterator 
list <Person>::iterator listIterator;
//The List for the losers ("Eliminated Players")
list <int> losers;
//size of the list decreases as a player is eliminated
int size;
// the number of people at the start of the game.
int numOfPlayers;
// Elimintation counter interval. Specified by the user.("The Potato") 
int elimCounter;
};
#endif