// Header guard to prevent multiple inclusions of this file in a single compilation unit.
#ifndef ARRAY_HPP
// Defines the ARRAY_HPP macro, marking this header as included.
#define ARRAY_HPP

// Include the standard exception header for std::exception, the base class for our custom exception.
#include <exception>
// Include the standard except header for standard exception classes.
#include <stdexcept>
// Include the C standard definition header for std::size_t, a type for representing sizes and counts.
#include <cstddef>

// Template declaration, making the Array class generic so it can hold elements of any type T.
template<typename T>
// Class definition for our custom dynamic array.
class Array {
// Private members are encapsulated and not accessible from outside the class.
private:
    // A pointer to a dynamically allocated block of memory of type T, where the array elements will be stored.
    T* _elements;
    // An unsigned integer that holds the number of elements in the array.
    std::size_t _size;

// Public members define the interface of the class.
public:
    // Default constructor: creates an empty array.
    Array();
    // Constructor: creates an array of a specific size 'n'.
    Array(unsigned int n);
    // Copy constructor: creates a deep copy of another Array object.
    Array(const Array& other);
    // Assignment operator: assigns the content of another Array object to this one (deep copy).
    Array& operator=(const Array& other);
    // Destructor: cleans up the dynamically allocated memory when the object is destroyed.
    ~Array();
    
    // Overloads the subscript operator [] for non-const arrays, allowing element access and modification.
    T& operator[](int index);
    // Overloads the subscript operator [] for const arrays, allowing read-only element access.
    const T& operator[](int index) const;
    
    // A public method to get the current size (number of elements) of the array.
    std::size_t size() const;
    
    // Defines a custom exception class that inherits from the standard std::exception.
    class OutOfBoundsException : public std::exception {
    // Public interface for the exception class.
    public:
        // Overrides the what() method from std::exception to return a custom error message.
        // 'throw()' is an exception specification indicating this function does not throw any exceptions.
        virtual const char* what() const throw() {
            // The C-style string message that will be returned when the exception is caught.
            return "Array index out of bounds";
        }
    };
};

// --- Implementation of the Array class methods ---

// Default constructor implementation.
template<typename T>
Array<T>::Array() : _elements(NULL), _size(0) {} // Initializes the pointer to NULL and size to 0.

// Sized constructor implementation.
template<typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n) { // Initializes size with n.
    // Checks if the requested size is greater than zero to avoid allocating a zero-sized array.
    if (n > 0) {
        // Dynamically allocates an array of 'n' elements of type T and stores the address in _elements.
        _elements = new T[n];
    }
}

// Copy constructor implementation.
template<typename T>
Array<T>::Array(const Array& other) : _elements(NULL), _size(other._size) { // Copies the size from the other array.
    // Proceeds only if the array to be copied has elements.
    if (_size > 0) {
        // Allocates new memory for this object's elements.
        _elements = new T[_size];
        // Loops through each element of the 'other' array.
        for (std::size_t i = 0; i < _size; ++i) {
            // Copies each element from the 'other' array to this one (deep copy).
            _elements[i] = other._elements[i];
        }
    }
}

// Assignment operator implementation.
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    // Protects against self-assignment (e.g., `myArray = myArray;`).
    if (this != &other) {
        // Deletes the old memory block to prevent memory leaks.
        delete[] _elements;
        // Copies the size from the 'other' array.
        _size = other._size;
        // Checks if the new size is positive.
        if (_size > 0) {
            // Allocates a new memory block for the elements.
            _elements = new T[_size];
            // Loops through each element of the 'other' array.
            for (std::size_t i = 0; i < _size; ++i) {
                // Copies each element, completing the deep copy.
                _elements[i] = other._elements[i];
            }
        } else {
            // If the new size is 0, set the pointer to NULL.
            _elements = NULL;
        }
    }
    // Returns a reference to the current object to allow for chaining assignments (e.g., a = b = c).
    return *this;
}

// Destructor implementation.
template<typename T>
Array<T>::~Array() {
    // Deallocates the memory that was dynamically allocated for the array elements.
    // Using `delete[]` is crucial for arrays to ensure all elements are properly destroyed.
    delete[] _elements;
}

// Non-const subscript operator implementation.
template<typename T>
T& Array<T>::operator[](int index) {
    // Checks if the index is negative or greater than or equal to the size.
    if (index < 0 || static_cast<std::size_t>(index) >= _size) {
        // If the index is invalid, it throws the custom exception.
        throw OutOfBoundsException();
    }
    // If the index is valid, it returns a reference to the element, allowing it to be modified.
    return _elements[index];
}

// Const subscript operator implementation.
template<typename T>
const T& Array<T>::operator[](int index) const {
    // Performs the same bounds check as the non-const version.
    if (index < 0 || static_cast<std::size_t>(index) >= _size) {
        // Throws the exception if the index is out of bounds.
        throw OutOfBoundsException();
    }
    // Returns a const reference to the element, allowing it to be read but not modified.
    return _elements[index];
}

// size() method implementation.
template<typename T>
std::size_t Array<T>::size() const {
    // Returns the private _size member.
    return _size;
}

#endif

/*
 * --- Code Summary and Exercise Context ---
 *
 * This file defines a class template `Array<T>` which is a custom implementation of a dynamic array.
 * The goal of this exercise is to demonstrate a fundamental understanding of several key C++ concepts:
 *
 * 1.  **Class Templates:** By using `template<typename T>`, the `Array` class is made generic. It can be
 *     instantiated with any data type (e.g., `Array<int>`, `Array<std::string>`, `Array<float>`), making
 *     it a highly reusable piece of code.
 *
 * 2.  **Dynamic Memory Management:** The class manually manages memory on the heap using `new[]` to allocate
 *     and `delete[]` to deallocate memory for the array elements. This is a core skill in C++ and requires
 *     careful handling to prevent memory leaks.
 *
 * 3.  **Orthodox Canonical Form (OCF):** The class correctly implements the essential member functions required
 *     for a class that manages dynamic memory:
 *     -   Default Constructor
 *     -   Copy Constructor (for deep copies)
 *     -   Assignment Operator (for deep copies)
 *     -   Destructor
 *     This ensures that the array behaves predictably when copied, assigned, or destroyed.
 *
 * 4.  **Operator Overloading:** The subscript operator `operator[]` is overloaded to provide intuitive, C-style
 *     array access (e.g., `myArray[i]`). Two versions are provided: a non-const version for modifying
 *     elements and a const version for safe, read-only access.
 *
 * 5.  **Exception Handling:** A custom exception class, `OutOfBoundsException`, is implemented to handle
 *     runtime errors gracefully. The `operator[]` checks if an index is valid and throws this exception
 *     if it's not, preventing crashes from memory access violations and allowing the user of the class
 *     to handle the error.
 *
 * In the context of the C++ Modules, this exercise is a capstone for the basic concepts, bringing together
 * templates, memory management, and class design into a single, practical data structure.
 */
