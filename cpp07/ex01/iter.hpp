#ifndef ITER_HPP  // Header guard: prevents multiple inclusions of this header file
#define ITER_HPP  // Define the macro ITER_HPP to mark this file as included

#include <cstddef>  // Include C standard definitions library for std::size_t type
                    // std::size_t is an unsigned integer type used for array sizes/indices

// Function template definition for iter function
// Template parameters:
// - T: type of array elements (int, float, string, etc.)
// - F: type of function/functor to apply to each element
// This allows the function to work with any array type and any callable object
template<typename T, typename F>
void iter(T* array, std::size_t length, F func) {
    // Function parameters:
    // - T* array: pointer to the first element of the array
    //   T* means "pointer to type T" - works with any type
    // - std::size_t length: number of elements in the array
    //   std::size_t is unsigned, so it can't be negative (safer than int)
    // - F func: function/functor to call on each array element
    //   F is deduced by compiler based on what's passed in
    
    // Safety check: verify array pointer is not null
    // Dereferencing a null pointer would cause segmentation fault
    if (!array) {
        return;  // Early return if array is null - prevents crash
                 // Function exits here without doing anything
    }
    
    // Main loop: iterate through each element of the array
    // std::size_t i: loop counter variable of same type as length
    // i < length: continue while index is less than array size
    // ++i: pre-increment (more efficient than post-increment)
    for (std::size_t i = 0; i < length; ++i) {
        // Call the function on the current array element
        // array[i]: access element at index i using subscript operator
        // This is equivalent to *(array + i) - pointer arithmetic
        // func(array[i]): call the function with current element as argument
        // The function can modify the element (if it takes non-const reference)
        // or just read it (if it takes const reference or value)
        func(array[i]);
    }
    // Function ends here - no return value needed (void function)
}

#endif  // End of header guard - matches the #ifndef at the top
        // This ensures the header content is only included once per compilation unit