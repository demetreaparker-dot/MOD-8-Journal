/*

 * Clock.cpp

 * Author: Demetre Parker

 * Description: Displays 12-hour and 24-hour clocks simultaneously

 *              and allows user interaction to modify time.

 */

#include <climits>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/* Constants */
const int HOURS_IN_DAY = 24;
const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_HALF_DAY = 12;
const int EXIT_PROGRAM = 4;

/* Function Prototypes */
void displayClocks(int hours, int minutes, int seconds);
void showMenu();
void increaseMinute(int& minutes, int& hours);
void increaseSecond(int& seconds, int& minutes, int& hours);
void increaseHour(int& hours);
string formatTime24(int hours, int minutes, int seconds);
string formatTime12(int hours, int minutes, int seconds);
int getUserChoice();


/* Main Function */
/* Description:This function captures the initial time and lets the user enter Hours,Minutes and Seconds
*/

int main() {

    int hours, minutes, seconds;
    int userChoice = 0;

    // Get initial time input

    cout << "Enter initial time (HH MM SS): ";
    cin >> hours >> minutes >> seconds;

    // Main loop
    while (userChoice != EXIT_PROGRAM) {
        displayClocks(hours, minutes, seconds);
        showMenu();
        userChoice = getUserChoice();

        switch (userChoice) {
        case 1:
            increaseHour(hours);
            break;
        case 2:
            increaseMinute(minutes, hours);
            break;
        case 3:
            increaseSecond(seconds, minutes, hours);
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
    return 0;
}


/*
 * Description: Display the clocks in 12-hour and 24-hour formats
 * @param hours - hour value
 * @param minutes - minute value
 * @param seconds - second value
 * @returns void.
 */
void displayClocks(int hours, int minutes, int seconds) {

    cout << "\n**************************   **************************\n";
    cout << "*      12-Hour Clock     *   *      24-Hour Clock     *\n";
    cout << "*       " << formatTime12(hours, minutes, seconds) << "      *   *        ";
    cout << formatTime24(hours, minutes, seconds) << "        *\n";
    cout << "**************************   **************************\n";

}


/* Displays menu options */
/* Description: This function displays users menu options 1 - 4
*/

void showMenu() {

    cout << "\nMenu Options:\n";
    cout << "1 - Add One Hour\n";
    cout << "2 - Add One Minute\n";
    cout << "3 - Add One Second\n";
    cout << "4 - Exit Program\n";
}


/* Gets user menu choice */
/* Description : This function allows user to select options within the clock program
*/

int getUserChoice() {
    int choice;

    cout << "Select an option: ";
    cin >> choice;
    return choice;

}


/* Adds one hour */
/* Description: This function adds hours
 * @param hours -  This is a reference to add hours
 */
void increaseHour(int& hours) {

    hours = (hours + 1) % HOURS_IN_DAY;

}



/* Adds one minute */
/* Description: This function adds minutes and handles hour rollover.
 *@param minutes - This is a reference to add minutes
 *@param hours  - This is a reference to add hours
 */
void increaseMinute(int& minutes, int& hours) {

    minutes++;
    if (minutes == MINUTES_IN_HOUR) {
        minutes = 0;
        increaseHour(hours);
    }

}


/* Adds one second */
/* Description: This function adds seconds and handles hour and minutes rollover
  @param seconds - This is a reference to add seconds
 *@param minutes - This is a reference to add minutes
  @param hours - This is a reference to add hours
 */

void increaseSecond(int& seconds, int& minutes, int& hours) {

    seconds++;
    if (seconds == MINUTES_IN_HOUR) {
        seconds = 0;
        increaseMinute(minutes, hours);
    }

}

string formatTime12(int hours, int minutes, int seconds)
{
    int hour12 = hours % HOURS_IN_HALF_DAY;
    if (hour12 == 0) {
        hour12 = HOURS_IN_HALF_DAY;
    }
    string period = (hours < HOURS_IN_HALF_DAY) ? " AM" : " PM";

    string min_sec = "";
    if (minutes < 10)
        min_sec += ":0" + to_string(minutes) + ":";
    else
        min_sec += ":" + to_string(minutes) + ":";

    if (seconds < 10)
        min_sec += "0" + to_string(seconds);
    else
        min_sec += to_string(seconds);

    string clocks = to_string(hour12) + min_sec + period;
    if (hour12 < 10)
        clocks = "0" + clocks;

    return clocks;
}

string formatTime24(int hours, int minutes, int seconds)
{
    string min_sec = "";
    if (minutes < 10)
        min_sec += ":0" + to_string(minutes) + ":";
    else
        min_sec += ":" + to_string(minutes) + ":";

    if (seconds < 10)
        min_sec += "0" + to_string(seconds);
    else
        min_sec += to_string(seconds);

    string clocks = to_string(hours) + min_sec;
    if (hours < 10)
        clocks = "0" + clocks;

    return clocks;

}