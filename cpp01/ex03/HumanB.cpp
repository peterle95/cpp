/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:05:16 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/04 15:32:01 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& newWeapon) 
{
    weapon = &newWeapon;
}

void HumanB::attack() const 
{
    if (weapon) 
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } 
    else 
    {
        std::cout << name << " has no weapon to attack with" << std::endl;
    }
}