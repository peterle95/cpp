/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:06:26 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/16 11:49:16 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug() 
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() 
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() 
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

// The complain function takes a string parameter 'level' which indicates the type of complaint 
// the Harl object should respond to. It uses an array of pointers to member functions of the 
// Harl class, which correspond to the different complaint levels: debug, info, warning, and error.
// The levels are stored in a separate array of strings for comparison.
// The function iterates through the levels array, and when it finds a match with the provided 
// 'level', it calls the corresponding member function using the syntax (this->*complaints[i])().
// Here, 'this' is a pointer to the current instance of the Harl class, allowing access to its 
// member functions. If no valid level is found, it outputs "Invalid complaint level".

void Harl::complain(std::string level) 
{
    // Array of pointers to member functions of the Harl class.
    // Each element in this array corresponds to a specific complaint level.
    // The syntax 'void (Harl::*complaints[])()' declares an array of pointers to member functions
    // that return void and take no parameters. The '&Harl::functionName' syntax is used to get
    // the address of each member function.

    void (Harl::*complaints[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    /* The empty parentheses () indicate that the member functions 
    being pointed to do not take any parameters. For example, 
    these functions could be called without any arguments like this: 
    (this->*complaints[i])(); where complaints[i] points to a 
    member function such as &Harl::debug, which does not require 
    any input parameters.

    void (Harl::*complaints[])() declares an array of pointers to member functions of the Harl class.
    The void before the parentheses indicates that these functions return void.
    The empty parentheses () specify that these functions do not accept any arguments.
    */

    Harl harl; // Instantiate an object of the Harl class.
    // Array of strings representing the complaint levels.
    // Each string corresponds to the member function in the 'complaints' array.
    // This array is used to compare the input level with the defined levels.
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    // To determine the number of elements in the 'levels' array, we divide the total size of the array by the size of one element. 
    // 'sizeof(levels)' gives us the total number of bytes used by the entire array, while 'sizeof(levels[0])' gives us the size of a single element (a string in this case). 
    // By dividing these two values, we get the number of elements in the array, which is stored in 'sizeArray'. 
    // This allows us to iterate through the array safely without exceeding its bounds.
    // For example, if 'levels' contains {"DEBUG", "INFO", "WARNING", "ERROR"}, 
    // sizeof(levels) would return 4 * sizeof(std::string) because there are 4 strings in the array, 
    // and sizeof(levels[0]) would return sizeof(std::string), which is the size of one string. 
    // The value of sizeof(std::string) can vary depending on the implementation, but it typically returns a value around 24 to 32 bytes on most platforms. 
    // Therefore, sizeArray would be calculated as 4 * sizeof(std::string) / sizeof(std::string), resulting in sizeArray being 4.
    int sizeArray = sizeof(levels) / sizeof(levels[0]);

    for (int i = 0; i < sizeArray; i++) 
    {
        if (level == levels[i]) 
        {
            // 'this' is a pointer to the current instance of the Harl class.
            // Using 'this->' allows us to access the member function pointed to by complaints[i].
            // It is necessary to use 'this->' when calling a member function through a 
            //pointer to member function.
            (harl.*complaints[i])();
            /*In this line, the empty parentheses () are used to call the 
            member function that the pointer complaints[i] points to.
            (harl.*complaints[i])(); dereferences the pointer to the member function.

            Another way to call the member function is:
            (this->*complaints[i])(); dereferences the pointer to the member function, allowing access to the function itself.
            The empty parentheses () after this expression indicate that the function is being called with no arguments.
            But then remove the instance of the class Harl.*/
            return;
        }
    }
    std::cout << "Invalid complaint level" << std::endl;
}