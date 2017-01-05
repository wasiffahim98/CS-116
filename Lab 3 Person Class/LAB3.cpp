/*
* This program uses private and public classes to
* store name and age of a person into an array of
* up to 30. After the information is stored, the user
* could select the option to print out all the data
* that has been entered in. After that, the user could
* press the exit button to exit out of the program.
*/

#include <iostream>  //Basic Preprocessors.
#include <string>
#include <iomanip>
#include <ctime>
#include <cctype>
using namespace std;

void printMeFirst(string name, string courseInfo);  //Prints my name prototype


int selection;  //Used for user to input a selection.

//The Person class with string and integer.
class Person
{
public:
    Person();
    Person (string pname, int page);
    string getName() const;
    void setName(string pname);
    void setAge(int page);
    int getAge() const;
private:
    string name;  //Noname if unknown.
    int age;  //0 if unknown
};

Person::Person()    //Constructor for Person class
{
    name = "Noname";
    age = 0;
}

void Person::setName(string pname)   //setName assigns a value to the name member.
{
    name = pname;
}

void Person::setAge(int page)   //setAge assigns a value to the age member.
{
    age = page;
}

string Person::getName() const   //getName returns the value in the name member.
{
    return name;
}

int Person::getAge() const   //getAge returns the value in the age member.
{
    return age;
}



int main(int argc, char** argv)
{
    int k=0;   //loop counter for the print function.
    string pname;   //Input/Output variable of Name throughout the Main Function
    string dummy;  //get rid of cin buffer
    double page;    //Input/Output variable of Age throughout the Main Function
Person student[30];    //Declaration of a number of person array
void printInfo(Person[] , int);
   printMeFirst("Wasif Fahim","CS116 Tuesday\n Lab 3: Person Class");  //Printing my name

   do{       //Menu setup for the user
   cout << "\nPress the number indicated to choose your selection:" << endl;
   cout << "\t1 - Enter in Person's Information" << endl;
   cout << "\t2 - Print out the Person's Information" << endl;
   cout << "\t3 - Exit Program" << endl;
   cin >> selection;

   if(selection == 1)  //When user selects '1' they could enter in name and age
   {
       for(int i=0; i<30; i++)
       {
           k++;   //Counter for the print function
       cout << "Enter in name (Enter 'Q' to return to menu): ";

       while (1)   //Loop keeps going if user keeps entering invalid input
{

    bool number=false; // Is pname a number?
    cin.clear();    //clears invalid line
    cin.get();     //Allows user to re enter valid input
    getline(cin, pname); // get the entire line, including spaces



    // Step through each character in the string until we either hit
    // the end of the string, or we rejected a character
    for (unsigned int n=0; n < pname.length() && !number; n++)
    {
        // If the current character is an alphabet, that's fine
        if (isalpha(pname[n]))
            continue;
        // If it's a space, that's fine too
        if (pname[n]==' ')
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

    if (pname == "Q" || pname == "q") //Ends the program here when user presses either uppercase or lowercase Q/q.
		{
		break;
		getline(cin, dummy);   // get rid of cin buffer
		}

       student[i].setName(pname);   //Store the name of student in the Person object.


       cout << "Enter in age: ";
      // cin >> birth;

        while (1) {     //Loop keeps going if user keeps entering invalid input
    if (cin >> page &&  page > 0 && page < 141 )  //Checks to see if input is a valid number
        {
      break;     //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
    else {
      cout << "Invalid Input! Please input a numerical value between 1-140." << endl;   //Prints out the error line
      cin.clear();   //clears out invalid input for user to reenter
      while (cin.get() != '\n') ;   //Lets user retry the input
  }
}

       student[i].setAge(page);    //Store the age of student in the Person object.

       }
   }

   else if(selection == 2)    //If user selects '2' it prints out the information.
   {
       printInfo(student, k);   //Calls in the print function to print out the information.
   }

   else if(selection ==3)   //If user selects '3' its prints the closing line and ends the program.
   {
       cout << "Thank You for using my program! Have a nice day!" << endl;   //closing line
   }

   else
   {
       cout << "Invalid Input! Please enter in a valid selection!" << endl;   //error line for invalid input
   }

   }while( selection!=3);   //Ends the program if user inputs '3'
}

void printMeFirst(string name, string courseInfo)
{
    cout <<" Program written by: "<< name << endl; // put your name here
    cout <<" Course info: "<< courseInfo << endl;
    time_t now = time(0);  // current date/time based on current system
    char* dt = ctime(&now); // convert now to string for
    cout << " Date: " << dt << endl;
}


void printInfo(Person student[], int i)
{
    for(int p=0;p<i-1;p++)
    {
        cout << "\nPerson Number " << p+1 << ": " << endl;   //Indicates which person the information is for.
        cout << "Name: " << student[p].getName() << endl;   //Outputs the name
        cout << "Age: " << student[p].getAge() << "\n\n";  //Outputs the age
    }
}

