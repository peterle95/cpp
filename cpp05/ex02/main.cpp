/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:14:59 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/21 17:17:26 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/*The main differences between exercise ex01 and ex02.

The primary difference appears to be the transition from a concrete `Form` class in ex01 to an abstract `AForm` 
class in ex02 that introduces concrete implementations of specific form types.

Here are the key differences:

1. **Abstract Base Class**: 
   - In ex01, you had a concrete `Form` class
   - In ex02, this has been renamed to `AForm` and made abstract with a pure virtual function `execute()`

2. **Form Specialization**:
   - Ex02 introduces three concrete form classes that inherit from `AForm`:
     - `ShrubberyCreationForm`: Creates a file with ASCII trees (requires grades 145 to sign, 137 to execute)
     - `RobotomyRequestForm`: Makes drilling noises and has a 50% chance of successful robotomy (grades 72/45)
     - `PresidentialPardonForm`: Pardons someone by Zaphod Beeblebrox (grades 25/5)

3. **Form Execution**:
   - Ex01 likely just had the signing mechanism
   - Ex02 adds an execution mechanism via the `execute()` method that performs different actions based on the form type
   - Added `executeForm()` method to the `Bureaucrat` class

4. **Additional Exception**:
   - Ex02 adds a `FormNotSignedException` to prevent execution of unsigned forms

5. **Implementation Details**:
   - Each form type has different requirements for signing and execution
   - Each form performs a different action when executed:
     - `ShrubberyCreationForm` creates a file with ASCII art
     - `RobotomyRequestForm` performs a randomized robotomy operation
     - `PresidentialPardonForm` issues a presidential pardon

In summary, ex01 likely focused on the basic form mechanics (creating, signing forms), while ex02 extends this by 
making forms abstract and introducing specialized form types with unique behaviors and execution requirements.*/

int main() 
{
    try 
    {
        // Create bureaucrats with different grades
        Bureaucrat high("High Grade", 1);
        Bureaucrat mid("Mid Grade", 50);
        Bureaucrat low("Low Grade", 150);
        
        std::cout << "=== Bureaucrats Created ===" << std::endl;
        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;
        std::cout << "===========================" << std::endl << std::endl;
        
        // Test ShrubberyCreationForm (sign: 145, exec: 137)
        std::cout << "=== Testing ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrub("garden");
        
        // Low should be able to sign but not execute
        /*In low.signForm(shrub), the bureaucrat object low is calling its signForm method 
        with shrub (a ShrubberyCreationForm object) as the argument.  
        Looking at the implementation in Bureaucrat.cpp, the signForm method:
        
        Attempts to call form.beSigned(*this) - passing the bureaucrat itself to the form
        If successful, outputs a message that the bureaucrat signed the form
        If an exception occurs (like when the bureaucrat's grade is too low), it catches the 
        exception and prints a failure message
        In this specific case, since low has grade 150 and the ShrubberyCreationForm requires 
        grade 145 to sign, the attempt fails with a "Grade too low for form" exception, 
        which is caught and displayed in the output.
   	  */
        low.signForm(shrub);
        low.executeForm(shrub);  // Should fail
        
        mid.executeForm(shrub);
        std::cout << "====================================" << std::endl << std::endl;
        
        // Test RobotomyRequestForm (sign: 72, exec: 45)
        std::cout << "=== Testing RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robot("target");
        
        // Low shouldn't be able to sign or execute
        low.signForm(robot);  // Should fail
        
        // Mid should be able to sign and execute
        mid.signForm(robot);
        mid.executeForm(robot);
        std::cout << "===================================" << std::endl << std::endl;
        
        // Test PresidentialPardonForm (sign: 25, exec: 5)
        std::cout << "=== Testing PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardon("criminal");
        
        // Mid shouldn't be able to sign
        mid.signForm(pardon);  // Should fail
        
        // High should be able to sign and execute
        high.signForm(pardon);
        high.executeForm(pardon);
        std::cout << "======================================" << std::endl << std::endl;
        
        // Test executing without signing
        std::cout << "=== Testing Unsigned Form ===" << std::endl;
        ShrubberyCreationForm unsignedShrub("test");
        high.executeForm(unsignedShrub);  // Should fail
        std::cout << "============================" << std::endl;
        
    } 
    catch (std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}