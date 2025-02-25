/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:39 by pmolzer           #+#    #+#             */
/*   Updated: 2025/02/25 14:40:42 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() 
{
    ClapTrap clap("CL4P-TP");
    // ClapTrap clap2("CL4P-TP2"); 
    
    clap.attack("Enemy");
    clap.takeDamage(5);
    /* clap.takeDamage(6);
    clap.restoreEnergy(10); */
    clap.beRepaired(3);

    // clap2.attack("Another Enemy");
    // clap.attack("Another Enemy");
    
    // Implement and turn in your own tests to ensure your code works as expected.
    return 0;
}