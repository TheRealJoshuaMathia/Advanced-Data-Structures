// Joshua Mathia
// Assignment #2
// fileSystem.hpp file

#include "header.hpp"

class fileSystem 
{
    enum cases {one = 1, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, eleven = 11};

    public:
    vector <string> generateFileNames();
    void fileNameMenu();
    string getFileName(vector <string> &fileNames);
    int getChoiceFromUser();
    bool openFile(ifstream &input, string &fullPath);
    vector <int> readFile(ifstream &input, string &fullPath);
    bool closeFile(ifstream &input);
    string getFilePath(string &fileName);
    vector <string> generateFileArray(string &fullpath);
    fileSystem();
    ~fileSystem();
    int convertToInt(string &data);
    string getNextFile(string &fullPath, int &counter);

    private:
};
