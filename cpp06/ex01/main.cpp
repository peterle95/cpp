/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:30:09 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/30 21:09:39 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

/*TASK:
Implement a class Serializer, which will not be initializable by the user in any way,
with the following static methods:
uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer type uintptr_t.
Data* deserialize(uintptr_t raw);
It takes an unsigned integer parameter and converts it to a pointer to Data.
Write a program to test that your class works as expected.
You must create a non-empty (meaning it has data members) Data structure.
Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer.
Do not forget to turn in the files of your Data structure.*/


/*Purpose and Core Concepts
This exercise teaches pointer serialization - converting memory addresses to integers and back. The core concepts are:

Serialization: Converting a pointer (memory address) to uintptr_t (unsigned integer type)
Deserialization: Converting the integer back to a pointer
Type casting: Using reinterpret_cast to change data interpretation without changing the underlying bits
Static utility class: A class that only provides static methods and cannot be instantiated

The exercise demonstrates that pointers are just memory addresses that can be stored as integers, 
then converted back to working pointers.

Why use a struct? The exercise requires a "non-empty" data structure to prove the serialization works correctly. 
A struct with multiple data members shows that after serialize/deserialize, you can still access 
the original object's data through the restored pointer.*/

int main() 
{
    // Create a Data object with sample values to test serialization
    Data original;
    original.id = 42;
    original.name = "Sample Data";
    original.value = 3.14159;
    
    // Display original object's memory address and contents
    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << &original << std::endl;
    std::cout << "ID: " << original.id << std::endl;
    std::cout << "Name: " << original.name << std::endl;
    std::cout << "Value: " << original.value << std::endl;
    std::cout << std::endl;
    
    // SERIALIZATION: Convert pointer to integer
    // This stores the memory address as an unsigned integer
    /*
    `uintptr_t` is an unsigned integer type that's guaranteed to be large enough to hold a pointer value.

    **Key properties:**
    - **Size**: Always matches your system's pointer size (32-bit on 32-bit systems, 64-bit on 64-bit systems)
    - **Unsigned**: Can't be negative, uses all bits for the address value
    - **Portable**: Works across different architectures and compilers
    - **Reversible**: You can convert pointer → `uintptr_t` → pointer without data loss
    
    **Why use it for serialization?**
    - Regular `int` might be too small (32-bit int can't hold a 64-bit pointer)
    - `uintptr_t` is specifically designed for this pointer-to-integer conversion
    - It's part of the C standard (`<stdint.h>`) so it's guaranteed to exist
    
    **Example sizes:**
    - 32-bit system: `uintptr_t` = 32 bits (can hold 4GB address space)
    - 64-bit system: `uintptr_t` = 64 bits (can hold massive address space)
    
    Think of it as the "perfect container" for storing memory addresses as numbers.*/
    uintptr_t serialized = Serializer::serialize(&original);
    /*Breaking down uintptr_t serialized = Serializer::serialize(&original);:

    uintptr_t serialized - Declares a variable named serialized of type uintptr_t
    
    &original - Address-of operator gets the memory address of the original object
    
    Serializer::serialize() - Static method call using scope resolution operator ::
    
    No object instance needed since it's static
    Takes the address as parameter
    =  - Assignment operator stores the returned value in serialized
    
    Flow:
    
    &original gets the memory address (e.g., 0x7fff5fbff6c0)
    Serializer::serialize() converts that address to uintptr_t
    Result gets stored in serialized variable
    The :: syntax is used because serialize is a static method - you call it on the class itself, not on an instance of the class.
    */
    std::cout << "Serialized to uintptr_t: " << serialized << std::endl;
    std::cout << std::endl;
    
    // DESERIALIZATION: Convert integer back to pointer
    // This restores the memory address as a usable Data pointer
    Data* deserialized = Serializer::deserialize(serialized);
    
    // Access the original object through the deserialized pointer
    // This proves the serialization preserved the memory address correctly
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    std::cout << std::endl;
    
    // VERIFICATION: Confirm both pointers point to the same memory location
    // This is the key test - if serialization worked, addresses should match
    std::cout << "Address comparison:" << std::endl;
    std::cout << "Original: " << &original << std::endl;
    std::cout << "Deserialized: " << deserialized << std::endl;
    std::cout << "Are equal: " << ((&original == deserialized) ? "Yes" : "No") << std::endl;
    
    return 0;
}

