/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:05:11 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/11 22:05:12 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA 
{
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif