/**
 * @file Contact.cpp
 * @author pmolzer (pmolzer@student.42berlin.de)
 * @brief This is the implementation of the Contact class.
 * The class stores the first name, last name, nickname, phone number
 * and darkest secret of a contact.
 * The class provides methods for setting the contact information
 * and for displaying the contact information in a short and a long format.
 * The short format displays the index of the contact, the first name,
 * the last name and the nickname in a table format.
 * The long format displays all the contact information in a detailed format.
 */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
// maybe do this excercise without this library

/**
 * @brief Sets the contact information.
 * @param first The first name of the contact.
 * @param last The last name of the contact.
 * @param nick The nickname of the contact.
 * @param phone The phone number of the contact.
 * @param secret The darkest secret of the contact.
 */
void Contact::setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret) {
    firstName = first; // sets the first name of the contact
    lastName = last; // sets the last name of the contact
    nickname = nick; // sets the nickname of the contact
    phoneNumber = phone; // sets the phone number of the contact
    darkestSecret = secret; // sets the darkest secret of the contact
}

/**
 * @brief Displays the contact information in a short format.
 * @param index The index of the contact.
 */
void Contact::displayShort(int index) {
    std::cout << std::setw(10) << index << "|"; // displays the index of the contact, right aligned in a field of width 10
    std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"; // displays the first name of the contact, right aligned in a field of width 10
    // if the length of the first name is greater than 10 characters, it truncates the first name to 9 characters and appends a period at the end
    std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"; // displays the last name of the contact, right aligned in a field of width 10
    // if the length of the last name is greater than 10 characters, it truncates the last name to 9 characters and appends a period at the end
    std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl; // displays the nickname of the contact, right aligned in a field of width 10
    // if the length of the nickname is greater than 10 characters, it truncates the nickname to 9 characters and appends a period at the end
    // std::endl is used to insert a newline character at the end of the line
}

/**
 * @brief Displays the contact information in a long format.
 */
void Contact::displayFull() {
    std::cout << "First Name: " << firstName << std::endl; // displays the first name of the contact, followed by a newline character
    std::cout << "Last Name: " << lastName << std::endl; // displays the last name of the contact, followed by a newline character
    std::cout << "Nickname: " << nickname << std::endl; // displays the nickname of the contact, followed by a newline character
    std::cout << "Phone Number: " << phoneNumber << std::endl; // displays the phone number of the contact, followed by a newline character
    std::cout << "Darkest Secret: " << darkestSecret << std::endl; // displays the darkest secret of the contact, followed by a newline character
}
