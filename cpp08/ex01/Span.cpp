#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <numeric>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N)
{
    _numbers.reserve(N);
}

Span::Span(const Span& other) 
{
    *this = other;
}

Span& Span::operator=(const Span& other) 
{
    if (this != &other) 
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) 
{
    if (_numbers.size() >= _maxSize) 
    {
        throw Span::SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() 
{
    if (_numbers.size() <= 1) 
    {
        throw Span::NoSpanException();
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) 
    {
        if (sorted[i] - sorted[i-1] < minSpan) 
            minSpan = sorted[i] - sorted[i-1];
    }
    return minSpan;
}

int Span::longestSpan() 
{
    if (_numbers.size() <= 1) 
    {
        throw Span::NoSpanException();
    }
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

const char* Span::SpanFullException::what() const throw() 
{
    return "Span is full";
}

const char* Span::NoSpanException::what() const throw() 
{
    return "Not enough numbers to find a span";
}