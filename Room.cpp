#include "Room.h"
#include <iostream>
using namespace std;

// is pure virtual so it can not be inline
void Room::enter(Student * student) // enters student
{
    this->student = student;
}


// is pure virtual so it can not be inline
Student * Room::exit() // exits student
{
    Student * studentToExit = student;
    student = NULL;
    return studentToExit;
}



