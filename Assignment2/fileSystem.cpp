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
//This function gets the initial file name, starting point from the user.
//The user would select an option from the input menu.
//The selection would get the desired fileName.
//Returns fileName
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
    int fileSize= 8;

    for(int i = 0; i < FILE_RIGHTBOUND; i++)
    {
        cout << "Enter (" << i + 1 << ")" << "for " << fileSize << " input Size" << endl;
        
        fileSize = fileSize * 2;
    }
    cout << "Please enter a number from the list: " << endl;
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

        //cout << fileName << endl;  for testing purposes
    }

    return fileNames;
}

//readFile()
//This function passes the input stream & fullPath inorder to read the file
//The function opens the file, reads the file and stores each line as a string.
//The string is then converted to an int and pushed into the vector.
//The vector is returned
vector <int> fileSystem::readFile(ifstream &inputFile, string &fullPath)
{
    vector <int> inputArray;
    bool success;
    string delim = "\n";

    success = openFile(inputFile, fullPath);

    string data;
    int emptyLines;
    int conversionResult;

    while(inputFile >> data)
    {
        if(data == delim)
        {
            emptyLines++;
        }

        else 
        {
            conversionResult = convertToInt(data);
            inputArray.push_back(conversionResult);
        }
    }
    
    // for(auto counter : inputArray) // print array
    // {
    //     cout << counter << endl;
    // }

    return inputArray;
}

//openFile()
//This function opens the file, from the path that was passed into the function
//Checks whether file was opened successfully.(Function returns true)
//Else Function returns false 
bool fileSystem::openFile(ifstream &input, string &fullPath)
{
    bool success = false;

    input.open(fullPath);

    if(input.is_open())
    {
    cout << "Opened File succesfully!" << endl;
    success = true;
    }
    else 
    {
        cout << "File didn't open successfully!" << endl;
    }

    return success;
}

//CloseFile()
//This function passes the file stream and closes the file
//Returns true if file was closed
//Else returns false
bool fileSystem::closeFile(ifstream &input)
{
    bool success = false;

    input.close(); // closes file

    if(!input.is_open()) // checks if the file is not open
    {
        cout << "File closed successfully!" << endl;
        success = true;
    }
    
    return true;
}

//getFilePath()
//This function gets the full path for the fileName
//fullPath is returned
string fileSystem::getFilePath(string &fileName)
{
    string folder = "./inputs/";
    string fullPath = folder + fileName;

    cout << fullPath << endl;

    return fullPath;
}

//convertToInt()
//This function converts the string from the input stream to an integer.
//result is returned
int fileSystem::convertToInt(string &data)
{
    int result;

    result = stoi(data);

    return result;
}

//getNextFile()
//This function passes the fullpath(fileName), and counter(text file number) variable as parameters.
//The function finds the last 0 in the file name. Creates a sub string and appends the file number and .txt to the end of the string
// Returns text File
string fileSystem::getNextFile(string &fullPath, int &counter)
{
    std::size_t found = fullPath.find_last_of("0");
    string fileName;
    string txt = ".txt";
    string textFile;
    string number;

    fileName = fullPath.substr(0,found);
    number = to_string(counter);
    
    textFile = fileName + number + txt;

    return textFile;   
}