#include "Floor.h"
#include <iostream>
using namespace std;

Floor::Floor(const int & floorNumber, const int & Cclass) : floorNumber(floorNumber) // constructor
{
    cout << "A New Floor has been created!" << endl;
    for(int i = 0 ; i < 6 ; i++)
    {
        this->classroom[i] = new Classroom(i + 1, Cclass);
    }
}


Floor::~Floor() // destructor
{
    cout << endl << "A Floor to be destroyed!" << endl << endl;
    for(int i = 0 ; i < 6 ; i++)
    {
        delete this->classroom[i];
    }
}


void Floor::enter(Student * student)
{
    cout << student->getName() << " enters floor!" << endl;
    corridor.enter(student);
    classroom[student->getClassroomNumber() - 1]->enter(corridor.exit());
}


void Floor::place(Teacher * teacher)
{
    classroom[teacher->getClassroomNumber() - 1]->place(teacher);
}


void Floor::operate(int N)
{
    for(int i = 0 ; i < 6 ; i++)
    {
        classroom[i]->operate(N);
    }
}

void Floor::print()
{
    cout << " Floor number " << floorNumber << " contains: " << endl;
    for(int i = 0 ; i < 6 ; i++)
    {
        cout  << '\t' << '\t'; 
        classroom[i]->print();
    }
}