#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Orthodox Canonical Form
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    // Iterator typedefs - Exposing the underlying container's iterator types
    //
    // std::stack itself doesn't provide iterator types, but we can access them
    // through its underlying container (typically std::deque<T>).
    //
    // Each typedef follows this pattern:
    // 1. typename std::stack<T>::container_type - Access the underlying container type
    // 2. ::iterator/const_iterator/etc - Access the specific iterator type from that container
    // 3. typedef - Create an alias with a simple name in MutantStack's scope
    //
    // This allows users to write: MutantStack<int>::iterator it;
    // Instead of: std::deque<int>::iterator it;
    //
    // The 'typename' keyword is required because we're accessing a type that depends
    // on a template parameter T. Without it, the compiler wouldn't know that
    // std::stack<T>::container_type::iterator refers to a type vs a value.
    // Standard iterator - allows modification of elements during traversal
    typedef typename std::stack<T>::container_type::iterator iterator;
    // Const iterator - read-only access to elements during traversal
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    // Reverse iterator - allows traversal from end to beginning (can modify elements)
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    // Const reverse iterator - read-only traversal from end to beginning
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Iterator access functions
    // Note: We use 'this->c' to access the underlying container
    // 'c' is a protected member of std::stack that holds the actual container
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};


#endif