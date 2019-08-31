// Joshua Mathia
// Assignment #1
// linkedList.hpp File

#include "header.hpp"

class linkedList
{
private:
public:
    // Class Functions
    linkedList();
    ~linkedList();
    void runProgram();
    forward_list<int> createList(vector<int> &sortedVector);
    vector<int> sortVector(vector<int> &unsortedVector);
    // Program Requirments
    vector<int> readFile();
    int getMin(forward_list<int> &singlyLinkedList);
    int getMax(forward_list<int> &singlyLinkedList);
    double findMedian(forward_list<int> &singlyLinkedList);
    void generateReport(forward_list<int> &singlyLinkedList);
    // Helper Functions
    int convertToInt(string value);
    string getFileName();
};