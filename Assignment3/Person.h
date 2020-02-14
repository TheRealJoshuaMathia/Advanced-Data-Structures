#ifndef Person_h
#define Person_h

#include <iostream>
using std::cout;

class Person {


    public:
	// Constructor:
	// Note: A person object should be created only if there is a position available for that person to occupy. 
	//		And of course, no two people can occupy the same position, and 
	//		no person can occupy more than one position at any given time.
	// ...
    Person();
	
	//Constructur used to populate list
	Person(int i);

    // Destructor
    ~Person();

    //print the position
    void print();

    int getPostion();
	void setPostion(int num);
    
    private:

   	int position; // position occupied by the person at any point of the game
						// Note: Because each position occupies a unique position initially, 
						// 		that initial position can also be treated as the identifier (id)
						//		or name for that person.
						//		And as the potato is passed around and people are eliminated,
						//			that id can be retained.
};
#endif 