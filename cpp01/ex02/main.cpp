/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:19:06 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/09 14:23:15 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TASK OF THE PROGRAM:
Write a program that contains:
• A string variable initialized to "HI THIS IS BRAIN".
• stringPTR: A pointer to the string.
• stringREF: A reference to the string.
Your program has to print:
• The memory address of the string variable.
• The memory address held by stringPTR.
• The memory address held by stringREF.
And then:
• The value of the string variable.
• The value pointed to by stringPTR.
• The value pointed to by stringREF.
That’s all, no tricks. The goal of this exercise is to demystify references which can
seem completely new. Although there are some little differences, this is another syntax
for something you already do: address manipulation.*/

#include <iostream>
#include <string>

// This program demonstrates the use of pointers and references in C++.
// It initializes a string variable, creates a pointer and a reference to that string,
// and then prints their memory addresses and values.

int main() 
{
    std::string str = "HI THIS IS BRAIN"; // Initialize a string variable with a message.
    std::string *stringPTR = &str; // Create a pointer that holds the address of the string variable.
    std::string &stringREF = str; // Create a reference that refers to the string variable.

    // Print memory addresses
    std::cout << "Memory address of the string variable: " << &str << std::endl; // Print the address of the string variable.
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl; // Print the address stored in the pointer.
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl; // Print the address of the reference (same as the string variable).

    // Print values
    std::cout << "Value of the string variable: " << str << std::endl; // Print the value of the string variable.
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl; // Dereference the pointer to get the value it points to.
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl; // Print the value of the reference (same as the string variable).

    return 0; // Return 0 to indicate successful execution.
}

// Pointers and references are both used to refer to other variables, but they have some key differences and similarities:
// Similarities:
// - Both can be used to access the value of the variable they refer to.
// - Both can be used to modify the value of the variable they refer to (if the variable is not const).
// 
// Use Cases:
// - Pointers are often used in dynamic memory allocation, data structures (like linked lists), and when you need to manage the lifetime of an object manually.
// - References are typically used for function parameters and return types when you want to avoid copying large objects, providing a cleaner syntax for accessing variables.
//
// Differences:
// - A pointer can be reassigned to point to a different variable, while a reference cannot be changed once it is initialized.
// - Pointers can be null (i.e., they can point to nothing), whereas references must always refer to a valid object.
// - The syntax for dereferencing a pointer (using *) is different from accessing a reference (which behaves like the variable itself).
// - Pointers require explicit memory management (e.g., using new and delete), while references do not.