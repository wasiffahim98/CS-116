/*This program reads the wine information that is stored in the SQL 
 * database and stores them into vectors. Once it is in the vectors, the
 * users have multiple options with what they could do with the wine 
 * information. User could find wines between a price range, between a 
 * rating range, sort it by price and sort by rating. This can help the 
 * wine users filter out the wines based on either price or rating. It 
 * displays all the wines in an organized table-like layout that has 
 * lined-up columns for every desired wine information.
*/

#include <mysql.h>             //Needed for accessing SQL Database
#include <stdio.h>            //Basic C Preprocessor
#include <stdlib.h>          //C Standard General Utilities Library
#include <iostream>         //Basic C++ Preprocessor
#include <iomanip>         //Needed for decimal precision and position
#include <string>         //Needed for use of strings
#include <vector>        //Needed for use of vectors.
#include <sstream>      //Needed for string streams
#include "dbconnect.h" //Connects to header file

using namespace std;
void printMeFirst(string name, string courseInfo);  //Print my name prototype
void firstOption(int& searchRating1, int& searchRating2);  //First Option Function prototype
void secondOption(double& searchPrice1, double& searchPrice2);  //Second Option Function prototype
void printFunction(vector<int>& ratingVec, vector<int>& vintageVec, vector<double>& priceVec, vector<string>& nameVec, vector<string>& typeVec);   //Print Function prototype
void clearVec(vector<int>& ratingVec, vector<int>& vintageVec, vector<double>& priceVec, vector<string>& nameVec, vector<string>& typeVec);    //Clear Vector Function prototype
void pushBack(vector<int>& ratingVec, vector<int>& vintageVec, vector<double>& priceVec, vector<string>& nameVec, vector<string>& typeVec, string name, int vintage, int rating,double price, string type);  //PushBack Function prototype
 
 //The Wine Class
class Wine
{
public:     //Public Members
    Wine() {}; //Default Constructor

    void setWineName(string inputName2);
    void setWineVintage(int inputVintage);
    void setWineScore(int inputScore);
    void setWinePrice(double inputPrice);
    void setWineType(string inputType);

    string getName();
    string getType();
    int getVintage();
    int getScore();
    double getPrice();
    string getWineryAddress();
    void print();

private:          //private members
    string name;
    string type;
    int vintage;
    int score;  // wine rating
    double price;
};

void Wine::setWineName(string inputName)  //setWineName assigns a value to name member.
{
    name = inputName;
}

void Wine::setWineVintage(int inputVintage)   //setWineVintage assigns a value to vintage member.
{
    vintage = inputVintage;
}

void Wine::setWineScore(int inputScore)      //setWineScore assigns a value to score member.
{
    score = inputScore;
}

void Wine::setWinePrice(double inputPrice)   //setWinePrice assigns a value to price member.
{
    price = inputPrice;
}

void Wine::setWineType(string inputType)    //setWineType assigns a value to type member.
{
    type = inputType;
}

string Wine::getName()     //getName returns the value to the name member.
{
    return name;
}

int Wine::getScore()      //getScore returns the value to the score member.
{
    return score;
}

double Wine::getPrice()    //gerPrice returns the value to the price member.
{
    return price;
}

string Wine::getType()    //getType returns the value to the type member.
{
    return type;
}
 
/*
 argv[1] - put sql command in argv[1], otherwise, just 
 use sql "show tables"
*/
int main(int argc, char* argv[])
{
  MYSQL *conn;		// the connection
  MYSQL_RES *res;	// the results
  MYSQL_ROW row;	// the results row (line by line)
 
  struct connection_details mysqlD;
  mysqlD.server = (char *)"localhost";  // where the mysql database is
  mysqlD.user = (char *)"root";		// the root user of mysql	
  mysqlD.password = (char *)"password"; // the password of the root user in mysql
  mysqlD.database = (char *)"mysql";	// the databse to pick
 
  // connect to the mysql database
  conn = mysql_connection_setup(mysqlD);
 
  res = mysql_perform_query(conn, (char *)"use wine");
  
  vector<string> nameVec;      //Vector for wine name
  vector<int> vintageVec;     //Vector for wine vintage
  vector<int> ratingVec;     //Vector for wine rating
  vector<double> priceVec;  //Vector for wine price
  vector<string> typeVec;  //Vector for wine type
  

  
  printMeFirst("Wasif Fahim","CS116 Tuesday\n Final Lab: Wine SQL");  //Printing my name
  

  // assign the results return to the MYSQL_RES pointer
  if (argc < 2)
  {
     cout << "argv[0]: " << argv[0] << endl;
     printf("\nUsage: %s  \"SQL statement here\"\n", argv[0]);
     printf("if no argument given, default is:\n %s show tables\n", argv[0]);
     res = mysql_perform_query(conn, (char *)"show tables");
     printf("MySQL Tables in mysql database:\n");
  }
  else
  {
     cout << "argv[0]: " << argv[0] << endl;     //Displays argv[0] value
     cout << "argv[1]: " << argv[1] << endl;    //Displays argv[1] value
     res = mysql_perform_query(conn, argv[1]); //Gathers data from the mySQL connection				 
   }

  while ((row = mysql_fetch_row(res)) !=NULL)    //A loop that goes through all the data stored in the mySQL database
  {
      if (argc < 2) {
         printf("%s\n", row[0]);  // only print out 1st column
      }
      else
      {
		  string inputName = row[0];	       //Storing wine name as a Wine class object	
		  int inputVintage = atoi(row[1]);    //Storing wine vintage as a Wine class object
		  int inputRating = atoi(row[2]);    //Storing wine rating as a Wine class object
		  double inputPrice = atof(row[3]); //Storing wine price as a Wine class object
		  string inputType = row[4];       //Storing wine type as a Wine class object
		  pushBack(ratingVec, vintageVec, priceVec, nameVec, typeVec, inputName, inputVintage, inputRating, inputPrice, inputType);  //Calls in the pushBack function to store wine class objects into vectors
      }
  }
  int selection;    //Needed for user selection key
  
  do{
	   cout << "\nPress the number indicated to choose your selection: " << endl;               //Prints out main menu selection
        cout << "\t1 - Display wine ratings between two inputs" << endl;                       //Description for option 1
        cout << "\t2 - Display wine prices between two inputs" << endl;                       //Description for option 2
        cout << "\t3 - Display all wines sorted by price" << endl;                           //Description for option 3
        cout << "\t4 - Display all wines sorted by score" << endl;                          //Description for option 4
        cout << "\t5 - Display all wines sorted by wineTypes, ratings and price" << endl;  //Description for option 5
        cout << "\t6 - Quit Program" << endl;                                             //Description for option 6
        //User inputs selection
        while (1) {     //If user accidentally enters in alphabet instead of letters, this loop will catch it so the program won't crash.
       if (cin >> selection )   //Takes in the selection value and checks if it is a valid number
        {
       break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }

      else
        {
      cout << "Invalid Input! Please enter in a valid numeral value." << endl;  //Displays the error message
      cin.clear();  //Allows user to reenter the searchScore.
      while (cin.get() != '\n') ;
        }
            }                                                              
        
        if(selection == 1)   //Goes into first selection where user can have wines display between rating ranges  
        {
			int searchRating1, searchRating2;                              //Declared integers for user's input for rating ranges
			clearVec(ratingVec, vintageVec, priceVec, nameVec, typeVec);  //Calls in the clearVec function to clear out the vectors
			firstOption(searchRating1, searchRating2);                   //Calls in the firstOption function to handle and carry out the user's rating ranges
			
			ostringstream cmd;          //ostringstream declaration for use in the mySQL commandline
			cmd << "select * from wineInfo where rating >= " << searchRating1 << " and rating <= " << searchRating2;    //Takes in the user's rating range input and inserts them into SQL select statements to get wines between the desired rating range
			res = mysql_perform_query(conn, (char*)cmd.str().c_str());     //Applies filtering to the mySQL database to only display desired wines from SQL statement         
			cout << endl;  //Skips line for organization
			
			while((row = mysql_fetch_row(res)) !=NULL)   //A loop that goes through all the data stored in the mySQL database
			{
				string inputName = row[0];		    //Storing wine name as a Wine class object	
				int inputVintage = atoi(row[1]);   //Storing wine vintage as a Wine class object	
				int inputRating = atoi(row[2]);   //Storing wine rating as a Wine class object	
				double inputPrice = atof(row[3]);//Storing wine price as a Wine class object	
				string inputType = row[4];      //Storing wine type as a Wine class object	
				pushBack(ratingVec, vintageVec, priceVec, nameVec, typeVec, inputName, inputVintage, inputRating, inputPrice, inputType);  //Calls in the pushBack function to store wine class objects into vectors
			}
			printFunction(ratingVec, vintageVec, priceVec, nameVec, typeVec);  //Calls in the printFunction to output the selected wine data in an organized table
		}
		else if(selection == 2)    //Goes into second selection where user can have wines display between price ranges  
		{
			double searchPrice1, searchPrice2;                              //Declared doubles for user's input for price ranges
			clearVec(ratingVec, vintageVec, priceVec, nameVec, typeVec);   //Calls in the clearVec function to clear out the vectors
			secondOption(searchPrice1, searchPrice2);                     //Calls in the secondOption function to handle and carry out the user's price ranges 
			
			ostringstream cmd;     //ostringstream declaration for use in the mySQL commandline
			cmd << "select * from wineInfo where price >= " << searchPrice1 << " and price <= " << searchPrice2;  //Takes in the user's price range input and inserts them into SQL select statements to get wines between the desired price range
			res = mysql_perform_query(conn, (char*)cmd.str().c_str());   //Applies filtering to the mySQL database to only display desired wines from SQL statement 
			cout << endl;    //Skips line for organization
			
			while((row = mysql_fetch_row(res)) !=NULL)   //A loop that goes through all the data stored in the mySQL database
			{
				string inputName = row[0];		     //Storing wine name as a Wine class object	
				int inputVintage = atoi(row[1]);    //Storing wine vintage as a Wine class object
				int inputRating = atoi(row[2]);    //Storing wine rating as a Wine class object 
				double inputPrice = atof(row[3]); //Storing wine price as a Wine class object
				string inputType = row[4];       //Storing wine type as a Wine class object
				pushBack(ratingVec, vintageVec, priceVec, nameVec, typeVec, inputName, inputVintage, inputRating, inputPrice, inputType);   //Calls in the pushBack function to store wine class objects into vectors
			}
		printFunction(ratingVec, vintageVec, priceVec, nameVec, typeVec);  //Calls in the printFunction to output the selected wine data in an organized table
		}
		else if(selection == 3)   //Goes into third selection where user can have wines display sorted by price
		{
			clearVec(ratingVec, vintageVec, priceVec, nameVec, typeVec);   //Calls in the clearVec function to clear out the vectors
			
			ostringstream cmd;    //ostringstream declaration for use in the mySQL commandline
			cmd << "select * from wineInfo order by price";   //Gives out the SQL select statement that would sort by price
			res = mysql_perform_query(conn, (char*)cmd.str().c_str());  //Applies filtering to the mySQL database to only display desired wines from SQL statement
			cout << endl;   //Skips line for organization
			
			while ((row = mysql_fetch_row(res)) !=NULL)    //A loop that goes through all the data stored in the mySQL database
			{
				string inputName = row[0];		    //Storing wine name as a Wine class object	   
				int inputVintage = atoi(row[1]);    //Storing wine vintage as a Wine class object
				int inputRating = atoi(row[2]);    //Storing wine rating as a Wine class object 
				double inputPrice = atof(row[3]); //Storing wine price as a Wine class object
				string inputType = row[4];       //Storing wine type as a Wine class object
				pushBack(ratingVec, vintageVec, priceVec, nameVec, typeVec, inputName, inputVintage, inputRating, inputPrice, inputType); //Calls in the pushBack function to store wine class objects into vectors
			}
			printFunction(ratingVec, vintageVec, priceVec, nameVec, typeVec);  //Calls in the printFunction to output the selected wine data in an organized table
		}
		else if(selection == 4)   //Goes into fourth selection where user can have wines display sorted by rating
		{
			clearVec(ratingVec, vintageVec, priceVec, nameVec, typeVec);   //Calls in the clearVec function to clear out the vectors
			
			ostringstream cmd;     //ostringstream declaration for use in the mySQL commandline
			cmd << "select * from wineInfo order by rating";     //Gives out the SQL select statement that would sort by rating
			res = mysql_perform_query(conn, (char*)cmd.str().c_str());   //Applies filtering to the mySQL database to only display desired wines from SQL statement
			cout << endl;    //Skips line for organization
			
			while ((row = mysql_fetch_row(res)) !=NULL)   //A loop that goes through all the data stored in the mySQL database
			{
				string inputName = row[0];		    //Storing wine name as a Wine class object	
				int inputVintage = atoi(row[1]);    //Storing wine vintage as a Wine class object
				int inputRating = atoi(row[2]);    //Storing wine rating as a Wine class object  
				double inputPrice = atof(row[3]); //Storing wine price as a Wine class object 
				string inputType = row[4];       //Storing wine type as a Wine class object
				pushBack(ratingVec, vintageVec, priceVec, nameVec, typeVec, inputName, inputVintage, inputRating, inputPrice, inputType);  //Calls in the pushBack function to store wine class objects into vectors
			}
			printFunction(ratingVec, vintageVec, priceVec, nameVec, typeVec);     //Calls in the printFunction to output the selected wine data in an organized table
		}
		else if(selection == 5)   //Goes into fourth selection where user can have wines display sorted by wineType, price and rating
		{
			clearVec(ratingVec, vintageVec, priceVec, nameVec, typeVec);  //Calls in the clearVec function to clear out the vectors
			
			ostringstream cmd;   //ostringstream declaration for use in the mySQL commandline
			cmd << "select * from wineInfo order by wineType, rating DESC";   //Gives out the SQL select statement that would sort by wineType, price and rating
			res = mysql_perform_query(conn, (char*)cmd.str().c_str());    //Applies filtering to the mySQL database to only display desired wines from SQL statement
			cout << endl;      //Skips line for organization
			
			while ((row = mysql_fetch_row(res)) !=NULL)    //A loop that goes through all the data stored in the mySQL database
			{
				string inputName = row[0];		      //Storing wine name as a Wine class object	     
				int inputVintage = atoi(row[1]);      //Storing wine vintage as a Wine class object
				int inputRating = atoi(row[2]);      //Storing wine rating as a Wine class object 
				double inputPrice = atof(row[3]);   //Storing wine price as a Wine class object 
				string inputType = row[4];         //Storing wine type as a Wine class object
				pushBack(ratingVec, vintageVec, priceVec, nameVec, typeVec, inputName, inputVintage, inputRating, inputPrice, inputType); //Calls in the pushBack function to store wine class objects into vectors
			}
			printFunction(ratingVec, vintageVec, priceVec, nameVec, typeVec);   //Calls in the printFunction to output the selected wine data in an organized table
		}
		else if(selection == 6)   //Outputs the exiting statement when the program closes
			cout << "Thank you for using program! Have a great day!" << endl;
		else
			cout << "Invalid Input! Please enter in a valid number!" << endl;   //Error message for entering a number not on the menu
	}while(selection != 6);    //Ends the program when the user enters in '6'
  
  /* clean up the database result set */
  mysql_free_result(res);
  /* clean up the database link */
  mysql_close(conn);
 
  return 0;       //Program executed successfully!
}

//This function takes in the two integers that the user entered in for the wine rating range and goes through input validation process so the valid values can be used for the SQL statement to list the wines between the user's desired rating range.
void firstOption(int& searchRating1, int& searchRating2)      
{
	cout << "Enter in 2 ratings between 0-100:  " << endl;   //Lets the user know to enter in 2 ratings
	
	while (1) {
    if (cin >> searchRating1 && searchRating1 >= 0 && searchRating1 <= 100)   //Takes in the searchRating1 value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }

    else
        {
      cout << "Invalid Input! Please enter in a valid numeral value between 0-100." << endl;  //Error message will display if user enters in invalid input
      cin.clear();  //Allows user to reenter the searchRating1.
      while (cin.get() != '\n') ;
        }
            }
	
	cout << "Enter in second rating: " << endl;     //Lets the user know to enter in the second rating value
	
	while (1) {
    if (cin >> searchRating2 && searchRating2 >=0 && searchRating2 <= 100)   //Takes in the searchRating2 value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
        
    else
        {
      cout << "Invalid Input! Please enter in a valid numeral value between 0-100." << endl;  //Error message will display if user enters in invalid input
      cin.clear();  //Allows user to reenter the searchRating2.
      while (cin.get() != '\n') ;
        }
            }
}

//This function takes in the two doubles that the user entered in for the wine price range and goes through input validation process so the valid values can be used for the SQL statement to list the wines between the user's desired price range.
void secondOption(double& searchPrice1, double& searchPrice2)
{
	cout << "Enter in two price: " << endl;     //Lets the user know to enter in 2 prices
	
	while (1) {
    if (cin >> searchPrice1 && searchPrice1 >= 0 )   //Takes in the searchScore value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }

    else
        {
      cout << "Invalid Input! Please enter in a valid numeral value." << endl;    //Error message will display if user enters in invalid input
      cin.clear();  //Allows user to reenter the searchPrice1.
      while (cin.get() != '\n') ;
        }
            }
	
	cout << "Enter in second price: " << endl;     //Lets the user know to enter in second price
	
	while (1) {
    if (cin >> searchPrice2 && searchPrice2 >= 0 )   //Takes in the searchScore value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }

    else
        {
      cout << "Invalid Input! Please enter in a valid numeral value." << endl;    //Error message will display if user enters in invalid input
      cin.clear();  //Allows user to reenter the searchScore.
      while (cin.get() != '\n') ;
        }
            }
}

//This function takes in all the 5 vectors in as parameters and prints outs all the vector data in an organized table layout. It also prints out the average wine price.
void printFunction(vector<int>& ratingVec, vector<int>& vintageVec, vector<double>& priceVec, vector<string>& nameVec, vector<string>& typeVec)
{
	cout << "_____________________________________________________________________________________" << endl;     //Lines added in for a table-like layout
	  
	cout << left << setw(7) << "WINE#" << setw(42) << "NAME" << setw(10) <<"VINTAGE"  << setw(8) << "RATING" << setw(10) << "PRICE" << setw(10) << "TYPE"<< endl;   //Uses setw() to perfectly lineup every column
	cout << "_____________________________________________________________________________________" << endl;     //Additional lines added for an organized table-like layout
	int k = 0;       //Initializes wine counter
	double sum = 0; //Initializes wine sum
	  for(unsigned int i=0; i<nameVec.size(); i++)    
  {
	   cout << left << setw(7) << i+1 << setw(42) << nameVec[i] << setw(10) << vintageVec[i] << setw(8) << ratingVec[i] << "$" << setw(10) << setprecision(2) << fixed << priceVec[i] << setw(10) << typeVec[i] << endl;  //Displaying all wine data in lined up columns
	   cout << "_____________________________________________________________________________________" << endl;   //Additional lines to be printed after every wine gets listed.
	   k++;     //Keeps adding on to the wine counter in order to keep track on the number of wines
	   sum += priceVec[i];   //Keeps on adding price from every wine to keep track of the total price
  }
  cout << "Total Number of Wines: " << k << endl;	//Displays the total number of wine with the wine counter
  
            cout << "Average Price: $" << setprecision(2) << fixed << sum/k << endl;    //Uses the total prices of wines and divides by number of wine to give an average price
            cout << "_____________________________________________________________________________________" << endl;    //One last lined added in for an organized layout.
		sum = 0;  //Resets the average for multiple loop iterations
}

//This function takes in all the 5 vectors in as parameters and simply clears out all the vector
void clearVec(vector<int>& ratingVec, vector<int>& vintageVec, vector<double>& priceVec, vector<string>& nameVec, vector<string>& typeVec)
{
	nameVec.clear();        //Clears out the wine name vector
	vintageVec.clear();    //Clears out the wine vintage vector
	ratingVec.clear();    //Clears out the wine rating vector
	priceVec.clear();    //Clears out the wine price vector
	typeVec.clear();    //Clears out the wine type vector
}

//This function takes in all of the 5 vectors and the 5 wine class object. The wine class objects gets added into their respective vector.
void pushBack(vector<int>& ratingVec, vector<int>& vintageVec, vector<double>& priceVec, vector<string>& nameVec, vector<string>& typeVec, string inputName, int inputVintage, int inputRating, double inputPrice, string inputType)
{	  
	nameVec.push_back(inputName);           //Adds Wine Name object into Wine Name Vector
	vintageVec.push_back(inputVintage);    //Adds Wine Vintage object into Wine Vintage Vector
	ratingVec.push_back(inputRating);     //Adds Wine Rating object into Wine Rating Vector
	priceVec.push_back(inputPrice);      //Adds Wine Price object into Wine Price Vector
	typeVec.push_back(inputType); 		//Adds Wine Type object into Wine Type Vector
}

//This function takes in my name and course name and prints it out just like every other lab did!
void printMeFirst(string name, string courseInfo)
{
    cout <<" Program written by: "<< name << endl; // put your name here
    cout <<" Course info: "<< courseInfo << endl;
    time_t now = time(0);  // current date/time based on current system
    char* dt = ctime(&now); // convert now to string for
    cout << " Date: " << dt << endl;
}
