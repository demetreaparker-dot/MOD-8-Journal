MOD 8 JOURNAL
CS 210 – Project Three
Corner Grocer Item Tracking Program
Project Overview

In this project, I developed a C++ item-tracking system for the Corner Grocer. The program reads purchase data from CS210_Project_Three_Input_File.txt, analyzes how frequently each grocery item appears, and presents the results through an interactive menu.

The program allows users to:

Search for the frequency of a specific item

Display all item frequencies numerically

Display a histogram representation using asterisks

Exit the program


In addition, the program automatically generates a backup file called frequency.dat, which stores each item along with its purchase frequency. This demonstrates file output functionality and data persistence.

The purpose of this project was to convert raw transaction data into meaningful frequency reports that could help optimize store layout decisions.





Design and Implementation

This project was built using object-oriented principles. I created a GroceryItem class with:

Private data members (name and quantity)

A default constructor

A parameterized constructor

Getters and setters

An addItem() method to increment quantity

By separating the class definition (.h) and implementation (.cpp), I followed proper C++ design standards. I also ensured the class contained no input/output operations, maintaining separation of concerns and improving reusability.

In main.cpp, I used a map<string, GroceryItem> to store item frequencies. This allowed efficient lookup, automatic key organization, and clean frequency management.

The program was structured into modular functions:

LoadData() – Reads the input file and populates the map

CreateBackupFile() – Writes item frequencies to frequency.dat

PrintAllItems() – Displays numeric frequencies

PrintHistogram() – Displays a visual frequency chart

DisplayMenu() – Presents user options

This modular approach improved readability and maintainability.






What I Did Well

One of my strongest areas in this project was implementing proper encapsulation. Instead of storing raw integers in the map, I stored GroceryItem objects, which made the program more structured and expandable.

I also successfully implemented input validation for menu selection using cin.clear() and cin.ignore() with numeric_limits. This prevents runtime crashes when invalid input is entered.

Additionally, I wrote clear documentation comments above each function and followed consistent naming conventions to ensure professional, readable code.






Areas for Improvement

Although the program functions correctly, one improvement would be reducing redundancy in data loading. Currently, the program reloads the file before each menu operation. While this guarantees updated data, it could be optimized by loading once and updating only when necessary.

Another enhancement would be adding case-insensitive search functionality to improve user experience. I could also implement more advanced exception handling for file operations to make the program more robust.







Most Challenging Aspects

The most challenging part of this project was correctly implementing frequency tracking using a map. I had to ensure that each item was either inserted into the map or incremented using the addItem() method if it already existed.

Handling file input and ensuring accurate parsing also required careful debugging. Additionally, implementing proper input validation to prevent program crashes required understanding how to safely manage the input stream.

I overcame these challenges through testing, debugging, and reviewing course materials related to maps and file I/O.







Transferable Skills

This project strengthened several transferable skills:

Object-oriented programming in C++

Class design and encapsulation

File input and file output operations

Using std::map for structured data management

Input validation and runtime error prevention

Writing modular, maintainable code

These skills are directly applicable to larger software systems, backend development, and data-processing applications.








Maintainability and Adaptability

I made this program maintainable by:

Separating class definition and implementation

Using modular functions

Writing descriptive comments

Following consistent naming conventions

Because the program uses a class-based design and a dynamic container (map), it can be expanded easily. For example, additional attributes could be added to GroceryItem, or the program could integrate with a database instead of a text file without redesigning the core structure.
