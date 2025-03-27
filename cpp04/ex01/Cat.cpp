/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:42:50 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 12:20:56 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/*Subject: Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain.*/
Cat::Cat() : brain(new Brain())
{
    type = "Cat";
    std::cout << "\033[31mCat\033[0m constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) 
{
    std::cout << "\033[31mCat\033[0m copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "\033[31mCat\033[0m assignment operator called" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "\033[31mCat\033[0m destructor called" << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}