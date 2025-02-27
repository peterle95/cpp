/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:19:57 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:20:01 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain 
{
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();
};

#endif

