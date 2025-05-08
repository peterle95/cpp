/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:10:25 by pmolzer           #+#    #+#             */
/*   Updated: 2025/05/08 14:16:33 by pmolzer          ###   ########.fr       */
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
        Form taxForm("\033[31mTax Form\033[0m", 50, 25);
        std::cout << taxForm << std::endl;
        
        // Test high-level bureaucrat signing a form
        Bureaucrat highLevel("\033[92mDirector\033[0m", 10);
        std::cout << highLevel << std::endl;
        highLevel.signForm(taxForm);
        std::cout << taxForm << std::endl;
        
        // Test attempting to sign an already signed form
        Bureaucrat anotherHighLevel("\033[92mManager\033[0m", 20);
        anotherHighLevel.signForm(taxForm);
        
        // Test low-level bureaucrat failing to sign a form
        Form secretForm("\033[93mSecret Clearance\033[0m", 15, 5);
        std::cout << secretForm << std::endl;
        Bureaucrat lowLevel("\033[92mIntern\033[0m", 100);
        std::cout << lowLevel << std::endl;
        lowLevel.signForm(secretForm);
        std::cout << secretForm << std::endl;
        
        // Test form with invalid grade (too high)
        Form invalidForm("Invalid Form", 0, 50);
    } 
    catch (std::exception& e) 
    {
        std::cout << "\033[31mException: \033[0m" << e.what() << std::endl;
    }
    
    try 
    {
        // Test form with invalid grade (too low)
        Form invalidForm("Invalid Form", 50, 151);
    } 
    catch (std::exception& e) 
    {
        std::cout << "\033[31mException: \033[0m" << e.what() << std::endl;
    }

    return 0;
}