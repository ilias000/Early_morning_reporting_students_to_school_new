#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include <iostream>
using namespace std;

class Human 
{
protected:
    string name;
    int floorNumber, classroomNumber, tiredness, L;
    bool inside; // if inside == TRUE is inside the classroom 
public:
    Human(const string name, const int floorNumber, const int classroomNumber, const int L) : name(name), floorNumber(floorNumber), classroomNumber(classroomNumber), tiredness(0), L(L), inside(false) // constructor
    {}

    virtual ~Human() // destructor
    {
        cout << "Name = " << name << endl;
        cout << "Floor number = " << floorNumber << endl;
        cout << "Classroom number = " << classroomNumber << endl;
        cout << "Is inside = " << inside << endl;
        cout << "Tiredness = " << tiredness << endl << endl;
    }

    string getName() const
    {return name;}

    int getClassroomNumber() const
    {return classroomNumber;}

    int getFloorNumber() const
    {return floorNumber;}

    void setIsInside()
    {inside = true;}

    void increaseTiredness() // increases tiredness by L
    {tiredness = tiredness + L;}

    virtual void print() = 0; // is pure virtual because we want the class to be abstract so we can not create objects of the class

};
#endif