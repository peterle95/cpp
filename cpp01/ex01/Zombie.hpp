/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:04:16 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/06 15:27:37 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie 
{
private:
    std::string name;

public:
    Zombie();
    ~Zombie();

    void announce() const;
    void setName(const std::string& name);
};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP