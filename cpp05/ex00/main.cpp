/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:33:05 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/16 16:09:39 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    try 
    {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try 
    {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
