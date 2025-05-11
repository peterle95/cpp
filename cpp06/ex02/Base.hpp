/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:02:55 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/23 15:11:54 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base 
{
    public:
        virtual ~Base();
};

// Function prototypes
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif