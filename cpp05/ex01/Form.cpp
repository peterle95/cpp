/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:04:53 by pmolzer           #+#    #+#             */
/*   Updated: 2025/05/07 16:31:19 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"  // Include the Form class declaration

/* Default constructor
   Creates a form with default values (similar to Bureaucrat's default constructor) */
Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) 
{}  // Initializes with lowest possible grade requirements (150)

/* Parameterized constructor 
   Creates a form with specific name and grade requirements */
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    /* Validate that grades are within the allowed range (1-150)
       This is similar to the validation in Bureaucrat's constructor */
    if (gradeToSign < 1 || gradeToExecute < 1) 
    {
        throw GradeTooHighException();  // Same exception logic as in Bureaucrat class
    }
    if (gradeToSign > 150 || gradeToExecute > 150) 
    {
        throw GradeTooLowException();  // Same exception logic as in Bureaucrat class
    }
}

/* Copy constructor
   Note that const members are properly initialized in the initialization list */
Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{}  // Copies all properties from another Form

/* Destructor - no dynamic memory to free */
Form::~Form() 
{}

/* Assignment operator
   Limited to copying only the non-const members */
Form& Form::operator=(const Form& other) 
{
    if (this != &other)  // Self-assignment check (standard practice)
    {
        this->_signed = other._signed;  // Only copy whether it's signed
        // Note: cannot reassign const members (_name, _gradeToSign, _gradeToExecute)
        // This distinguishes it from Bureaucrat's assignment, which can copy grade but not name
    }
    return *this;  // Return reference to this object (standard practice)
}

/* Getter methods - provide read access to private member variables */
const std::string& Form::getName() const 
{
    return this->_name;  // Return form name (called by signForm in Bureaucrat class)
}

bool Form::isSigned() const 
{
    return this->_signed;  // Return signed status (used in operator<<)
}

int Form::getGradeToSign() const 
{
    return this->_gradeToSign;  // Return required grade to sign (used in operator<<)
}

int Form::getGradeToExecute() const 
{
    return this->_gradeToExecute;  // Return required grade to execute (used in operator<<)
}

/* Key method: Attempts to sign the form based on bureaucrat's grade
   This is called from Bureaucrat::signForm() method */
void Form::beSigned(const Bureaucrat& bureaucrat) 
{
    /*If this condition fails, it means the bureaucrat's grade number is higher than 
    the required grade to sign (remembering that lower numbers = higher rank). 
    So the only possible error here is that the bureaucrat's grade is "too low" in 
    terms of authority/rank (or "too high" numerically).
    The "grade too high" exception isn't relevant in this particular method because:
    
    The bureaucrat object passed as parameter is already validated (its grade is between 1-150)
    The form's grade requirements are already validated (they're between 1-150)
    The only possible failure is that the bureaucrat lacks sufficient authority
    
    So the flow is exactly as you described:
    
    If the bureaucrat's grade is inadequate, throw GradeTooLowException()
    This exception is caught in the catch block in Bureaucrat::signForm()
    The e.what() call invokes the overridden what() method from Form::GradeTooLowException
    Which returns the string "Grade too low for form"
    
    The "too high" exceptions would be thrown in other contexts - like when 
    creating a Form or Bureaucrat with invalid grade values, but not during the signing process itself.*/
    if (bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;  // Sign the form
    } else 
    {
        /* Throw exception if grade is too low
           This exception will be caught in Bureaucrat::signForm() */
        throw GradeTooLowException();
    }
}

/* Output stream operator overload for printing Form objects
   This is used in main.cpp to display form information */
std::ostream& operator<<(std::ostream& os, const Form& form) 
{
    os << "Form: " << form.getName() 
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       /*This line is part of the overloaded << operator.
       Here's what's happening:

        The code is using the ternary conditional operator ? : which works like a compact if-else statement
        form.isSigned() is called, which returns a boolean value (true or false)
        If form.isSigned() returns true, the expression evaluates to "Yes"
        If form.isSigned() returns false, the expression evaluates to "No"
        The resulting string ("Yes" or "No") is then inserted into the output stream
        
        This creates a user-friendly output when displaying a Form object. Instead of showing 
        "true" or "false" (or worse, 1 or 0) for the signed status, it shows 
        "Yes" or "No" which is more readable for users.*/
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;  // Similar to Bureaucrat's operator<< implementation
}

/* Exception class implementations - provide error messages
   Similar pattern to Bureaucrat's exception implementations */
const char* Form::GradeTooHighException::what() const throw() 
{
    return "Grade too high for form";  // Error message for too high grade
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Grade too low for form";  // Error message for too low grade
}