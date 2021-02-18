#ifndef SCHOOL_H
#define SCHOOL_H
#include "Floor.h"
#include "Yard.h"
#include "Staircase.h"
#include <iostream>
using namespace std;

class School
{
    Floor *floor[3];
    Yard yard;
    Staircase staircase;
public:
    School(const int &); // constructor
    ~School(); // destructor

    void enter(Student *);
    void place(Teacher *);
    void operate(int);
    void print();
};
#endif