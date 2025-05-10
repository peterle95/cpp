/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:14:12 by pmolzer           #+#    #+#             */
/*   Updated: 2025/05/10 15:55:15 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm.cpp
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "* DRILLING NOISES *" << std::endl;
    
    // Seed the random number generator with the current time
    // std::time(NULL) returns the current time as seconds since Jan 1, 1970
    // Using this value ensures we get different random numbers each time the program runs
    std::srand(std::time(NULL));
    /*Here's why srand() is necessary:

    Pseudorandom Number Generation: The C++ rand() function doesn't generate truly random numbers. It uses a 
        deterministic algorithm that produces a sequence of numbers that appear random.
    Seed Sets the Starting Point: srand() initializes the random number generator with a seed value, 
        effectively telling it where in its sequence to start.
    
    Without the srand(std::time(NULL)) line, the robotomy would have the exact same result (success or failure) every time for a given target, 
    which defeats the purpose of having a 50% chance.
    For a real-world application requiring better randomness, C++11 and later provide superior alternatives like <random> 
    library with std::mt19937 and distribution objects, but for this educational example, srand() with rand() is sufficient.*/
    
    // Generate a random number and check if it's even or odd
    // std::rand() generates a pseudo-random integer between 0 and RAND_MAX
    // The modulo 2 operation (% 2) gives either 0 (even) or 1 (odd)
    // In C++, non-zero values in conditionals are treated as true, zero as false
    if (std::rand() % 2)
       // If we got an odd number (1), the robotomy succeeds
       std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
       // If we got an even number (0), the robotomy fails
       std::cout << "Robotomy of " << this->_target << " failed." << std::endl;
}