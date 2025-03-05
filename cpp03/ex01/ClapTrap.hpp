/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:47:13 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/05 11:24:56 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:56 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/16 16:41:42 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP  /* Check if CLAPTRAP_HPP is not defined */
#define CLAPTRAP_HPP  /* Define CLAPTRAP_HPP to prevent multiple inclusions */

#include <string>  /* Include the string library for using std::string */

/* 
 * ClapTrap class definition.
 * This class simulates a ClapTrap character with attributes for name, hit points,
 * energy points, and attack damage. It provides methods for attacking, taking damage,
 * repairing, and accessing/modifying its attributes.
 */
class ClapTrap 
{
protected:  /* Access specifier for private members */
    std::string name;  /* The name of the ClapTrap instance */
    unsigned int hitPoints;  /* The health of the ClapTrap */
    unsigned int energyPoints;  /* The energy available for actions */
    unsigned int attackDamage;  /* The damage dealt by the ClapTrap */

public:  /* Access specifier for public members */
    ClapTrap(std::string name);  /* Constructor that initializes the ClapTrap with a name */
    ~ClapTrap();  /* Destructor that cleans up when a ClapTrap instance is destroyed */

    void attack(const std::string& target);  /* Method for the ClapTrap to attack a target */
    void takeDamage(unsigned int amount);  /* Method for the ClapTrap to take damage */
    void beRepaired(unsigned int amount);  /* Method for the ClapTrap to repair itself */

};

#endif