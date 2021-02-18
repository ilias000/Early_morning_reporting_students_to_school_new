#ifndef FLOOR_H
#define FLOOR_H
#include "Room.h"
#include "Classroom.h"
#include "Corridor.h"
#include <iostream>
using namespace std;

class Floor
{   
    int floorNumber;
    Classroom *classroom[6];
    Corridor corridor;
public:
    Floor(const int &, const int &); // constructor
    ~Floor(); // destructor
    
    void enter(Student *);
    void place(Teacher *);
    void operate(int);
    void print();
};
#endif