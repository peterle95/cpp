/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:30:09 by pmolzer           #+#    #+#             */
/*   Updated: 2025/07/13 12:55:03 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() 
{
    Data original;
    original.id = 42;
    original.name = "Sample Data";
    original.value = 3.14159;
    
    // Print original values
    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << &original << std::endl;
    std::cout << "ID: " << original.id << std::endl;
    std::cout << "Name: " << original.name << std::endl;
    std::cout << "Value: " << original.value << std::endl;
    std::cout << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized to uintptr_t: " << serialized << std::endl;
    std::cout << std::endl;
    
    // Deserialize back to a pointer
    Data* deserialized = Serializer::deserialize(serialized);
    
    // Print deserialized values
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    std::cout << std::endl;
    
    // Verify that the addresses match
    std::cout << "Address comparison:" << std::endl;
    std::cout << "Original: " << &original << std::endl;
    std::cout << "Deserialized: " << deserialized << std::endl;
    std::cout << "Are equal: " << ((&original == deserialized) ? "Yes" : "No") << std::endl;
    
    return 0;
}

