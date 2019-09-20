// Joshua Mathia
// Assignment #2
// test_driver.cpp file

#include "test_driver.hpp"

// test_driver()
// This function is the constructor for the class test_driver
test_driver::test_driver() {

 cout << "Starting Program... " << endl;
 cout << "---------------------" << endl;

}
// ~test_driver()
// This function is the destructor for the class test_driver
test_driver::~test_driver() {

 cout << "Ending Program... " << endl;
 cout << "---------------------" << endl;

} 

void test_driver::runApp()
{
   test_driver run;
   vector <string> inputFiles;

  inputFiles = run.generateFileNames();
  run.getFileName(inputFiles);
}