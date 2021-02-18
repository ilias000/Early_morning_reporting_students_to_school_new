#ifndef ROOM_H
#define ROOM_H
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

class Room
{
    Student * student; 
public:
    Room() : student(NULL){} // constructor
    virtual ~Room(){} // destructor

    // pure virtual because we want the class to be abstract so we can not create objects of the class
    virtual void enter(Student *) = 0; // enters a student
    virtual Student * exit() = 0; // exits student
};
#endif