#include "RunApp.h"

RunApp::RunApp()
{


}

RunApp::~RunApp()
{

    
}

void RunApp::startApp()
{   
    TestListMyJosephus runList;
    TestVectorMyJosephus runVector;
    
    int choice;

    while(choice != 3)
    {
        menu();
        choice = userResponse();

        if(choice == 1)
        {
            runList.runTest();
        }
        if(choice == 2)
        {
            runVector.runTest();
        }
    }
}

void RunApp::pauseSystem()
{
    system("read -p 'Press Enter to continue...' var");
    //system("pause"); // uncomment for windows
}
void RunApp::menu()
{
    cout << "Welcome to Josephus' Game" << endl;
    cout << "Run List (1), Run Vector (2), Quit Program (3) ???" << endl;
    cout << "Enter here: ";

}

int RunApp::userResponse()
{
    int userResponse = 0;
    do 
    {
        cin >> userResponse;

        if(userResponse == 1 || userResponse == 2|| userResponse == 3)
        {
            return userResponse;
        }
        else 
        {
            cout << "Invalid response! Try again..." << endl;
        }

    } while (userResponse != 1 || userResponse != 2|| userResponse != 3);
    
    return userResponse;
}
