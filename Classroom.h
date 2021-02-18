#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "Student.h"
#include "Teacher.h"
#include <iostream>
using namespace std;

class Classroom
{
    int classroomNumber, Cclass;
    Student **student;
    Teacher *teacher;
public:
    Classroom(const int &, const int &); // constructor
    ~Classroom(); // destructor

    void enter(Student *);
    void place(Teacher *);
    void operate(int);
    void print();
};
#endif