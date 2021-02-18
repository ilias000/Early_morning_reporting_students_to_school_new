#ifndef STUDENT_H
#define STUDENT_H
#include "Human.h"
#include <iostream>
using namespace std;

class Student : public Human
{
public:
    Student( const string name, const int floorNumber, const int classroomNumber, const int L) : Human(name, floorNumber, classroomNumber, L) // constructor
    {
        cout << "A New Student has been created!" << endl;
        cout << "Name = " << name << endl;
        cout << "Floor number = " << floorNumber << endl;
        cout << "Classroom number = " << classroomNumber << endl << endl;
    }

    virtual ~Student() // destructor
    {cout << "A Student to be destroyed!" << endl;}

    void attend(int N) 
    {
        for(int j = 0 ; j < N ; j++) // for every hour that school operates
            increaseTiredness();
    }

    // this class is abstract because the class human has the print function pure virtual and we dont define the function in this class
    // we want this function to be abstract because we dont want to create objects of this class and the print function of the class Human 
    // does what we want when we need to print a student
};
#endif