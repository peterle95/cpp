#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <numeric>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);
}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw Span::SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() {
    // Check if we have enough numbers to calculate a span
    // We need at least 2 numbers to find the difference between them
    if (_numbers.size() <= 1) {
        throw Span::NoSpanException();
    }
    
    // Create a sorted copy of the numbers vector
    // This allows us to easily find consecutive differences
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    // Initialize minSpan with the difference between the first two elements
    // This is our candidate for the shortest span
    // We start with this value because:
    // 1. We need an initial baseline value to compare against
    // 2. The first two elements (indices 0 and 1) represent the first 
    //    potential span
    // 3. In the for loop below, we start from index 2, so we must 
    //    consider the span between indices 0 and 1 before entering the loop
    // 4. This gives us a starting point for our minimum span search
    int minSpan = sorted[1] - sorted[0];
    
    // Iterate through the remaining elements to find the smallest difference
    // We start from index 2 since we already compared indices 0 and 1
    for (size_t i = 2; i < sorted.size(); ++i) 
    {
        // Calculate the difference between current and previous element
        // If this difference is smaller than our current minSpan, update it
        if (sorted[i] - sorted[i-1] < minSpan) 
            minSpan = sorted[i] - sorted[i-1];
    }
    
    // Return the smallest span found
    return minSpan;
}

int Span::longestSpan() {
    // Check if we have enough numbers to calculate a span
    // We need at least 2 numbers to find the difference between them
    if (_numbers.size() <= 1) {
        throw Span::NoSpanException();
    }
    
    // Find the minimum and maximum values in the numbers vector
    // The longest span will always be between these two extreme values
    // Note: std::min_element and std::max_element return iterators 
    // (pointer-like objects) pointing to the minimum and maximum elements, 
    // not the values themselves
    // We use the dereference operator (*) to get the actual values
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    
    // Return the difference between max and min
    // This gives us the longest possible span in the collection
    return max - min;
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is full";
}

const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers to find a span";
}