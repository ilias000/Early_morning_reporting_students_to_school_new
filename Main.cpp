#include "School.h"
#include "Junior.h"
#include "Senior.h"
#include <cstdlib>     
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "                             --- THE PROGRAM STARTED ---                                 " << endl ;

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;
	cout << "                       1. Να δημιουργείται ένα σχολικό κτήριο." << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;

	cout << "                                ~ Creating School ~ " << endl << endl;

	int Cclass = stoi(argv[1]), Lj = stoi(argv[2]), Ls = stoi(argv[3]), Lt = stoi(argv[4]), N = stoi(argv[5]);
	cout << "Cclass = " << Cclass << endl;
	cout << "Lj = " << Lj << endl;
	cout << "Ls = " << Ls << endl;
	cout << "Lt = " << Lt << endl;
	cout << "N = " << N << endl << endl;
	School school(Cclass);

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;
	cout << "                       2. Να δημιουργούνται οι μαθητές και οι δάσκαλοί του." << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;

	cout << "                                ~ Creating Students ~ " << endl << endl;
	
	srand((unsigned) time(0));
	int totalNumberOfStudents = 18 * Cclass;
	Student * student[totalNumberOfStudents]; // creating a array of pointers to Student objects 

	for(int i = 1, floorNumber = 1, classroomNumber = 1, studentForThisClass = 0 ; i <= totalNumberOfStudents ; i++)
	{
		// random names
		string name[] = {"ΜΑΡΙΑ", "ΕΛΕΝΗ", "ΓΕΩΡΓΙΟΣ", "ΑΙΚΑΤΕΡΙΝΗ", "ΒΑΣΙΛΙΚΗ", "ΚΛΑΙΡΗ", "ΚΩΝΣΤΑΝΤΙΝΟΣ", "ΙΩΑΝΝΗΣ", "ΝΙΚΟΛΑΟΣ", "ΓΕΩΡΓΙΑ", "ΣΟΦΙΑ", "ΑΝΑΣΤΑΣΙΑ", "ΕΥΑΓΓΕΛΙΑ", "ΙΩΑΝΝΑ", "ΧΡΗΣΤΟΣ", "ΠΑΝΑΓΙΩΤΗΣ", "ΒΑΣΙΛΕΙΟΣ", "ΑΘΑΝΑΣΙΟΣ", "ΜΙΧΑΗΛ", "ΣΠΥΡΙΔΩΝ"}; // array to choose a random name 	
		if(classroomNumber <= 3) // is a classroom with Junior students
			student[i-1] = new Junior(name[rand() % 20], floorNumber, classroomNumber, Lj); // creating Junior student with random name and inserting him to the array
		else // else is a classroom with Senior students
			student[i-1] = new Senior(name[rand() % 20], floorNumber, classroomNumber, Ls); // creating Senior student with random name and inserting him to the array
		studentForThisClass++;
		if(studentForThisClass == Cclass) // this class is full
		{
			classroomNumber++;
			studentForThisClass = 0;
			if(classroomNumber == 7) // all the classrooms of the floor are full
			{
				floorNumber++;
				classroomNumber = 1;
			}
		}
	}

cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "                                ~ Creating Teachers ~ " << endl << endl;


	Teacher * teacher[18]; // creating a array of pointers to Teacher objects 

	for(int i = 1, floorNumber = 1, classroomNumber = 1 ; i <= 18 ; i++, classroomNumber++)
	{
		// random names
		string name[] = {"ΜΑΡΙΑ", "ΕΛΕΝΗ", "ΓΕΩΡΓΙΟΣ", "ΑΙΚΑΤΕΡΙΝΗ", "ΒΑΣΙΛΙΚΗ", "ΚΛΑΙΡΗ", "ΚΩΝΣΤΑΝΤΙΝΟΣ", "ΙΩΑΝΝΗΣ", "ΝΙΚΟΛΑΟΣ", "ΓΕΩΡΓΙΑ", "ΣΟΦΙΑ", "ΑΝΑΣΤΑΣΙΑ", "ΕΥΑΓΓΕΛΙΑ", "ΙΩΑΝΝΑ", "ΧΡΗΣΤΟΣ", "ΠΑΝΑΓΙΩΤΗΣ", "ΒΑΣΙΛΕΙΟΣ", "ΑΘΑΝΑΣΙΟΣ"}; // array to choose a random name 
		// we want every teacher to have a different classroom
		teacher[i-1] = new Teacher(name[rand() % 18], floorNumber, classroomNumber, Lt); // creating teachers with random names and inserting them to the array
		if(classroomNumber == 6)
		{
			floorNumber++;
			classroomNumber = 0; 
		}
	}

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                       3. Να μπαίνουν μαθητές και να τοποθετούνται δάσκαλοι στο σχολικό κτήριο με τυχαία σειρά" << endl; 	
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	int randomIndexOfStudent, randomIndexOfTeacher;
	for(int i = 0 ; i < totalNumberOfStudents ; i++) // entering all the students 
	{
		do // random student to enter
		{
			randomIndexOfStudent = rand() % totalNumberOfStudents; // random number between [0 , total number of students)
		}while(student[randomIndexOfStudent] == NULL); // if the student has already entered find another random one
		school.enter(student[randomIndexOfStudent]);
		student[randomIndexOfStudent] = NULL;
		cout << endl;
	}

	for(int i = 0 ; i < 18 ; i++) // entering all the teachers 
	{
		do // random teacher to enter
		{
			randomIndexOfTeacher = rand() % 18; // random number between [0 , 18)
		}while(teacher[randomIndexOfTeacher] == NULL); // if the teacher has already entered find another random one
		school.place(teacher[randomIndexOfTeacher]);
		teacher[randomIndexOfTeacher] = NULL;
	}

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;
	cout << "                       4. Το σχολικό κτήριο να λειτουργεί για N ώρες." << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;

	school.operate(N);


	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;
	cout << "                       5. Να εκτυπώνεται το σχολικό κτήριο." << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;

	school.print();

	
	// cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	// cout << "                                ~ Deleting Students ~ " << endl << endl;
	// // delete students
	// for(int i = 0 ; i < 18 * Cclass ; i++)
	// {
	// 	delete student[i];
	// }

	// cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	// cout << "                                ~ Deleting Teachers ~ " << endl << endl;
	// // delete teachers
	// for(int i = 0 ; i < 18 ; i++)
	// {
	// 	delete teacher[i];
	// }
	
	cout << "                             --- THE PROGRAM ENDED ---                                 " << endl << endl ;
	return 0;
}