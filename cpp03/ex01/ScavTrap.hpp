/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:18:59 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/05 16:06:37 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap // This establishes public inheritance from ClapTrap
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();

    void attack(const std::string& target);
    // virtual void attack(const std::string& target);
    void guardGate();
};

#endif