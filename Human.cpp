#include "Human.h"
#include <iostream>
using namespace std;

void Human::print() // is pure virtual so it can not be inline
{cout << "Name = " << name << " Tiredness = " << tiredness << endl << endl;}
