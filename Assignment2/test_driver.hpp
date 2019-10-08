// Joshua Mathia
// Assignment #2
// test_driver.hpp file

#include "fileSystem.hpp"

class test_driver : public fileSystem {

public :

test_driver();
~test_driver();
int maxSubSum1(const vector<int> &intArray);
int maxSubSum2(const vector<int> &intArray);
int maxSubSum3(const vector<int> &intArray);
int maxSumRec(const vector<int> &intArray, int left, int right);
int maxSubSum4(const vector<int> &intArray);
int max3(int & maxleftSum, int  & maxRightSum, int & maxLeftBorderSum,  int & maxRightBorderSum); 

void runApp();
void generateReport(const vector <int> &intArray, string &fileName);
void pauseSystem();

private:

};