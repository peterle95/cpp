/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:06:26 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/11 22:06:27 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug() 
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() 
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() 
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) 
{
    void (Harl::*complaints[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) 
    {
        if (level == levels[i]) 
        {
            (this->*complaints[i])();
            return;
        }
    }
    std::cout << "Invalid complaint level" << std::endl;
}