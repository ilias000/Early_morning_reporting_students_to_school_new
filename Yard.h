#ifndef YARD_H
#define YARD_H
#include "Room.h"
#include <iostream>
using namespace std;

class Yard : public Room
{
public:
    Yard() // constructor
    {cout << "A New Yard has been created!" << endl << endl;}


    ~Yard() // destructor
    {cout << "A Yard to be destroyed!" << endl << endl;}


    void enter(Student * student)
    {
        cout << student->getName() << " enters schoolyard!" << endl;
        Room::enter(student);
    }


    Student * exit()
    {
        Student * studentToExit = Room::exit();
        cout << studentToExit->getName() << " exits schoolyard!" << endl;
        return studentToExit;
    }
};
#endif