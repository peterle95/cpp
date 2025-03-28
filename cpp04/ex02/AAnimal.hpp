/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:47:14 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 17:18:14 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal 
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    virtual void makeSound() const = 0; // Pure virtual function
    /*The main advantages of abstract classes are:

    1. Force implementation of specific methods in derived classes
    2. Define a common interface for a group of related classes
    3. Prevent instantiation of base classes that don't make sense on their own
    4. Enable polymorphic behavior through a common base type
    
    In this exercise, it ensures that:
    - Every animal must have a `makeSound()` method
    - You can't create a generic "Animal" object
    - Different animal types provide their own unique sound implementation
    */
    std::string getType() const;
};

#endif