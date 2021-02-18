#ifndef STAIRCASE_H
#define STAIRCASE_H
#include "Room.h"
#include <iostream>
using namespace std;

class Staircase : public Room
{
public:
    Staircase() // constructor
    {cout << "A New Stairecase has been created!" << endl << endl;}


    ~Staircase() // destructor
    {cout <<"A Stairecase to be destroyed!" << endl << endl;}


    void enter(Student * student)
    {
        cout << student->getName() << " enters stairs!" << endl;
        Room::enter(student);
    }


    Student * exit()
    {
        Student * studentToExit = Room::exit();
        cout << studentToExit->getName() << " exits stairs!" << endl;
        return studentToExit;
    }
};
#endif