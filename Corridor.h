#ifndef CORRIDOR_H
#define CORRIDOR_H
#include "Room.h"
#include <iostream>
using namespace std;

class Corridor : public Room
{
public:
    Corridor() // constructor
    {cout << endl << "A New Corridor has been created!" << endl;}


    ~Corridor() // destructor
    {cout << "A Corridor to be destroyed!" << endl << endl ;}


    void enter(Student * student)
    {
        cout << student->getName() << " enters corridor!" << endl;
        Room::enter(student);
    }


    Student * exit()
    {
        Student * studentToExit = Room::exit();
        cout << studentToExit->getName() << " exits corridor!" << endl;
        return studentToExit;
    }
};
#endif