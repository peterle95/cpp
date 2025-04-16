/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:45:23 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/16 14:18:27 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) 
{}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1) 
    {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) 
    {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{}

Form::~Form() 
{}

Form& Form::operator=(const Form& other) 
{
    if (this != &other) 
    {
        this->_signed = other._signed;
        // Note: cannot reassign const members (_name, _gradeToSign, _gradeToExecute)
    }
    return *this;
}

const std::string& Form::getName() const 
{
    return this->_name;
}

bool Form::isSigned() const 
{
    return this->_signed;
}

int Form::getGradeToSign() const 
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const 
{
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() <= this->_gradeToSign) 
    {
        this->_signed = true;
    } else 
    {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form) 
{
    os << "Form: " << form.getName() 
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Grade too high for form";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Grade too low for form";
}