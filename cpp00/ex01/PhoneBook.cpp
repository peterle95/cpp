// This file contains the implementation of the PhoneBook class.
// The PhoneBook class is a simple container for storing Contact objects.
// The class provides methods for adding a contact, searching for a contact by index,
// and displaying all contacts.
//
// The class stores the contacts in an array of Contact objects.
// The array is of size 8, meaning that the class can store up to 8 contacts.
// The class keeps track of how many contacts are currently stored in the array
// using the count variable.
// The class also keeps track of which contact is the oldest contact in the array
// using the oldest variable.
// The oldest contact is the contact that was added to the array last.

    // The "oldest" variable keeps track of the index of the oldest contact in the array.
    // When a new contact is added, it is placed at the index indicated by "oldest".
    // If the number of contacts exceeds 8, the oldest contact will be replaced by the new one.
    // The "oldest" index is updated in a circular manner using modulo operation:
    // (oldest + 1) % 8 ensures that after reaching the last index (7), it wraps around to 0.
    // This way, the array always contains the most recent 8 contacts, and the oldest one is overwritten.
//
// The addContact method prompts the user to enter the first name, last name,
// nickname, phone number, and darkest secret of a contact.
// The method then creates a new Contact object with the entered information
// and adds it to the array.
// The method also updates the count and oldest variables.
//
// The searchContact method prompts the user to enter the index of a contact
// that they want to display.
// The method then displays the contact at the entered index.
// If the index is invalid, the method displays an error message.

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// Constructor for the PhoneBook class.
// A constructor is a special member function that is automatically called when an 
// object of the class is created.
// It is used to initialize the object's member variables to a valid state.
// The syntax for a constructor is similar to that of a regular member function, 
// but it does not have a return type,
// and its name must match the class name. In this case, PhoneBook::PhoneBook() is 
// the constructor for the PhoneBook class.
// The initializer list (": count(0), oldest(0)") is used to set the initial values 
// of the count and oldest variables to 0.
// This is important because it ensures that the PhoneBook starts with no contacts 
// and the oldest index is set correctly.
PhoneBook::PhoneBook() : count(0), oldest(0) {}

// Adds a contact to the array.
// Prompts the user to enter the first name, last name, nickname, phone number,
// and darkest secret of the contact.
// Creates a new Contact object with the entered information and adds it to the array.
// Updates the count and oldest variables.
void PhoneBook::addContact() 
{
    std::string first, last, nick, phone, secret;
    
    // Prompts the user to enter the first name of the contact.
    std::cout << "Enter first name: ";
    // Reads the entered first name into the first variable.
    std::cin >> first;
    // Prompts the user to enter the last name of the contact.
    std::cout << "Enter last name: ";
    // Reads the entered last name into the last variable.
    std::cin >> last;
    // Prompts the user to enter the nickname of the contact.
    std::cout << "Enter nickname: ";
    // Reads the entered nickname into the nick variable.
    std::cin >> nick;
    // Prompts the user to enter the phone number of the contact.
    std::cout << "Enter phone number: ";
    // Reads the entered phone number into the phone variable.
    std::cin >> phone;
    // Prompts the user to enter the darkest secret of the contact.
    std::cout << "Enter darkest secret: ";
    // Reads the entered darkest secret into the secret variable.
    std::cin >> secret;

    // Creates a new Contact object with the entered information.
    contacts[oldest].setContact(first, last, nick, phone, secret);
    // Updates the oldest variable to point to the newly created contact.
    oldest = (oldest + 1) % 8;
    // If the count is less than 8, increments the count.
    if (count < 8) 
        count++;
}

// Searches for a contact by index and displays it.
// Prompts the user to enter the index of the contact that they want to display.
// Displays the contact at the entered index.
// If the index is invalid, displays an error message.
void PhoneBook::searchContact() 
{
    if (count == 0) 
    {
        // If the count is 0, displays a message indicating that the phonebook is empty.
        std::cout << "Phonebook is empty." << std::endl;
        // Returns from the method.
        return;
    }
    // Loops through the contacts array and displays each contact.
    for (int i = 0; i < count; i++) 
    {
        contacts[i].displayShort(i);
    }
    int index;
    // Prompts the user to enter the index of the contact that they want to display.
    std::cout << "Enter index to display: ";
    // Reads the entered index into the index variable.
    std::cin >> index;// If the entered index is invalid, displays an error message.
    // Checks if the previous input operation failed (e.g., if the user entered a non-integer value).
    if (std::cin.fail() || index < 0 || index >= count) 
    {
        std::cout << "Invalid index." << std::endl; // Clears the input buffer.
        std::cin.clear(); // Ignores any remaining characters in the input buffer.
        std::cin.ignore(10000, '\n');// Returns from the method.
        return;
    }
    // Displays the contact at the entered index.
    contacts[index].displayFull();
}
