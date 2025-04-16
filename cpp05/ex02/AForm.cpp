/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:45:23 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/16 13:55:07 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AForm.cpp (renamed from Form.cpp)
#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) 
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
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

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
      {
}

AForm::~AForm() 
{
}

AForm& AForm::operator=(const AForm& other) 
{
    if (this != &other) 
    {
        this->_signed = other._signed;
        // Note: cannot reassign const members (_name, _gradeToSign, _gradeToExecute)
    }
    return *this;
}

const std::string& AForm::getName() const 
{
    return this->_name;
}

bool AForm::isSigned() const 
{
    return this->_signed;
}

int AForm::getGradeToSign() const 
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const 
{
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() <= this->_gradeToSign) 
    {
        this->_signed = true;
    } 
    else 
    {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) 
{
    os << "Form: " << form.getName() 
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return "Grade too high for form";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return "Grade too low for form";
}

const char* AForm::FormNotSignedException::what() const throw() 
{
    return "Form is not signed";
}