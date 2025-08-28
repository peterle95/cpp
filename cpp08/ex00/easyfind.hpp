#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <exception>

class NotFoundException : public std::exception 
{
    public:
        virtual const char* what() const throw() 
        {
            return "Element not found in container";
        }
};

// Template function declaration - T is a placeholder for any container type (vector, list, etc.)
template <typename T>
// Function returns an iterator of type T::iterator (e.g., std::vector<int>::iterator)
// Takes a reference to container T and an integer value to search for
typename T::iterator easyfind(T& container, int value) 
{
    // Declare an iterator variable 'it' of the container's iterator type
    // std::find searches from container.begin() to container.end() for 'value'
    // Returns an iterator pointing to the found element, or container.end() if not found
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    // Check if the search failed by comparing with end() iterator
    // If it == container.end(), the element was not found
    if (it == container.end()) {
        // Throw custom exception defined in the header file
        throw NotFoundException();
    }
    // Return the iterator pointing to the found element
    return it;
}

#endif