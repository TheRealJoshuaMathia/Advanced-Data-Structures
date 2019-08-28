#include "header.hpp"

class linkedList
{
    private:

    public:

        vector <int> readFile();
        vector <int> sortVector(vector <int> unsortedList);
        void runProgram();
        string getFileName();
        linkedList();
        ~linkedList();
        int convertToInt(string value);
};