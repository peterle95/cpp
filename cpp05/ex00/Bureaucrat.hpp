/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:02:06 by pmolzer           #+#    #+#             */
/*   Updated: 2025/05/22 17:43:09 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

// The Bureaucrat class represents a bureaucrat with a name and a grade.
class Bureaucrat
{
private:
    const std::string _name; // The name of the bureaucrat, cannot be changed after initialization.
    int _grade; // The grade of the bureaucrat, which determines their rank.

public:
    Bureaucrat(); // Default constructor.
    Bureaucrat(const std::string& name, int grade); // Parameterized constructor.
    Bureaucrat(const Bureaucrat& other); // Copy constructor.
    ~Bureaucrat(); // Destructor.
    Bureaucrat& operator=(const Bureaucrat& other); // Assignment operator.

    // Nested exception class for handling cases where the grade is too high.
    // The GradeTooHighException class is a nested exception class that 
    // inherits from std::exception.
    // The throw() specifier indicates that this function does not throw any exceptions.
    // It is used to inform the compiler and the programmer that 
    // the function is guaranteed not to throw,
    // which can help with optimization and exception safety.
    class GradeTooHighException : public std::exception 
    {
        public: 
            virtual const char* what() const throw(); // Override what() to return an error message.
   
        /*This is called an "exception specification" and it does a few important things:

        Purpose: It declares that the function what() won't throw any exceptions of its 
        own. This was C++'s way of specifying which exceptions a function might throw.
        How it works: The empty throw() means "this function will not throw any 
        exceptions." If the function did try to throw an exception, 
        the program would call std::unexpected() and likely terminate.
        Why it's needed:

        It's part of the interface defined in the base class std::exception
        It helps with code reliability by documenting exception behavior
        It ensures that when you're already handling one exception, 
        the exception-handling mechanism itself won't throw additional exceptions

        In your specific case, the what() function implements the virtual method 
        from std::exception that returns a C-string describing the exception. 
        Since this is meant to be used during exception handling, it's 
        important that this function itself is "safe" and won't throw additional exceptions.
        Note that in modern C++ (C++11 and later), this syntax is deprecated 
        in favor of noexcept, but since you're using C++98 
        (as specified in your Makefile), the throw() specification is the 
        appropriate approach.*/
    };

    // Nested exception class for handling cases where the grade is too low.
    class GradeTooLowException : public std::exception 
    {
        public: 
            virtual const char* what() const throw();
            /*
            - virtual: Specifies this is a virtual function that can be overridden by derived classes. This enables polymorphic behavior.
            - const char*: The return type - a pointer to constant characters (a C-style string that can't be modified).
            - what(): The function name.
            - const (after the function name): Indicates this is a "const member function" that doesn't modify the object's state. 
                    This allows the function to be called on const objects.
            - throw(): This is an exception specification (in C++98) that declares this function doesn't throw any exceptions. 
                    In modern C++ (C++11 and later), this would be replaced with noexcept.

            In your derived exception classes, when you override this method:

            You're not required to use the virtual keyword again (though some add it for clarity)
            You must match the function signature exactly (return type, parameter list, const-ness)
            You must include the exception specification throw()
            
            This declaration ensures that when code catches an std::exception reference but the actual object is your 
            custom exception, the proper error message is displayed.*/
    };

    // Getter for the bureaucrat's name.
    const std::string& getName() const;
    // Getter for the bureaucrat's grade.
    int getGrade() const;
    /*both getName() and getGrade() are actually declared the same way - 
    they're both const member functions (notice the const at the end of both declarations). 
    The difference you're seeing is in their return types:
    
    Here's why they're different:
        
        getName() returns const std::string&:
        
        Returns a const reference to avoid copying the string (more efficient)
        The const in the return type prevents the caller from modifying the original string
        Since _name is declared as const std::string _name, returning a const reference makes sense
        
        getGrade() returns int:
        
        Returns the integer by value (which is cheap to copy)
        For primitive types like int, returning by value is the standard practice
        There's no performance benefit to returning a reference to an int
        Returning int by value is safer - the caller gets their own copy and can't accidentally modify the original*/

    // Method to increment the bureaucrat's grade (make it higher).
    void incrementGrade();
    // Method to decrement the bureaucrat's grade (make it lower).
    void decrementGrade();
};

// Overloaded output stream operator to print Bureaucrat information.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif