/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:14:28 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/19 21:32:21 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"  // Include the Bureaucrat class declaration
#include "Form.hpp"        // Include Form class declaration to use Form methods

/* Default constructor
   Creates a bureaucrat with default name and lowest possible grade */
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) 
{}  // Grade 150 is the lowest rank in the bureaucracy

/* Parameterized constructor 
   Creates a bureaucrat with specific name and grade */
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) 
{
    /* Validate that grade is within the allowed range (1-150) */
    if (grade < 1) 
    {
        throw GradeTooHighException();  // Grade 1 is highest possible rank (like 1st place)
    }
    if (grade > 150) 
    {
        throw GradeTooLowException();   // Grade 150 is lowest possible rank
    }
    this->_grade = grade;  // Set the grade if it's valid
}

/* Copy constructor
   Note that const member _name is properly initialized in the initialization list */
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) 
{
    *this = other;  // Use assignment operator to copy other properties
}

/* Destructor - no dynamic memory to free */
Bureaucrat::~Bureaucrat() 
{}

/* Assignment operator
   Limited to copying only the non-const members */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other)  // Self-assignment check (standard practice)
    {
        this->_grade = other._grade;  // Only copy the grade, not the name (which is const)
    }
    return *this;  // Return reference to this object (standard practice)
}

/* Getter methods - provide read access to private member variables */
const std::string& Bureaucrat::getName() const 
{
    return this->_name;  // Return bureaucrat name
}

int Bureaucrat::getGrade() const 
{
    return this->_grade;  // Return bureaucrat grade (used by Form::beSigned)
}

/* Method to increase bureaucrat's rank by decreasing grade number
   (Remember: lower grade number = higher rank) */
void Bureaucrat::incrementGrade() 
{
    if (this->_grade - 1 < 1)  // Check if incrementing would make grade too high
    {
        throw GradeTooHighException();  // Can't go higher than grade 1
    }
    this->_grade--;  // Decrement grade number = increase rank
}

/* Method to decrease bureaucrat's rank by increasing grade number */
void Bureaucrat::decrementGrade() 
{
    if (this->_grade + 1 > 150)  // Check if decrementing would make grade too low
    {
        throw GradeTooLowException();  // Can't go lower than grade 150
    }
    this->_grade++;  // Increment grade number = decrease rank
}

/* Method to attempt signing a form
   This is a key method that links Bureaucrat with Form */
void Bureaucrat::signForm(Form& form) 
{
    try 
    {
        form.beSigned(*this);  // Try to sign the form, passing this bureaucrat
        /* If successful, print confirmation message */
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } 
    catch (std::exception& e)  // Catch any exception thrown by form.beSigned()
    {
        /* If signing fails, print failure message with the reason */
        std::cout << this->_name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

/* Output stream operator overload for printing Bureaucrat objects
   This is used in main.cpp to display bureaucrat information */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

/* Each part serves a specific purpose:

    1. const char* - This is the return type
    Returns a pointer to a constant character (essentially a string that can't be modified)
    Standard return type for exception messages in C++
    
    2. Bureaucrat::GradeTooHighException:: - Specifies the class scope
    Bureaucrat:: means this belongs to the Bureaucrat class
    GradeTooHighException:: means this is a method of the nested GradeTooHighException class
    This syntax is necessary because we're defining a method that was declared inside a nested class
    
    3. what() - The function name
    Standard method name from std::exception that provides an error message
    This is the method that's called when you use e.what() on an exception
    
    4. const - Member function qualifier
    Indicates this method doesn't modify any member variables of the class
    Required for compatibility with the base class (std::exception)
    
    5. throw() - Exception specification (C++98 syntax)
    In C++98, this means the function doesn't throw any exceptions
    This is required to match the signature from std::exception
    In modern C++, this would be noexcept instead
    
    Each element is necessary because:
    We're overriding a virtual method from a base class (std::exception)
    The method signature must match exactly for proper polymorphic behavior
    The method needs to be defined outside the class definition, requiring the full scoping
    If any part were missing, it either wouldn't compile or wouldn't properly override the base 
    class method, which would break polymorphism (and the ability to call the right what() 
    method through a base class pointer).
*/
const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade too high";  // Error message for too high grade (below 1)
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade too low";   // Error message for too low grade (above 150)
}