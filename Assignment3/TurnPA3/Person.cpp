 #include "Person.h"

Person::Person()
{
    
}
Person::Person(int i)
{
    position = i;
}

 Person::~Person()
 {

 }

 void Person::print()
 {
     cout << getPostion() << ", ";
 }

 int Person::getPostion()
 {
    return this->position;
 }

 void Person::setPostion(int num)
 {
     this->position = num;

 }
