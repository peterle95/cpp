/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:48:01 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/10 11:08:34 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* Constructor that initializes the Weapon object with a specific type 
 * 
 * Syntax Explanation:
 * - 'Weapon::Weapon(const std::string& type)': This is the constructor declaration for the Weapon class. 
 *   It specifies that the constructor takes a single parameter of type 'const std::string&', which is a 
 *   constant reference to a string. This means that the string passed to the constructor cannot be modified 
 *   within the constructor, and it avoids making a copy of the string for efficiency.
 * - ': type(type)': This is an initializer list. It initializes the private member 'type' of the Weapon class 
 *   with the value of the parameter 'type'. The left side 'type' refers to the member variable, while the 
 *   right side 'type' refers to the constructor parameter. This syntax is used to directly initialize member 
 *   variables before the constructor body executes.
 */
Weapon::Weapon(const std::string& type) : type(type) {} /* Initialize the private attribute 'type' with the provided parameter */

/* 
 * Method to get the type of the weapon as a constant reference.
 * 
 * This function returns a constant reference to the private member 'type' of the Weapon class.
 * 
 * Syntax Explanation:
 * - 'const std::string&': This indicates that the function returns a reference to a std::string object, 
 *   and the 'const' qualifier means that the returned string cannot be modified through this reference.
 * - 'Weapon::getType() const': The 'const' at the end of the function declaration indicates that this 
 *   member function does not modify any member variables of the Weapon class.
 * 
 * Difference with C Language:
 * In C, there is no built-in string type like std::string; instead, strings are typically represented 
 * as character arrays (char arrays). The concept of returning a reference to a string is not applicable 
 * in C, as you would return a pointer to a char array instead. Additionally, C does not have the 
 * concept of member functions or classes, so this syntax is specific to C++.
 */
const std::string& Weapon::getType() const 
{
    return type; /* Return the private attribute 'type' */
}

/* Method to set the type of the weapon */
void Weapon::setType(const std::string& newType) 
{
    type = newType; /* Update the private attribute 'type' with the new value */
}