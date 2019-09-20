// Joshua Mathia
// Assignment #2
// fileSystem.cpp file

#include "fileSystem.hpp"
#define FILE_LEFTBOUND 1
#define FILE_RIGHTBOUND 11

//fileSystem()
//This function is the constructor for the class
fileSystem::fileSystem()
{
  cout << "Trying to find the desired input..." << endl;
}

//~fileSystem()
// This function is the destructor for rthe class 
fileSystem::~fileSystem()
{
    cout << "Ending file system...." << endl;
}

//getChoiceFromUser()
//This function gets the choice from the user
//choice cannot be less than FILE_LEFTBOUND "1" or less FILE_RIGHTBOUND "11"
//The function will execute infinitly if their is an invalid selection.
//Returns userChoice
int fileSystem::getChoiceFromUser()
{
    int userChoice = 0;

    do
    {
        cout << "Choice: ";
        cin >> userChoice;

        if (userChoice < FILE_LEFTBOUND || userChoice > FILE_RIGHTBOUND)
        {
            cout << "Invalid Choice: Try again: " << endl;
        }

    } while (userChoice < FILE_LEFTBOUND || userChoice > FILE_RIGHTBOUND);
    return userChoice;
}
//getFileName()
//This function gets the initial file name starting point from the user.
//The user would select an option from the input menu.
//That option would
//Returns userChoice
string fileSystem::getFileName(vector <string> & fileNames)
{
    int userChoice = 0;
    string fileName = " ";

    fileNameMenu();
    userChoice = getChoiceFromUser();
    fileName = fileNames.at(userChoice - 1); // subtracting one for the size of the vector

    // cout << fileName; for testing purposes

    return fileName;
}

//fileNameMenu()
//This function displays the menu for all the input files
// User would then select from the menu
void fileSystem::fileNameMenu()
{
    cout << "Please enter a number from the list: " << endl;
    cout << "---------------------------" << endl;
    cout << "Enter (1) for 8 input Size" << endl;
    cout << "Enter (2) for 16 input Size" << endl;
    cout << "Enter (3) for 32 input Size" << endl;
    cout << "Enter (4) for 64 input Size" << endl;
    cout << "Enter (5) for 128 input Size" << endl;
    cout << "Enter (6) for 256 input Size" << endl;
    cout << "Enter (7) for 512 input Size" << endl;
    cout << "Enter (8) for 1024 input Size" << endl;
    cout << "Enter (9) for 2048 input Size" << endl;
    cout << "Enter (10) for 4096 input Size" << endl;
    cout << "Enter (11) for 8192 input Size" << endl;
}
//generateFileNames()
//This function generates the fileNames for nessesary for file processing
//The function iterates through creating 11 different types of input.txt files
//The created path strings are pushed into a vector
//Returns fileNames
vector <string> fileSystem::generateFileNames(){

vector <string> fileNames;

    string path = "input";
    string underScore = "_";
    string fileNumber = "";
    string fileType = ".txt";
    string fileName = "";
    string zero = "0";
    int baseCase = 8;
    
    for(int counter = 0; counter < FILE_RIGHTBOUND; counter++)
    {
        fileNumber = to_string(baseCase); // Converts the baseCase number into a string

        fileName = path + underScore + fileNumber + underScore + zero + fileType; // adds each part of the fileName 
        baseCase *= 2; // 8 , 16 , 32, ... 8192 gets the fileNumber
        
        fileNames.push_back(fileName); // pushes the file name to vector

        cout << fileName << endl;
    }

    return fileNames;
}