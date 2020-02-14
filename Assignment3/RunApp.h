#ifndef RunApp_h
#define RunApp_h

#include "TestListMyJosephus.h"
#include "TestVectorMyJosephus.h"
using std::system;

class RunApp
{
    public:

    void menu();
    int userResponse();
    RunApp();
    ~RunApp();
    void pauseSystem();

    void startApp();
};
#endif