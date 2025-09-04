#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T* array, std::size_t length, F func) 
{
    if (!array) 
        return;
    
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif  