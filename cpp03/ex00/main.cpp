/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:39 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/16 16:45:37 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() 
{
    ClapTrap clap("CL4P-TP");
    
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    return 0;
}