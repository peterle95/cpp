/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:21:31 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/16 14:10:59 by pmolzer          ###   ########.fr       */
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