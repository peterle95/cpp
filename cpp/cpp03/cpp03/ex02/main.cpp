/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:26:30 by pmolzer           #+#    #+#             */
/*   Updated: 2025/02/25 14:31:30 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

/*TASK OF THE PROGRAM*/


int main() 
{
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    FragTrap frag("FR4G-TP");
    
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    scav.attack("Another Enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();
    
    frag.attack("Big Enemy");
    frag.takeDamage(30);
    frag.beRepaired(25);
    frag.highFivesGuys();
    // Again, add more tests to your program.
    return 0;
}