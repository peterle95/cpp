/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:36:44 by pmolzer           #+#    #+#             */
/*   Updated: 2024/09/07 11:32:03 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // includes input/output functions, such as std::cout
#include <cctype>   // includes functions for manipulating characters, such as toupper

int main(int argc, char** argv) // main function, which is the entry point of the program
{
    if (argc == 1) // argc is the number of arguments passed to the program
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; // prints a string to the console, followed by a newline
    }
    else
    {
        int i = 1; // loop counter
        while (i < argc) // loop until all arguments have been processed
        {
            int j = 0; // loop counter for the current argument
            while (argv[i][j]) // loop until the end of the current argument is reached
            {
                std::cout << (char)toupper(argv[i][j]); // prints the current character of the argument, converted to uppercase
                j++; // increment the loop counter
            }
            std::cout << " "; // prints a space to separate the arguments
            i++; // increment the loop counter
        }
        std::cout << std::endl; // prints a newline to end the line
    }
    return 0; // returns 0 to indicate that the program has finished successfully
}

/*
 * argc: the number of arguments passed to the program (including the name of the program)
 * argv: an array of character pointers, where each element points to a string representing an argument
 *
 * The loop iterates over each argument, and for each argument, it iterates over each character in the argument string.
 * toupper is used to convert each character to uppercase, and the result is printed to the console.
 *
 * The outer loop iterates over each argument, and the inner loop iterates over each character in the argument string.
 * The variable i is used to keep track of the current argument being processed, and the variable 
 * j is used to keep track of the
 * current character being processed within that argument.
 *
 * The std::cout line prints the current argument, converted to uppercase, followed by a space to separate the arguments.
 *
 * The std::cout line at the end prints a newline to end the line.
 */
