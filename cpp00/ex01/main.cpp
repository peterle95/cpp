/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:57:55 by pmolzer           #+#    #+#             */
/*   Updated: 2024/09/07 19:03:18 by pmolzer          ###   ########.fr       */
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
    }