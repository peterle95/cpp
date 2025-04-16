/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:33:05 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/16 16:13:33 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*TASK:
Let’s design an artificial nightmare of offices, corridors, forms, and waiting queues.
Sounds fun? No? Too bad.
First, start with the smallest cog in this vast bureaucratic machine: the Bureaucrat.
A Bureaucrat must have:
• A constant name.
• A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
Any attempt to instantiate a Bureaucrat with an invalid grade must throw an excep￾tion:
either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

You will provide getters for both attributes: getName() and getGrade(). You must
also implement two member functions to increment or decrement the bureaucrat’s grade.
If the grade goes out of range, both functions must throw the same exceptions as the
constructor.
Remember, since grade 1 is the highest and 150 the lowest,
incrementing a grade 3 should result in a grade 2 for the bureaucrat.
The thrown exceptions must be catchable using try and catch blocks:
try
{
    do some stuff with bureaucrats 
}
catch (std::exception & e)
{
    handle exception 
}
You must implement an overload of the insertion («) operator to print output in the
following format (without the angle brackets):
<name>, bureaucrat grade <grade>.
As usual, submit some tests to prove that everything works as expected.
*/

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
