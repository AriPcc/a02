/******************************************************************************
# Author:             Ari P.
# Assignment:         Assignment 2
# Date:               10/4/2025
# Description:        This program will generate a D2L-compatible filename
                      after reading necessary assignment details from the user.
# Input:              option (char), fName (cstring), lName (cstring),
                      lateChar (char), studentID (cstring), fileName (cstring,
                      hours (int), minutes (int), separator (char)
# Output:             encodeFileName (cstring)
# Sources:            Assignment 2 specifications, zyBooks reference
#*****************************************************************************/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Declare and initialize global constant variables
const int MAX_CHAR = 51;

// Declare functions, all of which are defined after main()
void welcome();
void displayMenu();
void readOption(char &option);
void encode(char* encodeFileName);
void lowerCase(char* text);
void readInput(char* fName, char* lName, bool &lateFlag);
void readInput(char* parsedID, char* fileName);
void readTime(char* strTime);
void goodbye();


int main() {
  // Declare and intitialize variables for input and output. Most are found
  // within the encode() function.
  char option = ' ';
  char encodeFileName[MAX_CHAR] = "";

  // Print welcome message
  welcome();
  cout << endl;

  // Allow user to continue encoding filenames until they quit
  do {
    // Display menu
    displayMenu();
    cout << endl;
    // Get menu selection
    readOption(option);
    cout << endl;

    // Generate and print encoded filename
    if (option == 'E' || option == 'e') {
      encode(encodeFileName);
      cout << endl;
      cout << "Your encoded filename is: " << encodeFileName << endl;
      cout << endl;
    }
  } while(option != 'Q' && option != 'q');

  // Print goodbye message and end the program
  goodbye();
  return 0;
}

// Name:    welcome()
// Desc:    This function prints a welcome message
// input:   None
// output:  None
// return:  void
void welcome() {
  cout << "Welcome to the filename encoding program!" << endl;
}

// Name:    displayMenu()
// Desc:    This function displays the menu
// input:   None
// output:  None
// return:  void
void displayMenu() {
  cout << "Please select an option:" << endl;
  cout << "   e) Encode filename" << endl;
  cout << "   q) Quit" << endl;
}

// Name:    readOption(char &option)
// Desc:    This function gets the user's menu selection
// input:   option
// output:  None
// return:  void
void readOption(char &option) {
  cin >> option;
  cin.ignore(100, '\n');
  // Ensure option is either E/e or Q/q
  while ( (cin.fail()) || (option != 'E' && option != 'e' && option != 'Q' && option != 'q') ) {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Invalid option! Please try again: ";
    cin >> option;
    cin.ignore(100, '\n');
  }
}

// Name:    encode(char* encodeFileName)
// Desc:    This function generates an encoded filename by calling several
//          input functions.
// input:   None
// output:  None
// return:  void
void encode(char* encodeFileName) {
  // Declare and initialize local variables for input
  char fName[MAX_CHAR] = "";
  char lName[MAX_CHAR] = "";
  bool lateFlag;
  char parsedID[MAX_CHAR] = "";
  char fileName[MAX_CHAR] = "";
  char strTime[MAX_CHAR] = "";

  cout << "Please answer the following six questions:" << endl;
  // Get all six input values
  readInput(fName, lName, lateFlag);
  readInput(parsedID, fileName);
  readTime(strTime);

  // Generate encoded filename
  // Filename format: lName_fName_LATE_parsedID_strTime_fileName
  strcpy(encodeFileName, lName);
  cout << encodeFileName << endl;
  strcat(encodeFileName, "_");
  cout << encodeFileName << endl;

  strcat(encodeFileName, fName);
  cout << encodeFileName << endl;
  strcat(encodeFileName, "_");
  cout << encodeFileName << endl;

  // Add LATE flag if assignment was late
  if (lateFlag == true) {
    strcat(encodeFileName, "LATE_");
    cout << encodeFileName << endl;
  }

  strcat(encodeFileName, parsedID);
  cout << encodeFileName << endl;
  strcat(encodeFileName, "_");
  cout << encodeFileName << endl;

  strcat(encodeFileName, strTime);
  cout << encodeFileName << endl;
  strcat(encodeFileName, "_");
  cout << encodeFileName << endl;
  
  strcat(encodeFileName, fileName);
  cout << encodeFileName << endl;
}

// Name:    lowerCase(char* text)
// Desc:    This function converts text to lowercase
// input:   None
// output:  None
// return:  void
void lowerCase(char* text) {
  for (int i = 0; i < strlen(text); i++) {
    text[i] = static_cast<char>( tolower(text[i]) );
  }
}

// Name:    readInput(char* fName, char* lName, bool &lateFlag)
// Desc:    This overloaded function gets the user's full name and the 
//          submission status of their assignment.
// input:   fName (cstring), lName (cstring), lateChar (char)
// output:  None
// return:  void
void readInput(char* fName, char* lName, bool &lateFlag) {
  char lateChar = ' ';

  // Get first and last name as lowercase cstrings
  cout << "Enter your first name: ";
  cin.get(fName, MAX_CHAR);
  cin.clear();
  cin.ignore(100,'\n');
  lowerCase(fName);
  cout << "Enter your last name: ";
  cin.get(lName, MAX_CHAR);
  cin.clear();
  lowerCase(lName);

  // Ask user if assignment was late
  cout << "Was your assignment late? (y/n): ";
  cin.ignore(100, '\n');
  cin.get(lateChar);
  cin.clear();
  cin.ignore(100, '\n');
  // Ensure lateChar is either Y/y or N/n
  while ( (cin.fail()) || (lateChar != 'Y' && lateChar != 'y' && lateChar != \
'N' && lateChar != 'n')) {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Invalid answer! Please try again." << endl;
    cout << "Was your assignment late? (y/n): ";
    cin.get(lateChar);
  }
  cin.ignore(100, '\n');

  // Update lateFlag if assignment was late
  if (lateChar == 'Y' || lateChar == 'y') {
    lateFlag = true;
  }
  else if (lateChar == 'N' || lateChar == 'n') {
    lateFlag = false;
  }
}

// Name:    readInput(char* parsedID, char* fileName)
// Desc:    This overloaded function gets the user's student ID and original
//          assignment filename.
// input:   studentID (cstring), fileName (cstring)
// output:  None
// return:  void
void readInput(char* parsedID, char* fileName) {
  char studentID[MAX_CHAR] = "";

  // Get student ID
  cout << "Enter your student ID (xxx-xx-xxxx): ";
  cin.get(studentID, MAX_CHAR);
  cin.ignore(100,'\n');
  // Keep only last 4 digits
  strncpy(parsedID, studentID + 7, 4);

  // Get original filename
  cout << "Enter original filename (including extension): ";
  cin.getline(fileName, MAX_CHAR);
}

// Name:    readTime(char* strTime)
// Desc:    This function gets the assignment's submission time
// input:   hours (int), minutes (int), separator (char)
// output:  None
// return:  void
void readTime(char* strTime) {
  int hours = 0;
  int minutes = 0;
  char separator = ' ';

  // Get assignment submission time (in military format)
  cout << "Enter submission time (military time, e.g. 18:30 for 6:30 PM): ";
  cin >> hours >> separator >> minutes;
  // Ensure that hours are between 0 and 24 and that minutes are between 0 and
  // 59 (midnight can be either 00:00 or 24:00).
  while ( (cin.fail()) || (separator != ':' || hours < 0 || hours > 24 || \
minutes < 0 || minutes > 59) ) {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Invalid answer! Please try again." << endl;
    cout << "Enter submission time (military time, e.g. 18:30 for 6:30 PM): ";
    cin >> hours >> separator >> minutes;
  }
  // If either hours or minutes are less than 10, prepend a 0
  if (hours < 10) {
    strcpy(strTime, "0");
    strcat(strTime, to_string(hours).c_str());
  }
  else {
    strcpy(strTime, to_string(hours).c_str());
  }
  if (minutes < 10) {
    strcat(strTime, "0");
  }
  strcat(strTime, to_string(minutes).c_str());
}

// Name:    goodbye()
// Desc:    This function prints a goodbye message
// input:   None
// output:  None
// return:  void
void goodbye() {
  cout << "Thank you for using the filename encoding program." << endl;
}