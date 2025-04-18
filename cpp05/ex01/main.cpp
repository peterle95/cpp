/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:10:25 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/18 13:09:49 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    try 
    {
        // Test basic Form functionality
        // Creates a Form object named "Tax Form" requiring grade 50 to sign and 25 to execute.
        Form taxForm("Tax Form", 50, 25);
        // Prints the form's information using the overloaded << operator.
        std::cout << taxForm << std::endl;
        
        // Test high-level bureaucrat signing a form
        // Creates a high-ranking Bureaucrat (grade 10) named "Director".
        Bureaucrat highLevel("Director", 10);
        // Displays the bureaucrat's information.
        std::cout << highLevel << std::endl;
        // Director signs the form - succeeds because grade 10 is better than required grade 50.
        highLevel.signForm(taxForm);
        // Shows the form again - now with signed status = Yes.
        std::cout << taxForm << std::endl;
        
        // Test attempting to sign an already signed form
        // Creates another bureaucrat and attempts to sign the already-signed form (succeeds but has no effect).
        Bureaucrat anotherHighLevel("Manager", 20);
        anotherHighLevel.signForm(taxForm);
        
        // Test low-level bureaucrat failing to sign a form
        // Creates another form requiring grade 15 to sign.
        Form secretForm("Secret Clearance", 15, 5);
        // Displays the secret form details.
        std::cout << secretForm << std::endl;
        // Creates a low-ranking bureaucrat (grade 100).
        Bureaucrat lowLevel("Intern", 100);
        // Shows the intern's information.
        std::cout << lowLevel << std::endl;
        // Intern attempts to sign but fails since grade 100 > required grade 15. Exception is caught in signForm().
        lowLevel.signForm(secretForm);
        // Shows the form is still unsigned.
        std::cout << secretForm << std::endl;
        
        // Test form with invalid grade (too high)
        // Tries to create form with grade 0 (too high) - throws exception caught by outer try-catch.
        Form invalidForm("Invalid Form", 0, 50);
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try 
    {
        // Test form with invalid grade (too low)
        // In second try block, attempts to create form with grade 151 (too low) 
        // throws another exception.
        Form invalidForm("Invalid Form", 50, 151);
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

/* COMPARISON WITH PREVIOUS EXERCISE:
This exercise builds on the previous one by adding a "Form" class to create a more complex interaction 
pattern. The key purposes are:

1. Implementing class relationships - showing how two classes can interact with each other
2. Managing circular dependencies through forward declarations
3. Practicing more advanced exception handling when one class interacts with another
4. Implementing a signing system where a Bureaucrat can sign a Form if their grade is high enough
5. Demonstrating object state changes (forms becoming signed)
6. Creating a more realistic bureaucratic system with both forms and bureaucrats

The main addition is the form-signing mechanic where bureaucrats can only sign forms if 
they have sufficient clearance (grade). This exercise teaches proper class interaction 
design and deeper error handling in a practical context.*/