/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:21:31 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/21 17:23:26 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bureaucrat.cpp
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) 
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) 
{
    if (grade < 1) 
    {
        throw GradeTooHighException();
    }
    if (grade > 150) 
    {
        throw GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) 
{
    *this = other;
}

Bureaucrat::~Bureaucrat() 
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other) 
    {
        this->_grade = other._grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const 
{
    return this->_name;
}

int Bureaucrat::getGrade() const 
{
    return this->_grade;
}

void Bureaucrat::incrementGrade() 
{
    if (this->_grade - 1 < 1) 
    {
        throw GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (this->_grade + 1 > 150) 
    {
        throw GradeTooLowException();
    }
    this->_grade++;
}

void Bureaucrat::signForm(AForm& form) 
{
    try 
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << this->_name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        /*When `execute` is called on a form object, the program knows which concrete implementation to call 
        through dynamic binding (also known as runtime polymorphism). Here's how it works:

        1. The `AForm` class is abstract and defines a virtual `execute` method
        2. Each derived form class (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm) 
        overrides this method with its own implementation
        3. When `form.execute(*this)` is called in the Bureaucrat class, the actual form object's type is
         determined at runtime
        4. The program uses the virtual function table (vtable) to call the correct implementation based 
        on the actual object type
        
        This is C++'s implementation of polymorphism. Even though the parameter is typed as `AForm const &`, 
        the program will call the execute method of the actual derived class that the reference points to, not 
        the base class method.*/
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->_name << " couldn't execute " << form.getName()
                 << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade too low";
}