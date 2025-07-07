/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:01:09 by pmolzer           #+#    #+#             */
/*   Updated: 2025/07/07 14:52:59 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main() 
{
    for (int i = 0; i < 5; i++) 
    {
        std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;
        
        Base* instance = generate();
        
        // Identify using pointer
        identify(instance);
        
        // Identify using reference
        identify(*instance);
        
        delete instance;
    }
    
    return 0;
}