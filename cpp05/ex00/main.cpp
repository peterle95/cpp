/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:33:05 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/16 16:22:00 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    try {
int main() 
{
   // FIRST TEST CASE: Testing incrementGrade() when reaching grade limit
   try 
   {
       // Create a Bureaucrat named "Alice" with grade 2 (second highest grade)
       Bureaucrat b1("Alice", 2);
       // Print the initial state using the overloaded << operator
       std::cout << b1 << std::endl;

       // Increment Alice's grade from 2 to 1 (the highest possible grade)
       b1.incrementGrade();
       // Print Alice's updated information - should show grade 1
       std::cout << b1 << std::endl;

       // Try to increment again - this should throw a GradeTooHighException
       // since grade 1 is already the highest possible grade
       b1.incrementGrade();
       // This line won't execute if an exception is thrown
       std::cout << b1 << std::endl;
   } 
   // Catch any exceptions that inherit from std::exception
   // (including our custom GradeTooHighException)
   catch (const std::exception& e) 
   {
       // Print the error message from the exception's what() method
       std::cerr << "Exception: " << e.what() << std::endl;
   }

   std::cout << std::endl;

   // SECOND TEST CASE: Testing decrementGrade() when reaching grade limit
   try 
   {
       // Create a Bureaucrat named "Bob" with grade 149 (second lowest grade)
       Bureaucrat b2("Bob", 149);
       // Print the initial state
       std::cout << b2 << std::endl;

       // Decrement Bob's grade from 149 to 150 (the lowest possible grade)
       b2.decrementGrade();
       // Print Bob's updated information - should show grade 150
       std::cout << b2 << std::endl;

       // Try to decrement again - this should throw a GradeTooLowException
       // since grade 150 is already the lowest possible grade
       b2.decrementGrade();
       // This line won't execute if an exception is thrown
       std::cout << b2 << std::endl;
   } 
   // Catch any exceptions
   catch (const std::exception& e) 
   {
       // Print the error message
       std::cerr << "Exception: " << e.what() << std::endl;
   }

   return 0;
}
