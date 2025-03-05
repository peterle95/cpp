/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:47:13 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/05 16:06:31 by pmolzer          ###   ########.fr       */
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
* Protected access enables direct member access in derived classes while
* maintaining encapsulation from external code. This design choice:
* 1. Allows derived classes (like ScavTrap) to modify attributes directly
*    without getters/setters
* 2. Maintains proper encapsulation hierarchy - only immediate descendants
*    get access
* 3. Reduces boilerplate code while keeping implementation details hidden
*    from unrelated classes
* 
* Tradeoff: Weakens strict encapsulation but is appropriate for tightly
* coupled inheritance hierarchies where derived classes need intimate
* knowledge of base implementation
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
    // virtual ~ClapTrap(); // Destructor for virtual member functions

    void attack(const std::string& target);  /* Method for the ClapTrap to attack a target */
    // virtual void attack(const std::string& target); // 
    void takeDamage(unsigned int amount);  /* Method for the ClapTrap to take damage */
    void beRepaired(unsigned int amount);  /* Method for the ClapTrap to repair itself */

};

#endif