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

        void addNumber(int number);
        
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