//This file contains all the functions that will be called and used throughout the program.

#include <cstdlib>
#include <iostream>
#include "student.h"
#include <ctime>

//Prints out my Name and current time/date.
void printMeFirst(string name, string courseInfo)
{
    cout <<" Program written by: "<< name << endl; // put your name here
    cout <<" Course info: "<< courseInfo << endl;
    time_t now = time(0);  // current date/time based on current system
    char* dt = ctime(&now); // convert now to string for
    cout << " Date: " << dt << endl;
}
	

//This function calculates the grade of every student listed in the array based on grade percentage. 
void calculateGrade(Student studentArray[], int i)
{

	if(studentArray[i].courseGrade.percent>=89)
        studentArray[i].courseGrade.grade = "A";
    else if(studentArray[i].courseGrade.percent>=79)
        studentArray[i].courseGrade.grade = "B";
    else if(studentArray[i].courseGrade.percent>=69)
        studentArray[i].courseGrade.grade = "C";
    else if (studentArray[i].courseGrade.percent>=59)
        studentArray[i].courseGrade.grade = "D";
    else
        studentArray[i].courseGrade.grade = "F";
    
}
			
//This function prints out the students' info that was stored in the array and gives out grade calculated from the calculateGrade Function. 
void printStudent(Student studentArray[], int i)
{
	
	 cout << "First Name: " << studentArray[i].name.firstName << endl;
	 cout << "Last Name: " << studentArray[i].name.lastName << endl;
	 cout << "Date Of Birth: " << studentArray[i].birthMonth << "/" << studentArray[i].birthDay << "/" << studentArray[i].birthYear << endl;
	 cout << "Course Percent: " << studentArray[i].courseGrade.percent << endl;
	 cout << "Course Letter Grade: " << studentArray[i].courseGrade.grade << endl;

}
