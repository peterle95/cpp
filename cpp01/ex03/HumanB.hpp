/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:54 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:23:58 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * HumanB.hpp
 * 
 * This header file defines the HumanB class, which represents a human character 
 * that can wield a weapon. Unlike HumanA, HumanB does not require a weapon to be 
 * provided at construction time, allowing for more flexibility in weapon assignment. 
 * The class includes methods for setting a weapon and attacking, which outputs 
 * the attack message based on the weapon type.
 */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp" /* Include the Weapon class definition to use Weapon objects */
#include <string> /* Include the string library for using std::string */

class HumanB 
{
private:
    std::string name; /* Private member variable to store the name of the human */
    Weapon* weapon; /* Pointer to a Weapon object, allowing for dynamic weapon assignment */

public:
    HumanB(const std::string& name); /* Constructor that initializes the HumanB object with a name */
    void setWeapon(Weapon& weapon); /* Method to set the weapon for this HumanB object */
    void attack() const; /* Method to perform an attack, displaying the attack message */
};

#endif