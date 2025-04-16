/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:02:06 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/16 13:55:45 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

// Forward declaration
class Form;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);

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
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif