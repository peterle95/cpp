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
    MutantStack &operator=(const MutantStack &other) {
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

// Iterator typedefs (using the underlying container's iterators)
    /* The purpose of the typedefs is to expose the iterator types from the underlying container and 
    give them simple, standard names within the scope of MutantStack. std::stack
  itself doesn't have an iterator type. We need to dig into its underlying container to find them.
   * typename std::stack<T>::container_type: This part accesses the type of the underlying container (e.g., std::deque<T>).
   * ::iterator: This then accesses the public iterator type defined within that container.
  By creating these typedefs, we allow a user of MutantStack to write standard-looking code 
  like MutantStack<int>::iterator it; without needing to know what the underlying
  container is.*/
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Functions to access iterators
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