#include "header.hpp"

class linkedList
{
private:
int x;
public:
    void readFile();
    string getFileName();
    void runProgram();
    linkedList(/* args */);
    ~linkedList();
};


linkedList::linkedList(/* args */)
{

}

linkedList::~linkedList()
{

}

string linkedList::getFileName()
{
    string fileName;

    cout << "Please enter the file name: " << endl;
    cin >> fileName;

    return fileName;
}

void linkedList::readFile() 
{

}

void linkedList::runProgram()
{
    string fileName;

    fileName = getFileName();
    


}