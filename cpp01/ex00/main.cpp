/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:15:36 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/05 16:35:20 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() 
{
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    
    randomChump("Stacky");
    
    delete heapZombie;
    return 0;
}