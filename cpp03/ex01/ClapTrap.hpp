/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:56 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/04 15:22:09 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap 
{
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    std::string getName() const { return name; }
    unsigned int getHitPoints() const { return hitPoints; }
    unsigned int getEnergyPoints() const { return energyPoints; }
    unsigned int getAttackDamage() const { return attackDamage; }
    void setHitPoints(unsigned int value) { hitPoints = value; }
    void setEnergyPoints(unsigned int value) { energyPoints = value; }
    void setAttackDamage(unsigned int value) { attackDamage = value; }

    ClapTrap(std::string name);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif