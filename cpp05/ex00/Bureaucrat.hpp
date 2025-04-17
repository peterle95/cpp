/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:02:06 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/17 15:24:00 by pmolzer          ###   ########.fr       */
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
    };

    // Nested exception class for handling cases where the grade is too low.
    class GradeTooLowException : public std::exception 
    {
        public: 
            virtual const char* what() const throw(); // Override what() to return an error message.
    };

    // Getter for the bureaucrat's name.
    const std::string& getName() const;
    // Getter for the bureaucrat's grade.
    int getGrade() const;

    // Method to increment the bureaucrat's grade (make it higher).
    void incrementGrade();
    // Method to decrement the bureaucrat's grade (make it lower).
    void decrementGrade();
};

// Overloaded output stream operator to print Bureaucrat information.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif