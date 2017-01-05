/*	
 * 	The purpose of this program is to have the user enter in the names, date of births and grades for up to 30 students.
 *	The program stores all the student information into an array. After the user is done entering in the students' infos,
 *	the program will print out all of the students' infos and their course letter grade.   
*/

#include <cstdlib>
#include <iostream>
#include "student.h"
using namespace std;

const int MAX_STUDENT=30;  //Maximum number of students

typedef Student studentArrayType[MAX_STUDENT];
int k;   //To be used in the Print Loop

int main(int argc, char** argv) {

	printMeFirst("Wasif Fahim","CS116 Tuesday\n Lab 2: Structures");  //Printing my name

    Student s1;   //Student sturcture
    Person teacher;  //Person structure
	studentArrayType studentArray;  //Main variable used to store student information in arrays
    
    string grade;
    string dummy; // get rid of cin buffer
    
    
    teacher.firstName = "Ron";   //Professor's First Name
    teacher.lastName = "Sha";   //Professor's Last Name

    for (int i = 0; i < MAX_STUDENT; i++)
    {
		k++;
		cout << "Enter First name (enter Q if no more inputs): ";  //Asks user to enter in a first name
		while (1)   //Loop keeps going if user keeps entering invalid input
{
    
    bool number=false; // Is studentArray[i].name.firstName a number?
    cin.clear();
    cin.get();
    getline(cin, studentArray[i].name.firstName); // get the entire line, including spaces

    

    // Step through each character in the string until we either hit
    // the end of the string, or we rejected a character
    for (unsigned int n=0; n < studentArray[i].name.firstName.length() && !number; n++)
    {
        // If the current character is an alphabet, that's fine
        if (isalpha(studentArray[i].name.firstName[n]))
            continue;
        // If it's a space, that's fine too    
        if (studentArray[i].name.firstName[n]==' ')
			continue;

        // Otherwise we're rejecting this input
        number = true;
        cout << "Invalid Input! Only Letters!" << endl; //Prints out the error line
    }

    // If the input has been accepted, exit the while loop
    // otherwise we're going to loop again
    if (!number)
        break;
}
		if (studentArray[i].name.firstName == "Q" || studentArray[i].name.firstName == "q") //Ends the program here when user presses either uppercase or lowercase Q/q.
		{	
		break;
		getline(cin, dummy);   // get rid of cin buffer
		}

		cout << "Enter Last Name: "; //Asks user to enter in a last name
		while (1)   //Loop keeps going if user keeps entering invalid input
{
    getline(cin, studentArray[i].name.lastName); // get the entire line, including spaces

    bool number=false; // has strName been rejected?

    // Step through each character in the string until we either hit
    // the end of the string, or we rejected a character
    for (unsigned int n=0; n < studentArray[i].name.lastName.length() && !number; n++)
    {
        // If the current character is an alpha character, that's fine
        if (isalpha(studentArray[i].name.lastName[n]))
            continue;

        // If it's a space, that's fine too
        if (studentArray[i].name.lastName[n]==' ')
            continue;

        // Otherwise we're rejecting this input
        number = true;
        cout << "Invalid Input! Only Letters!" << endl;  //Prints out the error line
    }

    // If the input has been accepted, exit the while loop
    // otherwise we're going to loop again
    if (!number)
        break;
}

        cout << "Enter Birth Month: ";  //Asks user to enter in a birth month

        while (1) {     //Loop keeps going if user keeps entering invalid input
    if (cin >> studentArray[i].birthMonth &&  studentArray[i].birthMonth > 0 && studentArray[i].birthMonth < 13 )  //Checks to see if input is a valid number
        {
      break;     //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
    else {
      cout << "Invalid Input! Please input a numerical value between 1-12." << endl;   //Prints out the error line
      cin.clear();   //clears out invalid input for user to reenter
      while (cin.get() != '\n') ;   //Lets user retry the input
  }
}
	
	cout << "Enter Birth Day: ";   //Asks user to enter in a birth day

        while (1) {   //Loop keeps going if user keeps entering invalid input
    if (cin >> studentArray[i].birthDay && studentArray[i].birthDay > 0 && studentArray[i].birthDay < 32 )   //Checks to see if input is a valid number
        {
      break;     //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
    else {
      cout << "Invalid Input! Please input a numerical value between 1-31." << endl;   //Prints out the error line
      cin.clear();   //clears out invalid input for user to reenter
      while (cin.get() != '\n') ;  //Lets user retry the input
  }
}

	cout << "Enter Birth Year: ";  //Asks user to enter in a birth year

        while (1) {   //Loop keeps going if user keeps entering invalid input
    if (cin >> studentArray[i].birthYear && studentArray[i].birthYear > -1 && studentArray[i].birthYear < 10000)   //Checks to see if input is a valid number
        {
      break;     //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
    else {
      cout << "Invalid Input! Please input a numerical value between 0-9999." << endl;  //Prints out the error line
      cin.clear();   //clears out invalid input for user to reenter
      while (cin.get() != '\n') ;  //Lets user retry the input
  }
}

	cout << "Enter your Grade Percentage: ";  //Asks user to enter in a grade percentage

        while (1) {   //Loop keeps going if user keeps entering invalid input
    if (cin >> studentArray[i].courseGrade.percent && studentArray[i].courseGrade.percent > -1 && studentArray[i].courseGrade.percent < 100.1)    //Checks to see if input is a valid number
        {
      break;     //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
    else {
      cout << "Invalid Input! Please input a numerical value between 0-100." << endl;  //Prints out the error line
      cin.clear();   //clears out invalid input for user to reenter
      while (cin.get() != '\n') ; //Lets user retry the input
  }
}


	calculateGrade(studentArray, i); 	//Calls in grade calculation function to calculate the grade
	cout <<"\n\n" ;  //Spaces out the user inputs from the printed info for organization
	
    }    
    
    for (int i = 0; i < (k-1); i++)  //Separte Loop for printing out student info
    {
		cout << "\nStudent #" << i+1 << " Info: \n\n";   

        printStudent(studentArray, i);  //Calls the function that will print out the student info

        cout << "\n";
	}

    return 0;
}
