#ifndef GROCERYITEM_H

#define GROCERYITEM_H



#include <string>



using namespace std;
/*

 * GroceryItem Class

 * ------------------

 * Encapsulates grocery item data including name and quantity.

 * This class is reusable and contains no input/output operations.

 */
class GroceryItem {

private:

    string name;

    int quantity;



public:

    // Default constructor

    GroceryItem();



    // Parameterized constructor

    GroceryItem(string itemName, int itemQuantity);



    // Getters

    string getName() const;

    int getQuantity() const;



    // Setters

    void setName(string itemName);

    void setQuantity(int itemQuantity);



    // Adds one to quantity

    void addItem();

};



#endif