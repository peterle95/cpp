#ifndef ARRAY_HPP
#define ARRAY_HPP

// Include guards prevent multiple inclusions of this header file
// If ARRAY_HPP is already defined, the preprocessor skips this entire file

#include <exception>    // For std::exception base class
#include <stdexcept>    // For standard exception classes (though we define our own)
#include <cstddef>      // For std::size_t type definition

// Template class declaration - T is a placeholder for any type
// This allows creating Array<int>, Array<string>, Array<MyClass>, etc.
template<typename T>
class Array {
private:
    // Private member variables - encapsulation principle
    T* _elements;           // Pointer to dynamically allocated array of type T
                           // Using new[] to allocate, delete[] to deallocate
    std::size_t _size;     // Number of elements in the array
                           // size_t is unsigned integer type, perfect for sizes/indices

public:
    // Public interface - these methods can be called by users of the class
    
    // Default constructor - creates empty array
    Array();
    
    // Parametric constructor - creates array with n elements
    Array(unsigned int n);
    
    // Copy constructor - creates deep copy of another Array
    // const reference prevents modification of source, & avoids copying
    Array(const Array& other);
    
    // Assignment operator - assigns one Array to another with deep copy
    // Returns reference to *this for chaining assignments (a = b = c)
    Array& operator=(const Array& other);
    
    // Destructor - cleans up dynamically allocated memory
    ~Array();
    
    // Subscript operators for element access
    // Non-const version - allows modification of elements
    // Updated to handle int indices (including negative) for bounds checking
    T& operator[](int index);
    
    // Const version - for read-only access on const Array objects
    // Must be separate overload because const objects can only call const methods
    const T& operator[](int index) const;
    
    // Size accessor - returns number of elements
    // const method because it doesn't modify the object
    std::size_t size() const;
    
    // Nested exception class for out-of-bounds access
    // Inherits from std::exception to follow standard exception hierarchy
    class OutOfBoundsException : public std::exception {
    public:
        // Override what() method to provide error message
        // throw() specification indicates this method won't throw exceptions
        virtual const char* what() const throw() {
            return "Array index out of bounds";
        }
    };
};

// TEMPLATE IMPLEMENTATION
// Template implementations must be in header file because compiler needs
// to see the full definition when instantiating templates

// Default constructor implementation
template<typename T>
Array<T>::Array() : _elements(NULL), _size(0) {
    // Member initializer list - more efficient than assignment in constructor body
    // _elements = NULL because we have no memory allocated yet
    // _size = 0 because empty array has no elements
}

// Parametric constructor implementation
template<typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n) {
    // Initialize _size to n first
    if (n > 0) {
        // Only allocate memory if size is greater than 0
        // new T[n] allocates memory for n objects of type T
        // Each element is default-constructed (0 for int, empty string for string, etc.)
        _elements = new T[n];
    }
    // If n == 0, _elements remains NULL (valid for empty array)
}

// Copy constructor implementation
template<typename T>
Array<T>::Array(const Array& other) : _elements(NULL), _size(other._size) {
    // Initialize _size to match source array
    if (_size > 0) {
        // Allocate new memory for this array (deep copy, not sharing pointers)
        _elements = new T[_size];
        
        // Copy each element individually
        // This ensures proper copying even for complex types
        for (std::size_t i = 0; i < _size; ++i) {
            _elements[i] = other._elements[i];  // Uses T's assignment operator
        }
    }
    // If source array is empty, _elements remains NULL
}

// Assignment operator implementation
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    // Self-assignment check - prevents issues when doing array = array
    if (this != &other) {
        // Clean up existing memory first
        delete[] _elements;  // Safe to call on NULL pointer
        
        // Copy size from source
        _size = other._size;
        
        if (_size > 0) {
            // Allocate new memory for deep copy
            _elements = new T[_size];
            
            // Copy all elements from source to this array
            for (std::size_t i = 0; i < _size; ++i) {
                _elements[i] = other._elements[i];
            }
        } else {
            // Source array is empty, so this array becomes empty too
            _elements = NULL;
        }
    }
    // Return reference to this object for assignment chaining
    return *this;
}

// Destructor implementation
template<typename T>
Array<T>::~Array() {
    // Clean up dynamically allocated memory
    // delete[] is safe to call on NULL pointer
    // Must use delete[] (not delete) because we used new[]
    delete[] _elements;
}

// Non-const subscript operator implementation
template<typename T>
T& Array<T>::operator[](int index) {
    // Bounds checking - critical for memory safety
    // Check for negative index (int can be negative)
    // Check for index >= size (cast to size_t for comparison)
    if (index < 0 || static_cast<std::size_t>(index) >= _size) {
        // Throw our custom exception for out-of-bounds access
        throw OutOfBoundsException();
    }
    // Return reference to element at index
    // Reference allows modification: array[0] = 42
    return _elements[index];
}

// Const subscript operator implementation
template<typename T>
const T& Array<T>::operator[](int index) const {
    // Same bounds checking as non-const version
    if (index < 0 || static_cast<std::size_t>(index) >= _size) {
        throw OutOfBoundsException();
    }
    // Return const reference - prevents modification
    // This version is called on const Array objects
    return _elements[index];
}

// Size accessor implementation
template<typename T>
std::size_t Array<T>::size() const {
    // Simple getter method - returns current size
    // const method because it doesn't modify the object
    return _size;
}

#endif  // End of include guard

/*
KEY DESIGN DECISIONS EXPLAINED:

1. TEMPLATE IN HEADER:
   - Template implementations must be in header files
   - Compiler needs full definition when instantiating templates
   - Each instantiation (Array<int>, Array<string>) creates separate compiled code

2. MEMORY MANAGEMENT:
   - Uses new[]/delete[] for dynamic allocation as required
   - NULL pointer for empty arrays (size 0)
   - Deep copying in copy constructor and assignment operator
   - RAII: constructor allocates, destructor deallocates

3. EXCEPTION SAFETY:
   - Custom exception class for bounds checking
   - delete[] is safe to call on NULL pointers
   - Self-assignment protection in operator=

4. CONST CORRECTNESS:
   - Separate const/non-const versions of operator[]
   - const methods for operations that don't modify state
   - const references in parameters to avoid unnecessary copying

5. TYPE SAFETY:
   - int parameter for operator[] allows negative checking
   - size_t for internal size storage (unsigned, appropriate for sizes)
   - static_cast for safe type conversions

6. PERFORMANCE:
   - Member initializer lists for efficient initialization
   - Reference returns from operator[] avoid copying
   - Inline implementations (header-only) for potential optimization

This implementation follows the Rule of Three:
- Custom destructor (manages dynamic memory)
- Custom copy constructor (deep copy)
- Custom assignment operator (deep copy)
*/