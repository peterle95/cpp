/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:14:59 by pmolzer           #+#    #+#             */
/*   Updated: 2025/05/09 12:31:41 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() 
{
    try 
    {
        // Create bureaucrats with different grades
        Bureaucrat high("\033[92mHigh Grade\033[0m", 1); // Green
        Bureaucrat mid("\033[94mMid Grade\033[0m", 50);    // Blue
        Bureaucrat low("\033[91mLow Grade\033[0m", 150);    // Red
        
        std::cout << "=== Bureaucrats Created ===" << std::endl;
        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;
        std::cout << "===========================" << std::endl << std::endl;
        
        // Test ShrubberyCreationForm (sign: 145, exec: 137)
        std::cout << "=== Testing ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrub("\033[35mgarden\033[0m");
        
        // Low should be able to sign but not execute
        low.signForm(shrub);
        low.executeForm(shrub);  // Should fail
        
        // Mid should be able to execute
        mid.executeForm(shrub);
        std::cout << "====================================" << std::endl << std::endl;
        
        // Test RobotomyRequestForm (sign: 72, exec: 45)
        std::cout << "=== Testing RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robot("\033[31mtarget\033[0m");
        
        // Low shouldn't be able to sign or execute
        low.signForm(robot);  // Should fail
        
        // Mid should be able to sign and execute
        mid.signForm(robot);
        mid.executeForm(robot);
        std::cout << "===================================" << std::endl << std::endl;
        
        // Test PresidentialPardonForm (sign: 25, exec: 5)
        std::cout << "=== Testing PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardon("\033[33mcriminal\033[0m");
        
        // Mid shouldn't be able to sign
        mid.signForm(pardon);  // Should fail
        
        // High should be able to sign and execute
        high.signForm(pardon);
        high.executeForm(pardon);
        std::cout << "======================================" << std::endl << std::endl;
        
        // Test executing without signing
        std::cout << "=== Testing Unsigned Form ===" << std::endl;
        ShrubberyCreationForm unsignedShrub("\033[36mtest\033[0m");
        high.executeForm(unsignedShrub);  // Should fail
        std::cout << "============================" << std::endl;
        
    } 
    catch (std::exception& e) 
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
    }
    
    return 0;
}