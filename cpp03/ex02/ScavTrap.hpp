/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:18:59 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/12 14:28:59 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};

#endif