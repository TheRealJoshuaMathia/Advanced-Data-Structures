// Joshua Mathia
// Assignment #2
// test_driver.cpp file

#include "test_driver.hpp"

// test_driver()
// This function is the constructor for the class test_driver
test_driver::test_driver()
{

    cout << "Starting Program... " << endl;
    cout << "---------------------" << endl;
}
// ~test_driver()
// This function is the destructor for the class test_driver
test_driver::~test_driver()
{

    cout << "Ending Program... " << endl;
    cout << "---------------------" << endl;
}

//runApp()
//This function provides the logic to run the program. 
// This function does not return anything
void test_driver::runApp()
{
    test_driver run;

    vector<string> inputFiles;
    vector<int> intArray;

    string nameOfFile;
    string fullPath;
    string textFile;

    ifstream inputFile;

    inputFiles = run.generateFileNames();

    nameOfFile = run.getFileName(inputFiles);

    fullPath = run.getFilePath(nameOfFile);

    int counter = 0;

    textFile = fullPath;

    while (counter < 10) // runs for all 0-9 text files
    {
        textFile = run.getNextFile(fullPath, counter);
        intArray = run.readFile(inputFile, textFile);

        generateReport(intArray, textFile);
        
        inputFile.close();
        pauseSystem();
        intArray.clear();

        counter++;
    }
}
//maxSubSum1()
//This function is algorithm 1
//Implementation from textbook
//Returns the maxSum found 
int test_driver::maxSubSum1(const vector<int> &intArray)
{
    int maxSum = 0;

    for (int i = 0; i < intArray.size(); ++i)
    {
        for (int j = i; j < intArray.size(); ++j)
        {
            int thisSum = 0;

            for (int k = i; k <= j; ++k)
            {
                thisSum += intArray[k];

                if (thisSum > maxSum)
                {
                    maxSum = thisSum;
                }
            }
        }
    }
    return maxSum;
}
//maxSubSum2()
//This function is algorithm 2
//Implementation is found in the book
//Returns maxSum found
int test_driver::maxSubSum2(const vector<int> &intArray)
{
    int maxSum = 0;

    for (int i = 0; i < intArray.size(); ++i)
    {
        int thisSum = 0;

        for (int j = i; j < intArray.size(); ++j)
        {
            thisSum += intArray[j];

            if (thisSum > maxSum)
            {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}
//maxSubRec()
//This function recusively searches for the maximum sum
//Returns the function maxsum3 which returns the maximum sum
int test_driver::maxSumRec(const vector<int> &intArray, int left, int right)
{
    if (left == right)
    {
        if (intArray[left] > 0)
            return intArray[left];
        else
        {
            return 0;
        }
    }

    int center = (left + right) / 2;
    int maxleftSum = maxSumRec(intArray, left, center);
    int maxRightSum = maxSumRec(intArray, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;

    for (int i = center; i >= left; --i)
    {
        leftBorderSum += intArray[i];

        if (leftBorderSum > maxLeftBorderSum)
        {
            maxLeftBorderSum = leftBorderSum;
        }
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;

    for (int j = center + 1; j <= right; ++j)
    {
        rightBorderSum += intArray[j];

        if (rightBorderSum > maxRightBorderSum)
        {
            maxRightBorderSum = rightBorderSum;
        }
    }

    return max3(maxleftSum, maxRightSum, maxLeftBorderSum, maxRightBorderSum);
}

//maxSubSum3()
//Returns the result of maxSumRec
int test_driver::maxSubSum3(const vector<int> &intArray)
{
    return maxSumRec(intArray, 0, intArray.size() - 1);
}

//maxSubSum4()
//This function is algorithm 4
//Returns maxSum
int test_driver::maxSubSum4(const vector<int> &intArray)
{
    int maxSum = 0, thisSum = 0;

    for (int j = 0; j < intArray.size(); ++j)
    {
        thisSum += intArray[j];

        if (thisSum > maxSum)
        {
            maxSum = thisSum;
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
        }
    }
    return maxSum;
}
//max3()
//This function compares the values of each max sum found in the sub problems.
//Returns the maximum Sum of all the bounds.
int test_driver::max3(int &maxleftSum, int &maxRightSum, int &maxLeftBorderSum, int &maxRightBorderSum)
{
    int maxSumCond1;
    int maxSumCond2;
    int totalMaxSum;

    // finds max between the two integers, maxLeftSum, MaxRightSum
    if (maxleftSum < maxRightSum) // Cond 1
    {
        maxSumCond1 = maxRightSum;
    }

    else if (maxleftSum > maxRightSum) // Cond 2
    {
        maxSumCond1 = maxleftSum;
    }
    // finds max between the two integers, maxLeftBorderSum, maxRightBorderSum
    else if (maxLeftBorderSum < maxRightBorderSum) // Cond 3
    {
        maxSumCond2 = maxRightBorderSum;
    }

    else if (maxLeftBorderSum > maxRightBorderSum) // Cond 4
    {
        maxSumCond2 = maxLeftBorderSum;
    }
    // finds max between the two integers, maxSumCond1, maxSumCond2
    else if (maxSumCond1 < maxSumCond2) // Cond 5
    {
        totalMaxSum = maxRightBorderSum;
    }

    else if (maxSumCond1 > maxSumCond2)
    {
        totalMaxSum = maxLeftBorderSum;
    }

    return totalMaxSum;
}
//generateReport()
//This function generates the report for each function.
//The name of the file is printed, and the timing of each function and output is displayed
//Function doesn't return anything 
void test_driver::generateReport(const vector<int> &intArray, string &fileName)
{

    cout << "Generating Report For: \n";
    cout << "-------------------\n";
    cout << fileName << endl;
    cout << "-------------------\n";
    cout << "The input file has : " << intArray.size() << " integers stored in the file." << endl;

    int maxSum1 = 0;
    int maxSum2 = 0;
    int maxSum3 = 0;
    int maxSum4 = 0;

    // Starts Execution clock
    cout << "-------------------\n";
    cout << "Running maxSubSum1" << endl;
    cout << "-------------------\n";
    auto start = high_resolution_clock::now();
    maxSum1 = maxSubSum1(intArray);
    auto stop = high_resolution_clock::now();
    // Ends execution clock

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "The Algorithm Execution Time is : " << duration.count() << " microseconds" << endl;
    cout << "The result of the max sub sequence sum is : " << maxSum1 << endl;
    cout << "-------------------\n";
    cout << "Running maxSubSum2" << endl;
    cout << "-------------------\n";
    start = high_resolution_clock::now();
    maxSum1 = maxSubSum2(intArray);
    stop = high_resolution_clock::now();
    // Ends execution clock

    duration = duration_cast<microseconds>(stop - start);
    cout << "The Algorithm Execution Time is : " << duration.count() << " microseconds" << endl;
    cout << "The result of the max sub sequence sum is : " << maxSum2 << endl;
    cout << "-------------------\n";
    cout << "Running maxSubSum3" << endl;
    cout << "-------------------\n";
    start = high_resolution_clock::now();
    maxSum3 = maxSubSum3(intArray);
    stop = high_resolution_clock::now();
    // Ends execution clock

    duration = duration_cast<microseconds>(stop - start);
    cout << "The Algorithm Execution Time is : " << duration.count() << " microseconds" << endl;
    cout << "The result of the max sub sequence sum is : " << maxSum3 << endl;
    cout << "-------------------\n";
    cout << "Running maxSubSum4" << endl;
    cout << "-------------------\n";
    start = high_resolution_clock::now();
    maxSum4 = maxSubSum4(intArray);
    stop = high_resolution_clock::now();
    // Ends execution clock

    duration = duration_cast<microseconds>(stop - start);
    cout << "The Algorithm Execution Time is : " << duration.count() << " microseconds" << endl;
    cout << "The result of the max sub sequence sum is : " << maxSum4 << endl;
}
//pauseSystem()
//This function pauses the console specifically for macOS purposes
void test_driver::pauseSystem()
{
    system("read -p 'Press Enter to continue...' var");
    //system("pause"); // uncomment for windows
}