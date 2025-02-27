/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:47:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/07 16:03:09 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal 
{
private:
    Brain* brain;

public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const;
};

#endif