/*  This program reads through two files
 *  of winelist and winery files. After
 *  reading the files, it stores the
 *  information from the files into
 *  individual vectors. After it is
 *  stored, the user has the option to
 *  find wines through price ranges and
 *  score ranges. The program could also
 *  sort the wines by price and score. If none
 *  of those work for the user, they could always
 *  just search for the specific wine type they
 *  are looking for. This application can come in
 *  handy for the holiday seasons.
 */

#include <iostream>   //Basic Preprocessor
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>  // used for sort
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;
void printMeFirst(string name, string courseInfo);  //Print my name prototype
//The Winery class
class Winery
{
public:
    Winery();
    Winery(string inputName, string inputAddr, string inputStreet,
           string inputCity, string inputState, string inputZip, string inputCountry);

    string getName() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    string getCountry() const;
    void setName(string inputName);
    void setAddress(string inputAddr);
    void setCity(string inputCity);
    void setState(string inputState);
    void setCountry(string inputCountry);

private:
    int    id;
    string wineryName;
    string street, city, state, country;
    string addr, zip;
};

//THe Wine Class
class Wine
{
public:
    Wine();

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

private:
    string name;
    string type;
    int vintage;
    int score;  // wine rating
    double price;

    Winery *wineryOrigin;
};

void Wine::setWineName(string inputName2)  //setWineName assigns a value to name member.
{
    name = inputName2;
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

void Winery::setName(string inputName)    //setName assigns a value to wineryName member.
{
    wineryName = inputName;
}

void Winery::setAddress(string inputAddr)   //setAddress assigns a value to street member.
{
    street = inputAddr;
}

void Winery::setCity(string inputCity)     //setCity assigns a value to city member.
{
    city = inputCity;
}

void Winery::setState(string inputState)   //setState assigns a value to state member.
{
    state = inputState;
}

void Winery::setCountry(string inputCountry)   //setCountry assigns a value to country member.
{
    country = inputCountry;
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

string Winery::getName() const   //getName returns the value to the wineryType member.
{
    return wineryName;
}

string Winery::getAddress() const    //getAddress returns the value to the street member.
{
    return street;
}

string Winery::getCity() const     //getCity returns the value to the city member.
{
    return city;
}

string Winery::getState() const     //getState returns the value to the state member.
{
    return state;
}

string Winery::getCountry() const      //getCountry returns the value to the country member.
{
    return country;
}

int main()
{
    printMeFirst("Wasif Fahim","CS116 Tuesday\n Lab 5: Winery");  //Printing my name
    int selection;   //For use in menu selection
    string inputName, inputAddr, inputCity, inputState, inputCountry;   //String variables from Winery class
    string text;   //Used for reading file

    int searchScore, searchScore2, searchPrice, searchPrice2;   //Used for finding price and score range

    string inputName2, inputType;      //String variables from Wine class
    int inputVintage, inputScore;     //Integer variable from Wine class
    double inputPrice;               //Double variable from Wine class

    string sVintage, sScore, sPrice;   //Strings used to convert string output into integer/double


    vector<string> name2Vec;        //Declaring string vector for wine name
    vector<string> typeVec;        //Declaring string vector for wine type
    vector<int> vintageVec;       //Declaring integer vector for wine vintage
    vector<int> scoreVec;        //Declaring integer vector for wine score
    vector<double> priceVec;    //Declaring double vector for wine price

    vector<Wine *> wineList;    //Declaring wine pointer vector  for winelist

    vector<string> nameVec;        //Declaring string vector for winery name
    vector<string> addrVec;       //Declaring string vector for winery address
    vector<string> cityVec;      //Declaring string vector for winery city
    vector<string> stateVec;    //Declaring string vector for winery state
    vector<string> countryVec; //Declaring string vector for winery country



    ifstream readWinery ("wineryRev.txt");       //Reads the winery file
    ifstream readWinelist ("winelistRev.txt");  //Reads the winelist file
   // readWinery.open("winery.txt");

    if (readWinery.is_open())   //Reads every line of the winery file when it is open
  {
		while (getline(readWinery, text))   //Puts items from file into a text
		{
        istringstream ss (text);   //Places the text in a stringstream

		getline(ss, inputName, ';');          //Gets stringstream and stores into inputName string
		getline(ss, inputAddr, ';');         //Gets stringstream and stores into inputAddr string
		getline(ss, inputCity, ';');        //Gets stringstream and stores into inputCity string
        getline(ss, inputState, ';');      //Gets stringstream and stores into inputState string
        getline(ss, inputCountry, ';');   //Gets stringstream and stores into inputCountry string

		nameVec.push_back(inputName);           //Adds in every inputName string into name vector
        addrVec.push_back(inputAddr);          //Adds in every inputAddr string into address vector
        cityVec.push_back(inputCity);         //Adds in every inputCity string into city vector
        stateVec.push_back(inputState);      //Adds in every inputState string into state vector
        countryVec.push_back(inputCountry); //Adds in every inputCountry string into country vector
	}
        readWinery.close();   //Closes the winery file
  }
  else
    cout << "Unable to open file";   //Error message if it can't be opened


	while(getline(readWinelist, text))   //Puts items from file into a text
        {
            istringstream ss (text);    //Places the text in a stringstream

        getline(ss, inputName2, ';');       //Gets stringstream and stores into wine Name string
        getline(ss, inputType, ';');       //Gets stringstream and stores into wine type string
        getline(ss, sVintage, ';');       //Gets stringstream and stores into wine vintage string
        getline(ss, sScore, ';');        //Gets stringstream and stores into wine score string
        getline(ss, sPrice, ';');       //Gets stringstream and stores into wine price string

        stringstream convert(sVintage);   //Converts wine vintage string into integer
        convert >> inputVintage;
        stringstream convert2(sScore);   //Converts wine score string into integer
        convert2 >> inputScore;
        stringstream convert3(sPrice);   // Converts wine price string into double
        convert3 >> inputPrice;

        name2Vec.push_back(inputName2);             //Adds in every wine Name string into wine name vector
        typeVec.push_back(inputType);              //Adds in every wine type string into wine type vector
        vintageVec.push_back(inputVintage);       //Adds in every wine vintage string into wine vintage vector
        scoreVec.push_back(inputScore);          //Adds in every wine score string into wine score vector
        priceVec.push_back(inputPrice);         //Adds in every wine price string into wine price vector
	}



	do{
        cout << "\nPress the number indicated to choose your selection: " << endl;          //Prints out main menu selection
        cout << "\t1 - Display wine scores between two inputs" << endl;                    //Description for option 1
        cout << "\t2 - Display wine prices between two inputs" << endl;                   //Description for option 2
        cout << "\t3 - Display all wines sorted by price" << endl;                       //Description for option 3
        cout << "\t4 - Display all wines sorted by score" << endl;                      //Description for option 4
        cout << "\t5 - Search for wines by type" << endl;                              //Description for option 5
        cout << "\t6 - Quit Program" << endl;                                         //Description for option 6
        cin >> selection;                                                            //User inputs selection


        if(selection == 1)   //Goes into option 1
        {
            cout << "Enter in 2 scores between 0-100: ";
            while (1) {
    if (cin >> searchScore && searchScore >= 0 && searchScore <= 100)   //Takes in the searchScore value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }

    else
        {
      cout << "Invalid Input! Please enter in a valid numeral value between 0-100." << endl;
      cin.clear();  //Allows user to reenter the searchScore.
      while (cin.get() != '\n') ;
        }
            }

           cout << "Enter in the second number: ";

            while (1) {
    if (cin >> searchScore2 && searchScore2 >=0 && searchScore2 <= 100)   //Takes in the searchScore2 value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }


    else
        {
      cout << "Invalid Input! Please enter in a valid numeral value between 0-100." << endl;
      cin.clear();  //Allows user to reenter the searchScore2.
      while (cin.get() != '\n') ;
        }
            }
            int k = 0;    //Initializes the Loop counter
            double sum = 0;   //Initialize Sum for average
            for(int i = 0; i < name2Vec.size(); i++)
            {
                if(scoreVec[i] >= searchScore && scoreVec[i] <= searchScore2)   //Compares searchScore and searchScore2 string with wine score vector
                {
                    k++;   //counter for average price
                    cout << "Name: " << name2Vec[i] << endl;
                    cout << "Wine Type: " << typeVec[i] << endl;
                    cout << "Vintage: " << vintageVec[i] << endl;
                    cout << "Score: " << scoreVec[i] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[i] << endl;
                    cout << "\n";
                    sum+=priceVec[i];   //Calculates average price
                 }
            }
            cout << "\nTotal Number of Wine: " << k << endl;
            cout << "Average Price: $" << setprecision(2) << fixed << sum/k << endl;
            sum = 0;  //Resets the average for multiple loop iterations
        }


        else if(selection ==2)   //Goes into option 2
        {
            cout << "Enter in 2 prices: ";

            while (1) {
    if (cin >> searchPrice && searchPrice >= 0 )   //Takes in the searchScore value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }

    else
        {
      cout << "Invalid Input! Please enter in a valid numeral value." << endl;
      cin.clear();  //Allows user to reenter the searchScore.
      while (cin.get() != '\n') ;
        }
            }
           cout << "Enter in the second number: ";

            while (1) {
    if (cin >> searchPrice2 && searchPrice2 >= 0 )   //Takes in the searchScore value and checks if it is a valid number
        {
      break;  //If it is valid with the if statement above, this breaks the loop of invalid input.
        }

    else
        {
      cout << "Invalid Input! Please enter in a valid numeral value." << endl;
      cin.clear();  //Allows user to reenter the searchScore.
      while (cin.get() != '\n') ;
        }
            }
            int k = 0;
            double sum = 0;
            for(int i = 0; i < name2Vec.size(); i++)
            {
                if(priceVec[i] >= searchPrice && priceVec[i] <= searchPrice2)
                {
                    k++;    //Counter for average price
                    cout << "Name: " << name2Vec[i] << endl;
                    cout << "Wine Type: " << typeVec[i] << endl;
                    cout << "Vintage: " << vintageVec[i] << endl;
                    cout << "Score: " << scoreVec[i] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[i] << endl;
                    cout << "\n";
                    sum+=priceVec[i];    //Calculates average price
                 }
            }
            cout << "\nTotal Number of Wine: " << k << endl;
            cout << "Average Price: $" << setprecision(2) << fixed << sum/k << endl;
            sum = 0;
        }

        else if(selection ==3)    //Goes into option 3
        {
            vector<double> temp;

            for(int j =0; j<8; j++)
            {
                temp.push_back(priceVec[j]);
                //cout << "Temp = " << temp[j] << endl;
            }
//cout << "Temp 2 = " << temp[1] << endl;
            sort(priceVec.begin(), priceVec.end());     //Sorts the price vector

    for (int k = 0; k < temp.size(); k++)
        {
            if(temp[k] == priceVec[0])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[k] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[0] << endl;
                  cout << "\n";
            }
        }

         for (int k = 0; k < temp.size(); k++)
         {


           if(temp[k] == priceVec[1])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[k] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[1] << endl;
                  cout << "\n";
            }
         }

          for (int k = 0; k < temp.size(); k++)
          {


             if(temp[k] == priceVec[2])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[k] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[2] << endl;
                  cout << "\n";
            }
          }
           for (int k = 0; k < temp.size(); k++)
           {


        if(temp[k] == priceVec[3])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[k] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[3] << endl;
                  cout << "\n";
            }
           }
            for (int k = 0; k < temp.size(); k++)
            {


        if(temp[k] == priceVec[4])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[k] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[4] << endl;
                  cout << "\n";
            }
            }

             for (int k = 0; k < temp.size(); k++)
             {


        if(temp[k] == priceVec[5])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[k] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[5] << endl;
                  cout << "\n";
            }
             }
            for (int k = 0; k < temp.size(); k++)
            {


        if(temp[k] == priceVec[6])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[k] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[6] << endl;
                  cout << "\n";
            }
            }
             for (int k = 0; k < temp.size(); k++)
             {


            if(temp[k] == priceVec[7])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[k] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[7] << endl;
                  cout << "\n";
            }
             }
        }

        else if(selection == 4)   //Goes into option 4
        {
            vector<int>temp;
             for(int j =0; j<8; j++)
            {
                temp.push_back(scoreVec[j]);
            }
            sort(scoreVec.begin(), scoreVec.end());    //sorts the score vector


            for (int k = 0; k < temp.size(); k++)
        {
            if(temp[k] == scoreVec[0])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[0] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[k] << endl;
                  cout << "\n";
            }
        }

         for (int k = 0; k < temp.size(); k++)
         {


           if(temp[k] == scoreVec[1])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[1] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[k] << endl;
                  cout << "\n";
            }
         }

          for (int k = 0; k < temp.size(); k++)
          {


             if(temp[k] == scoreVec[2])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[2] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[k] << endl;
                  cout << "\n";
            }
          }
           for (int k = 0; k < temp.size(); k++)
           {


        if(temp[k] == scoreVec[3])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[3] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[k] << endl;
                  cout << "\n";
            }
           }
            for (int k = 0; k < temp.size(); k++)
            {


        if(temp[k] == scoreVec[4])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[4] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[k] << endl;
                  cout << "\n";
            }
            }

             for (int k = 0; k < temp.size(); k++)
             {


        if(temp[k] == scoreVec[5])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[5] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[k] << endl;
                  cout << "\n";
            }
             }
            for (int k = 0; k < temp.size(); k++)
            {


        if(temp[k] == scoreVec[6])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[6] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[k] << endl;
                  cout << "\n";
            }
            }
             for (int k = 0; k < temp.size(); k++)
             {


            if(temp[k] == scoreVec[7])
            {
                  cout << "Name: " << name2Vec[k] << endl;
                  cout << "Wine Type: " << typeVec[k] << endl;
                   cout << "Vintage: " << vintageVec[k] << endl;
                  cout << "Score: " << scoreVec[7] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[k] << endl;
                  cout << "\n";
            }
             }

        }

        else if(selection == 5)    //Goes into option 5
        {
            string searchType;
            int k = 0;
            int counter = 0;
            double sum = 0;
            bool found = false;
            cout << "Enter in Wine Type: ";
           while (1)   //Loop keeps going if user keeps entering invalid input
{

    bool number=false; // Is searchType a number?
    cin.clear();    //clears invalid line
    cin.get();     //Allows user to re enter valid input
    getline(cin, searchType); // get the entire line, including spaces



    // Step through each character in the string until we either hit
    // the end of the string, or we rejected a character
    for (unsigned int n=0; n < searchType.length() && !number; n++)
    {
        // If the current character is an alphabet, that's fine
        if (isalpha(searchType[n]))
            continue;
        // If it's a space, that's fine too
        if (searchType[n]==' ')
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
            for(int j = 0; j<typeVec.size();j++)
            {
                if(searchType.compare(typeVec[j]) == 0)    //Compares the search term with every element of the wine type vector
                {
                    k++;
                    cout << "Name: " << name2Vec[j] << endl;
                    cout << "Wine Type: " << typeVec[j] << endl;
                    cout << "Vintage: " << vintageVec[j] << endl;
                    cout << "Score: " << scoreVec[j] << endl;
                    cout << "Price: $" << setprecision(2) << fixed << priceVec[j] << endl;
                    cout << "\n";
                    found = true;
                    counter++;
                    sum+=priceVec[j];
                }
                else if(counter<1)
                    found = false;
            }
            if(!found)   //Displays message if search term cannot be found
                cout << "Not Found!" << endl;

                else{      //Displays the average wine price only if it was found by the search term
                cout << "\nTotal Number of Wine: " << k << endl;
                cout << "Average Price: $" << setprecision(2) << fixed << sum/k << endl;
                sum = 0;
                }
        }
        else if(selection==6)    //Goes into option 6
            cout << "Thank You for using my program! Have a great day!" << endl;
        else   //Displays only if invalid input is selected
            cout << "Invalid input! Please enter a number 1-6" << endl;

  }while(selection!=6);   //Quits the program if user enters in 6


}




void printMeFirst(string name, string courseInfo)
{
    cout <<" Program written by: "<< name << endl; // put your name here
    cout <<" Course info: "<< courseInfo << endl;
    time_t now = time(0);  // current date/time based on current system
    char* dt = ctime(&now); // convert now to string for
    cout << " Date: " << dt << endl;
}
