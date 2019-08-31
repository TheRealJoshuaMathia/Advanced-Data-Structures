#include "linkedList.hpp"

// Global Variable
// This variable keeps track of the amount of elements in the list 
int counter = -1;


// readFile() Function
// This function creates a vector, gets the filename from the user
// and reads the textfile. The strings extracted are converted into a integer and stored in the vector.
// The Vector is returned 
vector<int> linkedList::readFile()
{
    vector<int> unsortedVector;

    string fileName;
    ifstream input;
    string buffer;
    int conversionResult;
    string delim = "\n";
    char space = ' ';
    int emptyLines;

    do
    {
        fileName = getFileName();
        input.open(fileName);
    } while (input.is_open() == false);

    while (input >> buffer) // Better way EOF wasn't the proper way
    {
        if(buffer == "\n") // Ignore newlines at end
        {
            emptyLines++;
        }
        else 
        {
            conversionResult = convertToInt(buffer);
            unsortedVector.push_back(conversionResult);
        }    
    }
    // for (int counter : unsortedVector) Prints values of unsortedVector
    // {
    //     cout << counter << endl;
    // }

    return unsortedVector;
}
//sortVector(&unsortedVector)
// This function passes unsortedVector as an argument
// using the STL algorithm class it sorts the vector.
// It returns the sorted vector
vector<int> linkedList::sortVector(vector<int> &unsortedVector)
{
    vector<int> sortedVector;
    sort(unsortedVector.begin(), unsortedVector.end());
    sortedVector = unsortedVector;

    // cout << "---------------\n"
    //      << "Testing sorted vector" << endl;
    // for (auto x : sortedVector) //Tested to see if the array was working right
    // {
    //     cout << x << endl;
    // }
    // cout << "---------------\n"
    //      << "END of testing sorted vector" << endl;
    return sortedVector;
}
 // createList()
 // This function passes the sorted vetor into the funtion.
 // Because the list is sorted, it needs to be reiterated from the 
 // back(largest values) to the front (small values).
 // This allows for the list to be populated with the smallest intergers 
 // being pushed into the front.
 // Returns a sorted singlylinked list
forward_list<int> linkedList::createList(vector<int> &sortedVector)
{
    forward_list<int> singlyLinkedList;

    vector<int>::reverse_iterator reverseIt = sortedVector.rbegin();

    for (reverseIt = sortedVector.rbegin(); reverseIt != sortedVector.rend(); reverseIt++)
    {
        singlyLinkedList.push_front(*reverseIt);
        counter++; // This variable is the size of the list
    }

    // For testing purposes prints out the values of the linked list 
    // cout << "---------------\n"
    //      << "Testing singlyLinked List" << endl;
    // for (auto count : singlyLinkedList)
    // {
    //     cout << count << endl;
    // }
    // cout << "---------------\n"
    //      << "Testing singlyLinked List" << endl;

    return singlyLinkedList;
}
// getFileName()
// This function asks the user for the name of the file, that value is stored in 
// the string fileName.
// Returns the string fileName
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
    // Fill the destructor
}
void linkedList::generateReport(forward_list<int> &singlyLinkedList)
{
    cout << "-------------------"
         << "Generating Report" << endl;
    int min;
    min = getMin(singlyLinkedList);
}
int linkedList::getMin(forward_list<int> &singlyLinkedList)
{
    int min = 0;
    min = singlyLinkedList.front();
    return min;
}
int linkedList::getMax(forward_list<int> &singlyLinkedList)
{
    int max;
    max = *max_element(singlyLinkedList.begin(), singlyLinkedList.end());
    return max;
}
double linkedList::findMedian(forward_list<int> &singlyLinkedList)
{
    int listCounter = 0;
    int median = counter / 2;
    double medianValue = 0;
    double result = 0.0;

    int testCase = counter;
    
    if (testCase % 2 == 0)
    {
        medianValue = 0;
        for (auto count = singlyLinkedList.begin(); count != singlyLinkedList.end(); count++)
        {
            listCounter++;
            if ((listCounter - 1) == median)
            {
                medianValue += *count;
            }

            if (listCounter == median)
            {
                medianValue += *count;
            }
        }
        result = medianValue / 2.0;
    
        return result;
    }
    
    else
    {
        for (auto count = singlyLinkedList.begin(); count != singlyLinkedList.end(); count++)
        {
            listCounter++;
            if ((listCounter - 1) == median)
            {
                medianValue = *count;
            }
        }

        return median;
    }
}

//This Function provides the logic for the program
void linkedList::runProgram()
{
    int x = 13;
    int y = 2;

    cout << x / y;

    vector<int> unsortedVector;

    unsortedVector = readFile();

    vector<int> sortedVector;
    sortedVector = sortVector(unsortedVector);

    forward_list<int> singlyLinkedList;

    singlyLinkedList = createList(sortedVector);

    int min;

    // Testing Execution of get min
    auto start = high_resolution_clock::now();
    min = getMin(singlyLinkedList);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"To find the min : " << duration.count() << " microseconds" << endl;
    cout << "The min is :" << min << endl;


    // Find max in linked list
    int max;

    start = high_resolution_clock::now();
    max = getMax(singlyLinkedList);
    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);
    cout <<"To find the max it took : " << duration.count() << " microseconds" << endl;
    cout << "The max is :" << max << endl;

    // Find median in linked list
    double medianValue;

    start = high_resolution_clock::now();
    medianValue = findMedian(singlyLinkedList);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout <<"To find the median it took : " << duration.count() << " microseconds" << endl;
    cout << "The median is: " << medianValue << endl;
}