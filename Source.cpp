/*
This program will display an Object-Oriented Programming (OOP) functions to create
Two (2) clocks that shows simultaeously and allow for user input. 
*/

/*
Author Name:	John Adebolujo
Date:			May 24, 2025
Class:			CS-210-Programming Languages.
Project:		Module 3-3 Project-One Submission.
*/

// The following codes will provide solutions to the questions in project one.

#include <iostream>
#include <iomanip>

using namespace std;

// Starting of function creation with the clock class definition
class Clock {
private:
    int hours;          // This variable stores Hours
    int minutes;        // This variable stores Minutes
    int seconds;        // This variable stores Seconds
    
public:
    // The following is a Constructor to initialize the clock with default or specified time
    Clock(int h = 0, int m = 0, int s = 0) : 
        hours(h), 
        minutes(m), 
        seconds(s) {}

    // We start with the Method to add one hour to the time through the user's input
    void addHour() {
        hours = (hours + 1) % 24; // Wrap around after 23 to maintain 24-hour format
    }

    // Then followed with the Method to add one minute to the time through the user's input
    void addMinute() {
        minutes++;
        if (minutes >= 60) {        // This statement check for overflow and adjust hours accordingly
            minutes = 0;
            addHour();
        }
    }

    
    // Next is the Method to add one second to the time through the user's input
    void addSecond() {
        seconds++;
        if (seconds >= 60) {        // This statement check for overflow and adjust Minutes accordingly
            seconds = 0;
            addMinute();
        }
    }

    // The following is the Output section...

    // Here, we create different functions to print Time in 12 hours and 24 hour simultaneously.

    // Starting with the Function to display time in 12-hour format according to Intern'l standard ISO-8601
    void display12HourFormat() const {
        int displayHours = hours % 12;                               // This statement convert Time to 12-hour format
        if (displayHours == 0) displayHours = 12;                    // This statement cater for Time changes at Noon and Midnight hours
        string period = (hours < 12) ? "AM" : "PM";                  // This statement examine Time periods AM/PM 
        cout << setw(2) << setfill('0') << displayHours << ":"       // This statement display Time hours (12 hours format)
             << setw(2) << setfill('0') << minutes << ":"            // This statement display Time Minutes 
             << setw(2) << setfill('0') << seconds << " " << period; // This statement display Time seconds 
    }

    // Then, we create the Function to display time in 24-hour format
    void display24HourFormat() const {
        cout << setw(2) << setfill('0') << hours << ":"             // This statement display Time hours (24 hours format)
            << setw(2) << setfill('0') << minutes << ":"            // This statement display Time Minutes 
            << setw(2) << setfill('0') << seconds;                  // This statement display Time seconds 
    }
};

    // Function to print '*' 26 times 
    string nCharString(size_t n, char c) {

        string result;                                              // This statement define string variable "result" 
        for (size_t i = 0; i < n; ++i) {                            // This statement define the Loop to print "*" for the number of times specified
            result += c;                                            // This statement acts as a counter for the Loop
        }

        return result;                                              // This statement return the value of the function
    }

    
// The following section have Functions that display choices and receive user's input

// Function to display the choices menu and process user input
void displayMenu(Clock& clock12, Clock& clock24) {
    int choice;
    string output;
    do {                                                    // The statement display current time for 12 hours and 24 hours respedtively
        cout << "\n\nCurrent Time:\n";
        cout << output << "          " << output << endl;   // This statement print "*"
        cout << "*      12-Hour Clock      *" << "          ";
        cout << "*      24-Hour Clock      *" << endl;
        cout << "*      ";
        clock12.display12HourFormat();                      // This statement display Time hours (12 hours format)
        cout << "        *" << "          ";
        cout << "*        ";
        clock24.display24HourFormat();                      // This statement display Time hours (24 hours format)
        cout << "         *" << endl;
        cout << output << "          " << output << endl;   // This statement print "*"
        cout << endl;
        cout << output << endl;                             // This statement print "*"
        cout << "\n\n* Menu:                  *\n";
        cout << "* 1 - Add One Hour        *\n";            // This statement allows the user to add One Hour to the time 
        cout << "* 2 - Add One Minute      *\n";            // This statement allows the user to add One Minute to the time
        cout << "* 3 - Add One Second      *\n";            // This statement allows the user to add One Second to the time
        cout << "* 4 - Exit Program        *\n";            // This statement allows the user to terminate the program using this option
        cout << output << endl;                             // This statement print "*"
        cout << endl;
        cout << "Enter your choice: ";                      // This statement encourage the user to make a choice
        cin >> choice;                                      // This statement is the input menu that receive the user option/choice

        // This section process user choice based on the options provided
        switch (choice) {
        case 1:
            clock12.addHour();                      // Based on the option "1-selection," this statement add One Hour to Time hour (12 hours format)
            clock24.addHour();                      // Based on the option "1-selection," this statement add One Hour to Time hour (24 hours format)
            break;
        case 2:
            clock12.addMinute();                    // Based on the option "2-selection," this statement add One Minute to Time minute (12 hours format)
            clock24.addMinute();                    // Based on the option "2-selection," this statement add One Minute to Time minute (24 hours format)
            break;
        case 3:
            clock12.addSecond();                    // Based on the option "3-selection," this statement add One Second to Time second (12 hours format)
            clock24.addSecond();                    // Based on the option "3-selection," this statement add One Second to Time second (24 hours format)
            break;
        case 4:
            cout << "Exiting...\n";                 // Based on the option "4-selection," this statement dipaly a message to exit the program
            break;
        default:
            cout << "Invalid choice. Please try again.\n";  // This statement cater for any invalid input option from the user differently from the displayed choices
        }
    } while (choice != 4);                                  // This statement cater for the Loop until the user choose the option to exit the program
}

int main() {                                        // The main function is where source code begins execution
    Clock clock12(10, 30, 45);                      // This statement initialize the 12 hour clock with random time
    Clock clock24(10, 30, 45);                      // This statement initialize the 24 hour clock with random time

    displayMenu(clock12, clock24);                  // This statement start the user interaction menu

    char toPrint = '*';
    int nTimes = 26;
    string output = nCharString(nTimes, toPrint);   // This statement calls the nCharString Function and assign it to string output variable
    
    
    return 0;                                       // This statement end the program
}
