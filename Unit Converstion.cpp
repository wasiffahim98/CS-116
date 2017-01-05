/*
This program is an Unit Converter. It converts from seconds to hours and minutes,
Fahrenheit to Celsius and Celsius to Fahrenheit. The user has the option to select
which unit types they want to be converted. Each selection calls in a function that
has the conversion formulas in placed.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cctype>
using namespace std;



/*    Print out the programmer’s information such as name, class information
      and date/time the program is run

       @param name -  the name of the programmer
       @param courseInfo -  the name of the course
       @return - none
*/

void printMeFirst(string name, string courseInfo)
{
    cout <<" Program written by: "<< name << endl; // put your name here
    cout <<" Course info: "<< courseInfo << endl;
    time_t now = time(0);  // current date/time based on current system
    char* dt = ctime(&now); // convert now to string for
    cout << " Date: " << dt << endl;
}

//This function converts seconds int minutes, hours and seconds.
void secondsConversion()
{
    int seconds, minutes, hours;
    cout << "Enter in the number of seconds: " << endl; //Asks the user to enter a number of seconds.
    while (1)
        {
    if (cin >> seconds && seconds >=0)  //Takes in the seconds value and checks if it is a valid positive number.
        {
      break;   //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
        else if(seconds<0)   //Error to be printed if seconds is entered in as a negative number.
        {
      cout << "Invalid Input! Please input a positive value." << endl;
      cin.clear();   //Gives user to reenter the seconds
      while (cin.get() != '\n') ;
        }
    else   //Error will keep on printing if random letters are entered in.
        {
      cout << "Invalid Input! Please input a numerical value." << endl;
      cin.clear();   //Allows user to reenter the seconds
      while (cin.get() != '\n') ;
        }
        }

    minutes = seconds / 60;  //Formulas for conversion.
    hours = minutes / 60;
    cout << seconds << " seconds is: " << int(hours) << " hours, " << int(minutes%60) << " minutes, " << int(seconds%60) << " seconds " << endl;  //Displays result
}

//This function converts the temperature from Fahrenheit to Celsius.
void fToC()
{
    double f, c;
    cout << "Enter a Fahrenheit value: ";

    while (1) {
    if (cin >> f)   //Takes in the Fahrenheit value and checks if it is a valid number
        {
      break;     //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
    else {
      cout << "Invalid Input! Please input a numerical value." << endl;
      cin.clear();   //Allows user to reenter the Fahrenheit.
      while (cin.get() != '\n') ;
  }
}
    c = (f-32)*(5.0/9.0);   //Formulas for conversion.
    cout << f << " F is equal to " << c << " C " << endl;   //Displays result
}

//This function converts the temperature from Celsius to Fahrenheit.
void cToF()
{
    double c, f;
    cout << "Enter a Celsius value: ";
    while (1) {
    if (cin >> c)   //Takes in the Celsius value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
    else
        {
      cout << "Invalid Input! Please input a numerical value." << endl;
      cin.clear();  //Allows user to reenter the Celsius.
      while (cin.get() != '\n') ;
        }
}

    f = c*(9.0/5.0) + 32.0;   //Formulas for conversion.
    cout << c << " C is equal to " << f << " F " << endl;  //Displays result
}

int selection;

//The main function gives user the option to select the unit type they would like to convert.
int main()
{
    // pass your name, your class info to function so it will print them out
    // always call this function in all of your lab
    printMeFirst("Wasif Fahim","CS116 Tuesday\n Lab 1: Unit Conversion");

 //  write your codes below  //
    do
    {
    cout << "Choose a selection below:" << endl;
    cout << "\t1 - Seconds to hours, minutes and seconds" << endl;
    cout << "\t2 - Fahrenheit to Celsius" << endl;
    cout << "\t3 - Celsius to Fahrenheit" << endl;
    cout << "\t4 - Quit" << endl;
    cin >> selection;   //User inputs their selection

    if(selection == 1)   //This selection goes to Seconds Conversion.
        secondsConversion();

    else if(selection == 2)    //This selection goes to Fahrenheit to Celsius Conversion.
        fToC();

    else if(selection == 3)    //This selection goes to Celsius to Fahrenheit Conversion.
        cToF();
        
    else if(selection == 4)   //This selection quits the program with a closing greeting.
		cout << "Thank You for using my program! Have a great day!" << endl;
		
    else                    //This statement gets printed if user selects an invalid input.
        cout << "Please enter in a valid selection" << endl;

    }while(selection != 4);  //This quits out of the program when the user selects the quit option.
}
