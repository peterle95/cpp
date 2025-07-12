#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// Function template iter that applies a function to each element of an array
template<typename T, typename F>
void iter(T* array, std::size_t length, F func) {
    // Check if array is null to avoid segmentation fault
    if (!array) {
        return;
    }
    
    // Iterate through each element of the array
    for (std::size_t i = 0; i < length; ++i) {
        // Call the function on each element
        // The function can take const or non-const reference
        func(array[i]);
    }
}

#endif  