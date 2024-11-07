/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:57:55 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/07 12:51:22 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is the beginning of the file. The first line is a comment that explains what the file is about.
// The lines that follow are the copyright information and the standard library includes.

#include "PhoneBook.hpp"
// This line includes the header file for the PhoneBook class.
// The PhoneBook class is a class that we have written, and it is not a standard library class.
// The header file contains the declaration of the class, and any other information that we need to use the class.

#include <iostream>
// This line includes the iostream library, which is a standard library.
// The iostream library is used for input and output, and it provides functions like cin and cout.

#include <string>
// This line includes the string library, which is a standard library.
// The string library is used to work with strings, and it provides functions like std::string and std::getline.

/*TASK OF THE PROGRAM:
 * The program should create a PhoneBook instance and repeatedly prompt the user for commands.
 * The program should handle the following commands: ADD, SEARCH, and EXIT.
 * You have to implement two classes:
 * PhoneBook
 * ◦ It has an array of contacts.
 * ◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
 * replace the oldest one by the new one.
 * ◦ Please note that dynamic allocation is forbidden.
 * Contact
 * ◦ Stands for a phonebook contact.
 * In your code, the phonebook must be instantiated as an instance of the PhoneBook
 * class. Same thing for the contacts. Each one of them must be instantiated as an instance
 * of the Contact class. You’re free to design the classes as you like but keep in mind that
 * anything that will always be used inside a class is private, and that anything that can be
 * used outside a class is public.
 */

int main() {
    // This is the beginning of the main function.
    // The main function is the entry point of the program, and it is called automatically when the program is started.
    // The main function returns an integer, which is the exit status of the program.

    PhoneBook book;
    // This line creates an instance of the PhoneBook class, which is a class that we have written.
    // The instance is named "book", and it is a local variable of the main function.

    std::string command;
    // This line creates a string variable named "command".
    // The string variable is used to store the command that the user enters.

    while (true) {
        // This line starts a while loop that will continue to run until the user enters the command "EXIT".
        // The while loop is used to repeatedly ask the user for a command until they enter "EXIT".

        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        // This line prints a message to the console, asking the user to enter a command.
        // The message is followed by a space, and then the prompt is displayed.

        std::cin >> command;
        // This line reads a line of input from the
        if (command == "ADD") {
            book.addContact();
        }
        else if (command == "SEARCH") {
            book.searchContact();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Invalid command" << std::endl;
        }
    }
    return 0;
}
