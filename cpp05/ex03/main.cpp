/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:14:59 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/12 15:03:29 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() 
{
    try 
    {
        Bureaucrat high("\033[92mHigh Grade\033[0m", 1);
        Bureaucrat mid("\033[94mMid Grade\033[0m", 50);
        Bureaucrat low("\033[91mLow Grade\033[0m", 150);
        
        std::cout << "=== Bureaucrats Created ===" << std::endl;
        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;
        std::cout << "===========================" << std::endl << std::endl;
        
        // Test Intern class
        std::cout << "=== Testing Intern Class ===" << std::endl;
        Intern someRandomIntern;
        AForm* rrf;
        AForm* scf;
        AForm* ppf;
        
        // Create forms using intern
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "home");
        ppf = someRandomIntern.makeForm("presidential pardon", "criminal");
        
        // Test invalid form name (this will return NULL and print error)
        std::cout << "--- Testing invalid form ---" << std::endl;
        AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
        if (!invalidForm)
            std::cout << "Invalid form returned NULL as expected" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        
        std::cout << "============================" << std::endl << std::endl;
        
        // Test the created forms
        if (rrf)
        {
            std::cout << "=== Testing Robotomy Request Form ===" << std::endl;
            high.signForm(*rrf);
            high.executeForm(*rrf);
            std::cout << "=====================================" << std::endl << std::endl;
        }
        
        if (scf)
        {
            std::cout << "=== Testing Shrubbery Creation Form ===" << std::endl;
            mid.signForm(*scf);
            mid.executeForm(*scf);
            std::cout << "=======================================" << std::endl << std::endl;
        }
        
        if (ppf)
        {
            std::cout << "=== Testing Presidential Pardon Form ===" << std::endl;
            high.signForm(*ppf);
            high.executeForm(*ppf);
            std::cout << "========================================" << std::endl << std::endl;
        }
        
        // Clean up dynamically allocated forms
        delete rrf;
        delete scf;
        delete ppf;
        // invalidForm is NULL, so no need to delete
        
    } 
    catch (std::exception& e) 
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
    }
    
    return 0;
}