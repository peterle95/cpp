/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:33:05 by pmolzer           #+#    #+#             */
/*   Updated: 2025/05/07 15:44:31 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    
    std::string word = "four";

    try
    {
        std::cout << word.at(4) << std::endl; // this will be an out of range error
    }
    /* catch(...) // exeptions are thrown with a type, like (...) --> catches any type of exeption
    {
        // std::cerr << e.what() << '\n';
        std::cout << "Exeption thrown!" << std::endl;
    } */
    catch(std::out_of_range& e) 
    /* when the exeption is thrown, an out_of_range type object is going to be previded. 
    "e" is the reference to that object. e is an object that has a method called "what".
    Any "what" method is going to return a string which may contain information about the exeption that is taking place*/
    {
        // std::cerr << e.what() << '\n';
        std::cout << "Exeption:" << e.what() << std::endl;
    }

    /* try
    {
        int *array = new int[99999999999999999999999999];
    }
    catch(std::out_of_range& e) // this is not going to catch it because it's another type of exeption
    {
        std::cout << "Exeption:" << e.what() << std::endl;
    }
    catch(std::bad_alloc& e)
    {
        std::cout << "Second Exeption:" << e.what() << std::endl;
    } */

   // --> Exeption types have a hierarchy "exception" is the highest. LOOK THIS UP
    
    
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
   catch (const std::exception& e) 
   /*When your code enters the catch block after throwing an exception, here's what happens step by step:

    1. An exception is thrown (e.g., throw GradeTooHighException() in the incrementGrade() method)
    2. Program execution immediately jumps to the matching catch block: catch (const std::exception& e)
    3. The thrown exception object (of type GradeTooHighException) is caught as a reference to its base class (std::exception)
    4. When you call e.what() inside the catch block:
        - The compiler sees you're calling the what() method on an std::exception reference
        - At runtime, the program checks the actual type of the object e refers to (which is GradeTooHighException)
        - Because what() is a virtual function, the program uses the virtual function table (vtable) to find the correct implementation
        - It locates and calls GradeTooHighException's version of what(), not the base class version
    5. The method returns the C-string "Grade too high"
    6. The returned string is passed to std::cerr and printed*/
   {
       std::cerr << "Exception: " << e.what() << std::endl;
       /*You need to call it as e.what() because:
            1. what() is a method of the exception object
            2. e is your reference to that exception object*/
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
