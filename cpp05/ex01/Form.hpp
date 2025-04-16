/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:45:33 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/16 13:54:48 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    ~Form();
    Form& operator=(const Form& other);

    class GradeTooHighException : public std::exception 
    {
        public: 
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception 
    {
        public: 
            virtual const char* what() const throw();
    };

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif