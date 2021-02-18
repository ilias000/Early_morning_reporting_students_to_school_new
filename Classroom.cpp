#include "Classroom.h"
#include <iostream>
using namespace std;

Classroom::Classroom(const int & classroomNumber, const int & Cclass) : classroomNumber(classroomNumber), Cclass(Cclass), teacher(NULL) // constructor
{
    cout << "A New Classroom has been created!" << endl;
    student = new Student*[Cclass];
    for(int i = 0 ; i < Cclass ; i++)
    {
        student[i] = NULL;
    }
}


Classroom::~Classroom() // destructor
{
    cout << "A Classroom to be destroyed!" << endl << endl;
    for(int i = 0 ; i < Cclass ; i++)
    {
        delete student[i];
    }
    delete[] student;
    delete teacher;
}


void Classroom::enter(Student * student)
{
    cout << student->getName() << " enters classroom!" << endl;
    for(int i = 0 ; i < Cclass ; i++) // make the first free pointer at the array of the classroom for the students point to the student that just entered the classroom
    {
        if(this->student[i] == NULL)
        {
            this->student[i] = student;
            break; 
        }
    }
    student->setIsInside();
}


void Classroom::place(Teacher * teacher)
{
    this->teacher = teacher;
    teacher->setIsInside();
}


void Classroom::operate(int N)
{
    for(int i = 0 ; i < Cclass ; i++) // for all the students of the class
    {
        student[i]->attend(N);
    }

    teacher->teach(N);
}


void Classroom::print()
{
    cout << "People in class " << classroomNumber << " are: " << endl;
    for(int i = 0 ; i < Cclass ; i++)
    {
        cout << '\t' << '\t' << '\t';
        student[i]->print();
    }
    cout << '\t' << '\t' << '\t';
    teacher->print();
}