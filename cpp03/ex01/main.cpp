/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:15 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/07 15:56:23 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() 
{
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    scav.attack("Another Enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();
    
    return 0;
}