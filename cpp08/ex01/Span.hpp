#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span 
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public: 
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        // Add a single integer to the span
        void addNumber(int number);
        
        // Template version: Add multiple numbers from a range using iterators
        // This allows adding numbers from containers like vector, list, array, etc.
        // More flexible than the single integer version - can add multiple numbers at once
        template<typename InputIterator>
        void addNumber(InputIterator first, InputIterator last)
        {
            if (static_cast<unsigned int>(std::distance(first, last)) > (_maxSize - _numbers.size()))
                throw SpanFullException();
            _numbers.insert(_numbers.end(), first, last);
        }

        int shortestSpan();
        int longestSpan();

        class SpanFullException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NoSpanException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif