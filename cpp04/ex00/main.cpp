/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:36:56 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/20 13:38:04 by pmolzer          ###   ########.fr       */
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
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound(); // will output the cat sound!
    dog->makeSound();
    animal->makeSound();

    std::cout << "****Wrong animal tests:****" << std::endl;
    std::cout << wrong->getType() << " : ";
    wrong->makeSound();
    
    std::cout << wrongCat->getType() << " : ";
    wrongCat->makeSound(); // Calls WrongAnimal's version ❌

    delete animal;
    delete dog;
    delete cat;
    delete wrong;
    delete wrongCat;        // Properly calls ~WrongCat then ~WrongAnimal ✅

    return 0;
}