/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:11:36 by pmolzer           #+#    #+#             */
/*   Updated: 2025/05/10 16:09:47 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();

    // Create an output file stream (ofstream) object named 'outfile'
    // The filename is created by concatenating the target name with "_shrubbery"
    // .c_str() converts the C++ string to a C-style char* which ofstream's constructor requires in C++98
    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    
    // Check if the file was opened successfully
    // If the file couldn't be created (due to permissions, disk space, invalid path, etc.),
    // the outfile object will evaluate to false in a boolean context
    if (!outfile)
    {
       // Print an error message to the standard error stream
       std::cerr << "Error: Could not create file" << std::endl;
       // Exit the function without drawing the tree if file creation failed
       return;
    }
    
    // The following lines write ASCII art of a tree to the file
    // The << operator is overloaded for ofstream to write data to the file
    // std::endl inserts a newline character and flushes the output buffer
    
    outfile << "    *    " << std::endl;
    outfile << "   ***   " << std::endl;
    outfile << "  *****  " << std::endl;
    outfile << " ******* " << std::endl;
    outfile << "*********" << std::endl;
    outfile << "    |    " << std::endl;
    outfile << "    |    " << std::endl;
    outfile << std::endl;
    outfile << "    *    " << std::endl;
    outfile << "   / \\   " << std::endl;
    outfile << "  /   \\  " << std::endl;
    outfile << " /     \\ " << std::endl;
    outfile << "---------" << std::endl;
    outfile << "    |    " << std::endl;
    outfile << "    |    " << std::endl;
    
    // Explicitly close the file (although this would happen automatically when outfile goes out of scope)
    // Closing ensures all buffered data is written to disk and system resources are released
    outfile.close();
}