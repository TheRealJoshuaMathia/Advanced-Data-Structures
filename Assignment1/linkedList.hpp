#include "header.hpp"

class linkedList
{
private: 
public:
    vector<int> readFile();
    vector<int> sortVector(vector<int> &unsortedVector);
    void runProgram();
    forward_list<int> createList(vector<int> &sortedVector);
    string getFileName();
    
    void generateReport(forward_list<int>&singlyLinkedList);
    int getMin(forward_list<int>&singlyLinkedList);
    int getMax(forward_list<int>&singlyLinkedList);
    double findMedian(forward_list<int>&singlyLinkedList);

    linkedList();
    ~linkedList();
    // Helper Functions
    int convertToInt(string value);
};