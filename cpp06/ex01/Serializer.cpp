/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:32:26 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/30 21:08:27 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Private constructors and destructor - prevent instantiation
Serializer::Serializer() 
{}

Serializer::Serializer(const Serializer& other) 
{ (void)other; }

Serializer& Serializer::operator=(const Serializer& other) 
{ (void)other; return *this; }

Serializer::~Serializer() 
{}


/*
    Key points about reinterpret_cast:

    Bit-level conversion: Changes type interpretation without changing the actual bits
    Dangerous but necessary: No safety checks - you must ensure the conversion makes sense
    Perfect for pointer/integer conversion: Designed for this exact use case
    Reversible: Pointer → integer → pointer preserves the original address
    The magic is that memory addresses are just numbers, so we can store them as integers and convert back to working pointers.
    */
// SERIALIZATION: Convert Data pointer to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) 
{
   // reinterpret_cast<uintptr_t>(ptr) performs a low-level type conversion
   // - Takes the raw memory address stored in 'ptr'
   // - Reinterprets those same bits as an unsigned integer
   // - No data is changed, only how we interpret the bits
   // - Example: pointer 0x7fff5fbff6c0 becomes integer 140734799925952
   return reinterpret_cast<uintptr_t>(ptr);
}

// DESERIALIZATION: Convert uintptr_t back to Data pointer
Data* Serializer::deserialize(uintptr_t raw) 
{
   // reinterpret_cast<Data*>(raw) performs the reverse conversion
   // - Takes the unsigned integer value in 'raw'
   // - Reinterprets those same bits as a Data pointer
   // - Again, no data is changed, only the interpretation
   // - Example: integer 140734799925952 becomes pointer 0x7fff5fbff6c0
   // - The returned pointer points to the exact same memory location
   return reinterpret_cast<Data*>(raw);
}