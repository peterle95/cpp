/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:43 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/10 11:52:25 by pmolzer          ###   ########.fr       */
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
    HumanA(const std::string& name, Weapon& weapon); /* Constructor that initializes the HumanA object with a name and a weapon reference */
    void attack() const; /* Method to perform an attack, displaying the attack message */
};

#endif