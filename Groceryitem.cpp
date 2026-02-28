#include "GroceryItem.h"
/*
 * @brief Default constructor.
 *
 * Initializes the grocery item with an empty name
 * and a quantity of zero.
 * Default constructor
 */
GroceryItem::GroceryItem() {
    name = "";
    quantity = 0;
}
/**
 * @brief Parameterized constructor.
 * Initializes the grocery item with a specified name
 * and quantity.
 * Parameterized constructor
 * @param itemName The name of the grocery item.
 * @param itemQuantity The initial quantity of the grocery item.
 */
GroceryItem::GroceryItem(string itemName, int itemQuantity) {
    name = itemName;
    quantity = itemQuantity;
}
/**
 * @brief Retrieves the name of the grocery item.
 * Getter for name
 * @return string The name of the grocery item.
 */
string GroceryItem::getName() const {
    return name;
}
/**
 * @brief Retrieves the quantity of the grocery item.
 * Getter for quantity
 * @return int The current quantity of the grocery item.
 */
int GroceryItem::getQuantity() const {
    return quantity;
}
/**
 * @brief Sets the name of the grocery item.
 * Setter for name
 * @param itemName The new name to assign to the grocery item.
 */
void GroceryItem::setName(string itemName) {
    name = itemName;
}
/**
 * @brief Sets the quantity of the grocery item.
 * Setter for quantity
 * @param itemQuantity The new quantity value to assign.
 */
void GroceryItem::setQuantity(int itemQuantity) {
    quantity = itemQuantity;
}
/**
 * @brief Increments the quantity of the grocery item by one.
 * Increment quantity
 * Used when an additional instance of the item
 * is encountered in the input file.
 */
void GroceryItem::addItem() {
    quantity++;
}
