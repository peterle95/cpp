/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:45:33 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/18 12:55:45 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

/*In the Form.hpp file, the declaration `class Bureaucrat;` at the top is a forward declaration. 
This is necessary because:

1. Form.hpp includes Bureaucrat.hpp, and Bureaucrat.hpp includes Form.hpp, creating a circular dependency
2. The Form class needs to know about the Bureaucrat class since it has a method `beSigned(const Bureaucrat& bureaucrat)`
3. The forward declaration tells the compiler that Bureaucrat is a class that will be fully defined elsewhere

This approach breaks the circular dependency while maintaining proper type checking during compilation. 
The complete Bureaucrat class definition isn't needed in Form.hpp since it only uses Bureaucrat as a 
reference parameter, not accessing its internal members directly.*/
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