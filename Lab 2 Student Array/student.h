//This file is the header portion that lists the function prototypes and structures that will be used throughout the program.

#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;


//Sturcture for the first and last names.
struct Person {
	string lastName, firstName;
};

//Structure for grade percentage and letter grade.
struct GradeRec {
	float percent;
	string grade;
};

//Structure for all the student information like DOB, name and grade.
struct Student {
    	Person name;
    	int birthYear, birthMonth, birthDay;
	GradeRec courseGrade;
};

void printMeFirst(string name, string courseInfo);  //Function prototype for printMeFirst.

void printStudent(Student studentArray[], int i);  //Function prototype for printStudent.

void calculateGrade(Student studentArray[], int i);  //Function prototype for calculateGrade.

#endif
