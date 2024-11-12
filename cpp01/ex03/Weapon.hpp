/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:34 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:25:29 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

// The Weapon class represents a weapon with a specific type.
// It provides methods to get and set the type of the weapon.
class Weapon 
{
private:
    std::string type; /* Private attribute to store the type of the weapon */

public:
    Weapon(const std::string& type); /* Constructor that initializes the weapon with a specific type */
    const std::string& getType() const; /* Method to get the type of the weapon as a constant reference. 
                                          It is not necessary to pass the type by value because returning a 
                                          constant reference allows the caller to access the type without 
                                          making a copy, which is more efficient. */
    void setType(const std::string& type); /* Method to set the type of the weapon */
};

#endif