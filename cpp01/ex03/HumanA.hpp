/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:43 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/15 16:26:11 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * HumanA.hpp
 * 
 * This header file defines the HumanA class, which represents a human character 
 * that is always armed with a weapon. The class requires a reference to a Weapon 
 * object to be passed at construction, ensuring that a HumanA instance is always 
 * initialized with a weapon. This file works in conjunction with the Weapon class 
 * and the HumanB class to demonstrate the interaction between humans and weapons 
 * in the program.
 */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp" /* Include the Weapon class definition to use Weapon objects */
#include <string> /* Include the string library for using std::string */

class HumanA 
{
private:
    std::string name; /* Private member variable to store the name of the human */
    Weapon& weapon; /* Reference to a Weapon object, ensuring that HumanA is always armed */

public:
    HumanA(const std::string& name, Weapon& weapon); 
    /* Constructor that initializes the HumanA object with a name and a weapon reference. 
       A pointer could also work, but it would allow for the possibility of the weapon being null, 
       which could lead to undefined behavior if not handled properly. Using a pointer could 
       allow the weapon to be NULL, which would require additional checks to ensure that the 
       HumanA instance is always associated with a valid Weapon object before performing actions, 
       making the design less robust. 
       Therefore, while a pointer is a valid option, using a reference enforces the relationship 
       between HumanA and Weapon more strictly, ensuring that HumanA must always have a weapon 
       to function correctly. */
    void attack() const; /* Method to perform an attack, displaying the attack message.
                           The 'const' qualifier indicates that this method does not modify 
                           any member variables of the HumanA class, ensuring that it can be 
                           called on const instances of HumanA. This is important for 
                           maintaining const-correctness in the code, allowing for safer 
                           and more predictable behavior when using const objects. */
};

/* 
 * Explanation:
 * In HumanA, the weapon is a reference because HumanA is designed to always be armed with a weapon.
 * A reference guarantees that a valid Weapon object is provided at construction, ensuring that 
 * HumanA cannot exist without a weapon. This design enforces the relationship between HumanA 
 * and Weapon, making it clear that HumanA must always have a weapon to function correctly.
 */

#endif