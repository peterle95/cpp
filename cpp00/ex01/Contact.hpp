#ifndef CONTACT_HPP // This is a preprocessor directive that checks if this file has not been included before.
                    //      If it has not been included, then the contents of the file are included.
#define CONTACT_HPP // This defines a symbol that can be used by the preprocessor to check if the file has been included.

#include <string>  // This is an include directive that includes the contents of the file "string".
                  //      This is needed so that the compiler knows what the std::string class is.

class Contact 
{  // This is a class definition. It is a new data type that can be used to create objects.
private:         // This is an access specifier that specifies that the members that follow are private.
                 //      This means that they can only be accessed by other members of the same class.
    std::string firstName;  // This is a member variable. It is a variable that is part of the class, and it is of type std::string.
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:          // This is an access specifier that specifies that the members that follow are public.
                 //      This means that they can be accessed by any other part of the program.
    void setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
                     // This is a member function. It is a function that is part of the class, and it can be called on an object of the class.
                     //      The function takes five parameters, which are all of type std::string.
                     //      The function sets the member variables of the class to the values of the parameters.
    void displayShort(int index); // This is a member function. It is a function that is part of the class, and it can be called on an object of the class.
                                 //      The function takes one parameter, which is of type int.
                                 //      The function displays the contact information in a short format.
    void displayFull(); // This is a member function. It is a function that is part of the class, and it can be called on an object of the class.
                        //      The function displays the contact information in a long format.
}; // This semicolon is necessary because the class definition is a declaration, and all declarations must end with a semicolon.

#endif
