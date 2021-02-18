#ifndef JUNIOR_H
#define JUNIOR_H
#include "Student.h"
#include <iostream>
using namespace std;

class Junior : public Student
{
public:
    Junior( const string name, const int floorNumber, const int classroomNumber, const int Lj) : Student(name, floorNumber, classroomNumber, Lj){} // constructor
    ~Junior(){} // destructor  

    void print() // if we did not define the function print the class Junior will be abstract because the class student is abstract
    {Student::print();}
};
#endif