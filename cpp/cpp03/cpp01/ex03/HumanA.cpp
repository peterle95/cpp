/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:05:07 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/11 22:05:08 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const 
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}