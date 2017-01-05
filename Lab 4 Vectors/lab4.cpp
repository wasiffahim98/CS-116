/*
*  This program reads through a list of names in a textfile.
*  From the textfile, all the user informations are stored in
*  vectors. The user has the option to search the last name
*  of the person, and if the person is found from the list,
*  then all of his/her info will print. The user also has the
*  second option to simply print all the people's info that
*  is stored on the textfile. After that, the user could quit
*  the program with the last option.
*/

#include <iostream>   //Basic Preprocessors
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
void printMeFirst(string name, string courseInfo);  //Prints my name prototype
int selection;  //Needed for menu selection

//The Person class with string and integer.
class Person
{
public:
    Person();
    Person(string fname, string lname, string s, int byear, int bmth, int bday);
    string findName(string lname) const;
    void setName(string fname, string lname);
    void setSex(string s);
    void setDob(int byear, int bmth, int bday);
    string getName() const;
    string getSex() const;
    int getDob() const;

private:
    string firstName;
    string lastName;
    string sex;
    int birthYear;
    int birthMonth;
    int birthDay;
};

Person::Person()   //Constructor for Person class
{
    firstName = "NoName";
    birthYear = 0;
}

void Person::setName(string fname, string lname)  //setName assigns a value to the firstName and lastName member.
{
    firstName = fname;
    lastName = lname;
}

void Person::setSex(string s)   //setSex assigns a value to the sex member.
{
    sex = s;
}

void Person::setDob(int byear, int bmth, int bday)   //setDob assigns a value to the birthYEear, birthMonth and birthDay member.
{
    birthYear = byear;
    birthMonth = bmth;
    birthDay = bday;
}

string Person::getName() const   //getName returns the value in the firstName and lastName member.
{
    return firstName;
    return lastName;
}

string Person::getSex() const   //getSex returns the value in the sex member.
{
    return sex;
}

int Person::getDob() const     //getDob returns the value in the birthYear, birthMonth and birthDay member.
{
    return birthYear;
    return birthMonth;
    return birthDay;
}



main(int argc, char* argv[])   //Main Function
{
    printMeFirst("Wasif Fahim","CS116 Tuesday\n Lab 4: Vector");  //Printing my name
    Person president;   //Declaring variable with class object
    int counter =0;    //Initializes loop counter
    string search;    //Allows user to enter last name to seach
    string fname, lname, s;     //String declaration for first name, last name and sex
    int byear, bmth, bday;     //Integer declaration for birth year, month and day
    bool found = false;       //Declaring the boolean variable
    vector<string> fName;    //Declaring string vector for first name
    vector<string> lName;   //Declaring string vector for last name
    vector<string> gender; //Declaring string vector for sex
    vector<int> yBirth;   //Declaring integer vector for birth year
    vector<int> mBirth;  //Declaring integer vector for birth month
    vector<int> dBirth; //Declaring integer vector for birth day
    ifstream read;     //Declaring file output variable
    read.open("personsInfo.txt");    //Opens up the text file

      do{     //Do-while loop to read through the file
     read >> fname >> lname >> s >> byear >> bmth >> bday;   //Reads through every word in a line and assigns it the variable in order
    fName.push_back(fname+" "+lname);                       //Adding element into first name vector
    lName.push_back(lname);                                //Adding element into last name vector
    yBirth.push_back(byear);                              //Adding element into birth year vector
    mBirth.push_back(bmth);                              //Adding element into birth month vector
    gender.push_back(s);                                //Adding element into gender vector
    dBirth.push_back(bday);                            //Adding element into birth year vector
    }while(!read.eof());                              //Loop ends when it is done reading through whole file

    do{      //Do-while loop to keep the menu going
        cout << "\nPress the number indicated to choose your selection: " << endl;  //Prints out main menu selection
        cout << "\t1 - Search by Last Name" << endl;                               //Description for option 1
        cout << "\t2 - Print out the current database" << endl;                   //Description for option 2
        cout << "\t3 - Exit Program" << endl;                                    //Description for option 3
        cin >> selection;     //Has user input their selection

        if(selection == 1)  //Goes into first selection
        {

    cout << "Enter Last Name: ";

    while (1)   //Loop keeps going if user keeps entering invalid input
{

    bool number=false; // Is search a number?
    cin.clear();    //clears invalid line
    cin.get();     //Allows user to re enter valid input
    getline(cin, search); // get the entire line, including spaces



    // Step through each character in the string until we either hit
    // the end of the string, or we rejected a character
    for (unsigned int n=0; n < search.length() && !number; n++)
    {
        // If the current character is an alphabet, that's fine
        if (isalpha(search[n]))
            continue;
        // If it's a space, that's fine too
        if (search[n]==' ')
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
    counter = 0;   //Resets counter for multiple uses
    for(int k=0; k<lName.size()-1;k++)
    {
    if(search.compare(lName[k])==0)    //If name is found, then it prints it out
        {
            cout << "\nName: " << fName[k] << endl;     //Prints out full name
            cout << "Sex: " << gender[k] << endl;      //Prints out sex
            cout << "DOB:" << mBirth[k]  << "/" << dBirth[k]  << "/" << yBirth[k] << endl;   //Prints out DOB
            found = true;
            counter++;
        }
        else if(counter<1)   //Breaks out of loop to go back to menu
            {
                found = false;
            }

        }
    if(!found)   //Print out "Not Found" if the name cannot be found

    cout << "Not Found" << endl;
    }

    else if(selection == 2)   //Goes into second selection
        {
            for(int i =0; i<(fName.size()-1); i++)  //Loops through the list in order to print out everyone
            {
            cout << "\nPerson #" << i+1;
            cout << "\nName: " << fName[i] << endl;         //Prints out full name
            cout << "Sex: " << gender[i] << endl;          //Prints out sex
            cout << "DOB:" << mBirth[i]  << "/" << dBirth[i]  << "/" << yBirth[i] << endl;  //Prints out DOB
            }
        }

    else if(selection == 3)   //Goes into third selection
        {
            cout << "Thank You for using my program! Have a nice day!" << endl;   //closing line
        }

        else
            cout << "Invalid Input! Please enter in a valid selection!" << endl;   //error line for invalid input

    }while(selection!=3);       //Quits the program if user enters 3
read.close();                  //Closes the file
    return 0;
}

void printMeFirst(string name, string courseInfo)
{
    cout <<" Program written by: "<< name << endl; // put your name here
    cout <<" Course info: "<< courseInfo << endl;
    time_t now = time(0);  // current date/time based on current system
    char* dt = ctime(&now); // convert now to string for
    cout << " Date: " << dt << endl;
}
