/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:21:31 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/18 12:49:55 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor initializes the bureaucrat with a default name and grade.
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

// Parameterized constructor initializes the bureaucrat with a given name and grade.
// Throws exceptions if the grade is out of valid range (1-150).
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException(); // Grade cannot be higher than 1.
    }
    if (grade > 150) {
        throw GradeTooLowException(); // Grade cannot be lower than 150.
    }
    this->_grade = grade; // Set the grade if it's valid.
}

// Copy constructor for creating a Bureaucrat from another Bureaucrat.
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    *this = other; // Use the assignment operator to copy the grade.
}

// Destructor for Bureaucrat (no dynamic memory to free).
Bureaucrat::~Bureaucrat() {}

// Assignment operator to copy the grade from another Bureaucrat.
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade; // Copy the grade.
    }
    return *this; // Return the current object.
}

// Getter for the bureaucrat's name.
const std::string& Bureaucrat::getName() const {
    return this->_name; // Return the name.
}

// Getter for the bureaucrat's grade.
int Bureaucrat::getGrade() const {
    return this->_grade; // Return the grade.
}

// Method to increment the bureaucrat's grade (make it higher).
void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1) {
        throw GradeTooHighException(); // Cannot increment beyond grade 1.
    }
    this->_grade--; // Decrement the grade (higher rank).
}

// Method to decrement the bureaucrat's grade (make it lower).
void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150) {
        throw GradeTooLowException(); // Cannot decrement beyond grade 150.
    }
    this->_grade++; // Increment the grade (lower rank).
}

// Overloaded output stream operator to print Bureaucrat information.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os; // Return the output stream.
}

// Implementation of the GradeTooHighException's what() method.
// The return type is const char*, which indicates that this function returns a pointer to a constant character string.
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    // The 'const' qualifier after the function name indicates that this method does not modify any member variables of the class.
    // The 'throw()' specifier indicates that this function is guaranteed not to throw any exceptions.
    return "Grade too high"; // Return error message for too high grade.
}

// Implementation of the GradeTooLowException's what() method.
// The return type is const char*, which indicates that this function returns a pointer 
// to a constant character string.
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    // The 'const' qualifier after the function name indicates that this method does 
    // not modify any member variables of the class.
    // The 'throw()' specifier indicates that this function is guaranteed not to throw any exceptions.
    return "Grade too low"; // Return error message for too low grade.
}