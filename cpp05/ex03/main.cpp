/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:14:59 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/16 19:09:18 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Include all necessary header files for the bureaucracy system
#include "Bureaucrat.hpp"              // For Bureaucrat class (can sign and execute forms)
#include "AForm.hpp"                   // For abstract AForm base class
#include "ShrubberyCreationForm.hpp"   // Concrete form that creates ASCII tree files
#include "RobotomyRequestForm.hpp"     // Concrete form that performs "robotomy" with 50% success rate
#include "PresidentialPardonForm.hpp"  // Concrete form that grants presidential pardons
#include "Intern.hpp"                  // Factory class that creates forms by name
#include <iostream>                    // For console input/output operations

int main() 
{
    try  // Wrap everything in try-catch to handle any exceptions that might be thrown
    {
        // Create three bureaucrats with different grade levels (1=highest, 150=lowest)
        // Using ANSI color codes for better visual distinction in terminal output
        Bureaucrat high("\033[92mHigh Grade\033[0m", 1);    // Grade 1 - can do everything
        Bureaucrat mid("\033[94mMid Grade\033[0m", 50);     // Grade 50 - mid-level permissions
        Bureaucrat low("\033[91mLow Grade\033[0m", 150);    // Grade 150 - lowest permissions
        
        // Display the created bureaucrats to show their names and grades
        std::cout << "=== Bureaucrats Created ===" << std::endl;
        std::cout << high << std::endl;  // Uses overloaded << operator from Bureaucrat class
        std::cout << mid << std::endl;   // Displays: "Mid Grade, bureaucrat grade 50"
        std::cout << low << std::endl;   // Displays: "Low Grade, bureaucrat grade 150"
        std::cout << "===========================" << std::endl << std::endl;
        
        // Test the Intern class - this is the factory design pattern implementation
        std::cout << "=== Testing Intern Class ===" << std::endl;
        Intern someRandomIntern;  // Create an intern object (no special constructor parameters)
        
        // Declare pointers to hold forms that the intern will create, THESE ARE NOT OBJECTS    
        AForm* rrf;  // Will hold RobotomyRequestForm
        AForm* scf;  // Will hold ShrubberyCreationForm  
        AForm* ppf;  // Will hold PresidentialPardonForm
        // these are pointers that can point to any object that inherits from AForm.
        
        // Use intern to create different types of forms by string names
        // The intern acts as a factory - you give it a form name and target, it returns the appropriate form
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");     // Creates RobotomyRequestForm
        scf = someRandomIntern.makeForm("shrubbery creation", "home");     // Creates ShrubberyCreationForm
        ppf = someRandomIntern.makeForm("presidential pardon", "criminal"); // Creates PresidentialPardonForm
        
        // Test error handling - try to create a form with invalid name
        std::cout << "--- Testing invalid form ---" << std::endl;
        AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
        if (!invalidForm)  // makeForm returns NULL for invalid form names
            std::cout << "Invalid form returned NULL as expected" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        
        std::cout << "============================" << std::endl << std::endl;
        
        // Test the RobotomyRequestForm if it was successfully created
        if (rrf)  // Check if pointer is not NULL
        {
            std::cout << "=== Testing Robotomy Request Form ===" << std::endl;
            high.signForm(*rrf);    // High-grade bureaucrat signs the form (grade 1 can sign grade 72 requirement)
            /*So when signForm(*rrf) is called:
            We're passing a complete RobotomyRequestForm object
            That object contains _target = "Bender" as one of its properties
            The method can access all aspects of the form, not just the target
            
            The dereferencing (*rrf) is necessary because signForm expects an object reference, 
            but we have a pointer, so we need to convert pointer → object reference.*/
            high.executeForm(*rrf); // High-grade bureaucrat executes the form (grade 1 can execute grade 45 requirement)
                                   // This will print drilling noises and 50% chance success/failure message
            std::cout << "=====================================" << std::endl << std::endl;
        }
        
        // Test the ShrubberyCreationForm if it was successfully created
        if (scf)  // Check if pointer is not NULL
        {
            std::cout << "=== Testing Shrubbery Creation Form ===" << std::endl;
            mid.signForm(*scf);    // Mid-grade bureaucrat signs the form (grade 50 can sign grade 145 requirement)
            mid.executeForm(*scf); // Mid-grade bureaucrat executes the form (grade 50 can execute grade 137 requirement)
                                  // This will create a file named "home_shrubbery" with ASCII trees
            std::cout << "=======================================" << std::endl << std::endl;
        }
        
        // Test the PresidentialPardonForm if it was successfully created
        if (ppf)  // Check if pointer is not NULL
        {
            std::cout << "=== Testing Presidential Pardon Form ===" << std::endl;
            high.signForm(*ppf);    // High-grade bureaucrat signs the form (grade 1 can sign grade 25 requirement)
            high.executeForm(*ppf); // High-grade bureaucrat executes the form (grade 1 can execute grade 5 requirement)
                                   // This will print a message about Zaphod Beeblebrox pardoning the target
            std::cout << "========================================" << std::endl << std::endl;
        }
        
        // Clean up dynamically allocated memory
        // The intern's makeForm method uses 'new' to create forms, so we must 'delete' them
        delete rrf;  // Delete RobotomyRequestForm object
        delete scf;  // Delete ShrubberyCreationForm object
        delete ppf;  // Delete PresidentialPardonForm object
        // invalidForm is NULL, so no need to delete (deleting NULL is safe but unnecessary)
        
    } 
    catch (std::exception& e)  // Catch any standard exceptions that might be thrown
    {
        // Print error message in red color using ANSI escape codes
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
        // Possible exceptions: GradeTooHighException, GradeTooLowException, FormNotSignedException
    }
    
    return 0;  // Indicate successful program completion
}