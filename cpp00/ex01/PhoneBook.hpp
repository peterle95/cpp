#ifndef PHONEBOOK_HPP 
// This is a preprocessor directive that checks if this file has not been included before.
//      If it has not been included, then the contents of the file are included.
#define PHONEBOOK_HPP 

// This is an include directive that includes the contents of the file "Contact.hpp".
//      This is needed so that the compiler knows what the Contact class is.
#include "Contact.hpp"

// This is a class definition. It is a new data type that can be used to create objects.
class PhoneBook 
{ 
private: // This is an access specifier that specifies that the members that follow are private.
        //      This means that they can only be accessed by other members of the same class.
    // This is an array of 8 Contact objects. This will store the contacts in the phonebook.
    Contact contacts[8];
    // This is an integer that keeps track of the number of contacts in the phonebook.
    int count;
    // This is an integer that keeps track of the index of the oldest contact in the phonebook.
    int oldest;

public: // This is an access specifier that specifies that the members that follow are public.
        //      This means that they can be accessed by any other part of the program.
    // This is a constructor that is called when an object of this class is created.
    PhoneBook();
    // This is a member function that adds a new contact to the phonebook.
    void addContact();
    // This is a member function that searches for a contact in the phonebook.
    void searchContact();
}; // This semicolon is necessary because the class definition is a declaration, and all declarations must end with a semicolon.

#endif // This is the end of the include guard. If the symbol was not defined, then the contents of the file are not included.

