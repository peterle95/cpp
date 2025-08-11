#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>
#include <cstddef>

template<typename T>
class Array {
private:
    T* _elements;
    std::size_t _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    
    T& operator[](int index);
    const T& operator[](int index) const;
    
    std::size_t size() const;
    
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Array index out of bounds";
        }
    };
};

// Implementation
template<typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n) {
    if (n > 0) {
        _elements = new T[n];
    }
}

template<typename T>
Array<T>::Array(const Array& other) : _elements(NULL), _size(other._size) {
    if (_size > 0) {
        _elements = new T[_size];
        for (std::size_t i = 0; i < _size; ++i) {
            _elements[i] = other._elements[i];
        }
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _elements;
        _size = other._size;
        if (_size > 0) {
            _elements = new T[_size];
            for (std::size_t i = 0; i < _size; ++i) {
                _elements[i] = other._elements[i];
            }
        } else {
            _elements = NULL;
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] _elements;
}

template<typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || static_cast<std::size_t>(index) >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || static_cast<std::size_t>(index) >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

template<typename T>
std::size_t Array<T>::size() const {
    return _size;
}

#endif