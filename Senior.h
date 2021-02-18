#ifndef SENIOR_H
#define SENIOR_H
#include "Student.h"
#include <iostream>
using namespace std;

class Senior : public Student
{
public:
    Senior( const string name, const int floorNumber, const int classroomNumber, const int Ls) : Student(name, floorNumber, classroomNumber, Ls){} // constructor
    ~Senior(){} // destructor

    void print() // if we did not define the function print the class Senior will be abstract because the class student is abstract
    {Student::print();}
};
#endif