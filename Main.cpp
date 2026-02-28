#include <iostream>
#include <fstream>
#include <map>
#include <limits>
#include "GroceryItem.h"

using namespace std;

const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
const string BACKUP_FILE = "frequency.dat";
/**
 * @brief Reads grocery item data from the input file and loads it into the provided map.
 *
 * Clears the existing map contents before loading. Each item read from the file
 * increments its quantity if it already exists in the map; otherwise, it is inserted
 * with an initial quantity of 1.
 *
 * @param groceryMap Reference to a map storing item names as keys and GroceryItem objects as values.
 */
void LoadData(map<string, GroceryItem>& groceryMap) {
    groceryMap.clear();

    ifstream inputFile(INPUT_FILE);
    string itemName;

    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    while (inputFile >> itemName) {
        if (groceryMap.count(itemName) > 0) {
            groceryMap.at(itemName).addItem();
        }
        else {
            groceryMap.emplace(itemName, GroceryItem(itemName, 1));
        }
    }

    inputFile.close();
}
/**
 * @brief Creates a backup file containing item frequency data.
 *
 * Writes each grocery item's name and quantity to the backup file.
 *
 * @param groceryMap Constant reference to a map containing grocery item data.
 *Creates the backup file frequency.dat
 */
void CreateBackupFile(const map<string, GroceryItem>& groceryMap) {
    ofstream outputFile(BACKUP_FILE);

    for (map < string, GroceryItem>::const_iterator it = groceryMap.begin(); it != groceryMap.end(); ++it) {
        outputFile << it->second.getName() << " "
            << it->second.getQuantity() << endl;
    }

    outputFile.close();
}
/*
 * Displays numeric frequency of all items.
 * @param groceryMap Constant reference to a map containing grocery item data.
 */
void PrintAllItems(const map<string, GroceryItem>& groceryMap) {
    for (map < string, GroceryItem>::const_iterator it = groceryMap.begin(); it != groceryMap.end(); ++it) {
        cout << it->second.getName() << " "
            << it->second.getQuantity() << endl;
    }
}
/**
 * @brief Displays the numeric frequency of all grocery items.
 *
 * Outputs each item name followed by its quantity.
 *
 * @param groceryMap Constant reference to a map containing grocery item data.
 */
void PrintHistogram(const map<string, GroceryItem>& groceryMap) {
    for (map < string, GroceryItem>::const_iterator it = groceryMap.begin(); it != groceryMap.end(); ++it) {
        cout << it->second.getName() << " ";

        for (int i = 0; i < it->second.getQuantity(); ++i) {
            cout << "*";
        }
        cout << endl;
    }
}
/**
 * @brief Displays a histogram representation of grocery item frequencies.
 *Each item is displayed with a number of asterisks corresponding
 * to its quantity.
 *@param groceryMap Constant reference to a map containing grocery item data.
 *Displays menu options.
 */
void DisplayMenu() {
    cout << "\n===== Corner Grocer Menu =====" << endl;
    cout << "1. Search for item frequency" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Select option: ";
}

int main() {
    map<string, GroceryItem> groceryMap;
    int userChoice = 0;
    string searchItem;
    // Initial load and backup file creation
    LoadData(groceryMap);
    CreateBackupFile(groceryMap);

    while (userChoice != 4) {

        DisplayMenu();

        while (!(cin >> userChoice)) {
            cout << "Invalid input. Please enter a number 1-4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (userChoice == 1) {
            LoadData(groceryMap);

            cout << "Enter item to search: ";
            cin >> searchItem;

            if (groceryMap.count(searchItem) > 0) {
                cout << searchItem << " appears "
                    << groceryMap.at(searchItem).getQuantity()
                    << " times." << endl;
            }
            else {
                cout << searchItem << " appears 0 times." << endl;
            }
        }

        else if (userChoice == 2) {
            LoadData(groceryMap);
            PrintAllItems(groceryMap);
        }

        else if (userChoice == 3) {
            LoadData(groceryMap);
            PrintHistogram(groceryMap);
        }

        else if (userChoice == 4) {
            cout << "Exiting program..." << endl;
        }

        else {
            cout << "Please select a valid option (1-4)." << endl;
        }
    }

    return 0;
}
