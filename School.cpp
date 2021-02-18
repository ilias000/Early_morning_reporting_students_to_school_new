#include "School.h"
#include <cstdlib>     
#include <ctime>
#include <iostream>
using namespace std;

School::School(const int & Cclass) // constructor
{
   cout << "A New School has been created!" << endl;
   for(int i = 0 ; i < 3 ; i++)
   {
       this->floor[i] = new Floor(i + 1, Cclass);
   }
}


School::~School() // destructor
{
    cout << "A School to be destroyed!" << endl;
    for(int i = 0 ; i < 3 ; i++)
    {
        delete this->floor[i];
    }
}
    

void School::enter(Student * student)
{
    cout << student->getName() << " enters school!" << endl;
    yard.enter(student);
    staircase.enter(yard.exit());
    floor[student->getFloorNumber() - 1]->enter(staircase.exit());
}


void School::place(Teacher * teacher)
{
    floor[teacher->getFloorNumber() - 1]->place(teacher);
}


void School::operate(int N)
{
    for(int i = 0 ; i < 3 ; i++)
    {
        floor[i]->operate(N);
    }
}


void School::print()
{
    cout << "School life consists of: " << endl;
    for(int i = 0 ; i < 3 ; i++)
    {
        cout << '\t';
        floor[i]->print();
    }
}