#include "Span.hpp"
#include <vector>

/*Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.
This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.
Next, implement two member functions: shortestSpan() and longestSpan()
They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.
Of course, you will write your own tests, and they will be far more thorough than the
ones below. Test your Span with at least 10,000 numbers. More would be even better.
*/
#include "Span.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "\033[91mBasic Tests:\033[0m" << std::endl;
    
    // Test 1: Basic functionality
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should be 2 (11-9)
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Should be 14 (17-3)
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n\033[91mException Tests:\033[0m" << std::endl;
    
    // Test 2: SpanFullException
    try {
        Span sp = Span(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw SpanFullException
    }
    catch (std::exception& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    // Test 3: NoSpanException - empty span
    try {
        Span sp = Span(5);
        sp.shortestSpan(); // Should throw NoSpanException
    }
    catch (std::exception& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    // Test 4: NoSpanException - single element
    try {
        Span sp = Span(5);
        sp.addNumber(42);
        sp.longestSpan(); // Should throw NoSpanException
    }
    catch (std::exception& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n\033[91mRange :\033[0m" << std::endl;
    
    // Test 5: Range-based addNumber with vector
    try {
        Span sp = Span(10);
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(5);
        vec.push_back(10);
        vec.push_back(15);
        // this uses the template version of addNumber
        sp.addNumber(vec.begin(), vec.end());
        // this uses the non-template version of addNumber
        sp.addNumber(20);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should be 4 (5-1) 
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Should be 19 (20-1)
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 6: Range-based addNumber with list
    try {
        Span sp = Span(5);
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);
        
        sp.addNumber(lst.begin(), lst.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should be 100
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Should be 200
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 7: Range-based exception
    try {
        Span sp = Span(3);
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5); // 5 elements, but span can only hold 3
        
        sp.addNumber(vec.begin(), vec.end()); // Should throw SpanFullException
    }
    catch (std::exception& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n\033[91m10.000 Numbers Test:\033[0m" << std::endl;
    
    // Test 8: Large scale test with 10,000 numbers
    try {
        const unsigned int LARGE_SIZE = 10000;
        Span largeSp = Span(LARGE_SIZE);
            
        std::vector<int> largeVec;
/*         largeVec.reserve(LARGE_SIZE);
 */        
        for (unsigned int i = 0; i < LARGE_SIZE; ++i) {
            largeVec.push_back(i);
        }
        
        largeSp.addNumber(largeVec.begin(), largeVec.end());
        
        std::cout << "Large span shortest: " << largeSp.shortestSpan() << std::endl;
        std::cout << "Large span longest: " << largeSp.longestSpan() << std::endl;
        std::cout << "Successfully tested with " << LARGE_SIZE << " numbers!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error in large test: " << e.what() << std::endl;
    }
    
    std::cout << "\n\033[91mEdge Cases:\033[0m" << std::endl;
    
    // Test 9: Negative numbers
    try {
        Span sp = Span(5);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(10);
        
        std::cout << "With negatives - Shortest: " << sp.shortestSpan() << std::endl; // Should be 5
        std::cout << "With negatives - Longest: " << sp.longestSpan() << std::endl;   // Should be 20
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 10: Duplicate numbers
    try {
        Span sp = Span(4);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(10);
        
        std::cout << "With duplicates - Shortest: " << sp.shortestSpan() << std::endl; // Should be 0
        std::cout << "With duplicates - Longest: " << sp.longestSpan() << std::endl;   // Should be 5
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}