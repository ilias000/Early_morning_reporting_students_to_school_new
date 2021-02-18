#ifndef TEACHER_H
#define TEACHER_H
#include "Human.h"
#include <iostream>
using namespace std;

class Teacher : public Human
{
public:
    Teacher(const string name, const int floorNumber, const int classroomNumber, const int Lt) : Human(name, floorNumber, classroomNumber, Lt) // constructor
    {
        cout << "A New Teacher has been created!" << endl;
        cout << "Name = " << name << endl;
        cout << "Floor number = " << floorNumber << endl;
        cout << "Classroom number = " << classroomNumber << endl << endl;
    }

    ~Teacher() // destructor
    {cout << "A Teacher to be destroyed!" << endl;}

    void teach(int N)
    {
        for(int j = 0 ; j < N ; j++) // for every hour that school operates
            increaseTiredness();
    }

    void print()
    {
        cout << "The teacher is : " << endl;
        cout << '\t' << '\t' << '\t';
        Human::print();
    }
};
#endif