#include "linkedList.hpp"

vector <int> linkedList::readFile()
{
    vector <int> unsortedList;

    string fileName;
    ifstream input;
    string buffer;
    int conversionResult;
    do
    {
        fileName = getFileName();
        input.open(fileName);
    } while (input.is_open() == false);
     
    while(!input.eof())
     {   
        getline(input, buffer);
        conversionResult = convertToInt(buffer);
        unsortedList.push_back(conversionResult);
     }

    for(int counter : unsortedList)
    {
        cout << counter << endl;
    }

    return unsortedList;
}

 vector <int> linkedList::sortVector(vector <int> unsortedList)
 {
     vector <int> sortedVector;
     sort(unsortedList.begin(), unsortedList.end());
     sortedVector = unsortedList;
     
     return sortedVector;
 }

void linkedList::runProgram()
{
    vector <int> unsortedVector;

    unsortedVector = readFile();
    vector <int> sortedVector;

    sortedVector = sortVector(unsortedVector);

    for(auto x : sortedVector)
    {
        cout << x;
    }
}
string linkedList::getFileName()
{
    string fileName;

    cout << "Enter the name of the input file: " << endl;

    cin >> fileName;

    return fileName;
}

 int linkedList::convertToInt(string value)
 {
     int result;

     result = stoi(value);
     
     return result;

 }
linkedList::linkedList()
{
    cout << "Object is being Created" << endl;
}
linkedList::~linkedList()
{
}
