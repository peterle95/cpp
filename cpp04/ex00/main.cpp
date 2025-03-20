/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:36:56 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/20 13:30:07 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

/*TASK OF THE PROGRAM*/


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "****Wrong animal tests:****" << std::endl;
    std::cout << wrong->getType() << " : ";
    wrong->makeSound();
    
    std::cout << wrongCat->getType() << " : ";
    wrongCat->makeSound(); // Calls WrongAnimal's version ❌

    delete meta;
    delete j;
    delete i;
    delete wrong;
    delete wrongCat;        // Properly calls ~WrongCat then ~WrongAnimal ✅

    return 0;
}