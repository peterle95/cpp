/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 00:00:00 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/28 11:26:22 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"   // Include the Intern class header file
#include <iostream>     // For console output (std::cout)

// Default constructor - creates an intern with no special initialization needed
Intern::Intern()
{} // Empty body since interns don't need any member variables or special setup

// Copy constructor - creates a new intern by copying from another intern
Intern::Intern(const Intern& other)
{
    (void)other;  // Cast to void to suppress "unused parameter" compiler warning
                  // No actual copying needed since Intern has no member variables to copy
}

// Destructor - cleans up when an intern object is destroyed
Intern::~Intern()
{} // Empty body since there's no dynamic memory allocation or resources to clean up

// Assignment operator - assigns one intern to another
Intern& Intern::operator=(const Intern& other)
{
    (void)other;  // Cast to void to suppress "unused parameter" compiler warning
                  // No actual assignment needed since Intern has no member variables
    return *this; // Return reference to current object for chaining assignments
}

// Private helper method to create a ShrubberyCreationForm
// This encapsulates the creation logic and is used by the factory method
AForm* Intern::makeShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);  // Dynamically allocate and return new form
                                              // Caller is responsible for deleting this memory
}

// Private helper method to create a RobotomyRequestForm
// This encapsulates the creation logic and is used by the factory method
AForm* Intern::makeRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);   // Dynamically allocate and return new form
                                             // Caller is responsible for deleting this memory
}

// Private helper method to create a PresidentialPardonForm
// This encapsulates the creation logic and is used by the factory method
AForm* Intern::makePresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target); // Dynamically allocate and return new form
                                              // Caller is responsible for deleting this memory
}

// Main factory method - creates forms based on string names
// This is the core of the Factory design pattern implementation
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    // Array of valid form names that the intern can create
    // These strings must match exactly what the client passes in
    std::string formNames[3] = {
        "shrubbery creation",  // Index 0 - corresponds to ShrubberyCreationForm
        "robotomy request",    // Index 1 - corresponds to RobotomyRequestForm
        "presidential pardon"  // Index 2 - corresponds to PresidentialPardonForm
    };
    
    // Array of function pointers to the private creation methods
// Each pointer corresponds to the form name at the same index
// This is a clever way to avoid a long if-else chain or switch statement
AForm* (Intern::*formCreators[3])(const std::string&) = {
//  ^      ^       ^        ^  ^         ^
//  |      |       |        |  |         |
//  |      |       |        |  |         +-- Parameter type (const std::string&)
//  |      |       |        |  +-- Array size (3 elements)
//  |      |       |        +-- Array name (formCreators)
//  |      |       +-- Member function pointer syntax (*...)
//  |      +-- Scope (Intern class)
//  +-- Return type (AForm pointer)

   &Intern::makeShrubberyCreationForm,   // Index 0 - creates ShrubberyCreationForm
   //  ^        ^
   //  |        +-- Method name
   //  +-- Address-of operator (gets pointer to method)
   
   &Intern::makeRobotomyRequestForm,     // Index 1 - creates RobotomyRequestForm
   &Intern::makePresidentialPardonForm   // Index 2 - creates PresidentialPardonForm
};

// Usage syntax breakdown:
// (this->*formCreators[i])(target)
//   ^    ^       ^      ^    ^
//   |    |       |      |    +-- Argument passed to method
//   |    |       |      +-- Array index selection
//   |    |       +-- Array of function pointers
//   |    +-- Pointer-to-member dereference operator
//   +-- Object instance (this pointer)
/*
Holistic Explanation
This demonstrates C++ member function pointers - a powerful but complex feature. 
The syntax AForm* (Intern::*)(const std::string&) declares a pointer that can 
hold the address of any Intern method matching that signature.
The array creates a lookup table mapping indices to creation methods. Instead of:
    if (name == "shrubbery") return makeShrubberyCreationForm(target);
    else if (name == "robotomy") return makeRobotomyRequestForm(target);
// etc...

You get:
    return (this->*formCreators[i])(target);  // Single line, index-driven
This pattern scales better (add new forms by extending arrays) and demonstrates how C++*/
    
    // Loop through all available form names to find a match
    for (int i = 0; i < 3; i++)
    {
        // Check if the requested form name matches any of our valid names
        if (formName == formNames[i])
        {
            // Inform user that intern is creating the requested form
            std::cout << "Intern creates " << formName << std::endl;
            
            // Use the function pointer to call the appropriate creation method
            // (this->*formCreators[i]) dereferences the function pointer and calls it
            // with 'target' as the parameter
            return (this->*formCreators[i])(target);
        }
    }
    
    // If we reach here, the form name was not found in our valid names array
    // Print an error message to inform the user
    std::cout << "Error: Form name '" << formName << "' does not exist" << std::endl;
    
    // Return NULL to indicate failure - caller should check for this
    return NULL;
}