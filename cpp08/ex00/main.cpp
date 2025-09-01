#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    /*
     * std::vector - Dynamic Array Container
     * - Stores elements in contiguous memory (like a resizable array)
     * - Provides random access to elements via [] operator
     * - Fast insertion/deletion at the end O(1), slow at beginning/middle O(n)
     * - Automatically manages memory allocation and deallocation
     * - Iterators can be invalidated when the vector reallocates memory
     * - Best for: Random access, frequent access to elements by index
     */
    std::cout << "\033[91mTesting Vector:\033[0m" << std::endl;
    std::vector<int> myVector;
    for (int i = 0; i < 10; ++i) {
        myVector.push_back(i * 2); // Add elements: 0, 2, 4, 6, 8, 10, 12, 14, 16, 18
    }

    try {
        std::cout << "Searching for 8 in vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(myVector, 8);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 42 in vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(myVector, 42);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    /*
     * std::list - Doubly Linked List Container
     * - Elements are stored in separate nodes, each containing data and pointers to next/previous nodes
     * - No random access - must traverse from beginning or end to reach an element
     * - Fast insertion/deletion anywhere in the list O(1) if you have an iterator
     * - No memory reallocation - each element is independently allocated
     * - Iterators remain valid unless the specific element is deleted
     * - Best for: Frequent insertions/deletions in the middle, when you don't need random access
     */
    std::cout << "\n\033[91mTesting List:\033[0m" << std::endl;
    std::list<int> myList;
    myList.push_back(10);   // Add to end
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_front(5);   // Add to beginning - efficient for list

    try {
        std::cout << "Searching for 30 in list..." << std::endl;
        std::list<int>::iterator result = easyfind(myList, 30);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 99 in list..." << std::endl;
        std::list<int>::iterator result = easyfind(myList, 99);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    /*
     * std::deque - Double-Ended Queue Container
     * - Combines benefits of vector and list: fast random access + efficient insertion at both ends
     * - Internally implemented as a collection of fixed-size arrays (chunks)
     * - Fast insertion/deletion at both front and back O(1)
     * - Random access to elements O(1), but slightly slower than vector due to indirection
     * - May invalidate iterators when elements are added/removed
     * - Best for: When you need random access AND efficient insertion/deletion at both ends
     */
    std::cout << "\n\033[91mTesting Deque:\033[0m" << std::endl;
    std::deque<int> myDeque;
    myDeque.push_back(100);   // Add to back
    myDeque.push_back(200);
    myDeque.push_front(50);   // Add to front - efficient for deque
    myDeque.push_back(300);
    // Current deque contents: [50, 100, 200, 300]

    try {
        std::cout << "Searching for 50 in deque..." << std::endl;
        std::deque<int>::iterator result = easyfind(myDeque, 50);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 150 in deque..." << std::endl;
        std::deque<int>::iterator result = easyfind(myDeque, 150);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    /*
     * Edge Cases Testing
     * - Empty containers: Testing behavior when no elements exist
     * - Single element: Testing minimal valid container size
     * These tests ensure our easyfind function handles boundary conditions properly
     */
    std::cout << "\n\033[91mTesting Edge Cases:\033[0m" << std::endl;
    
    // Test with empty container
    std::vector<int> emptyVector;
    try {
        std::cout << "Searching for 1 in empty vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(emptyVector, 1);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test with single element
    std::list<int> singleElementList;
    singleElementList.push_back(42);
    try {
        std::cout << "Searching for 42 in single-element list..." << std::endl;
        std::list<int>::iterator result = easyfind(singleElementList, 42);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 24 in single-element list..." << std::endl;
        std::list<int>::iterator result = easyfind(singleElementList, 24);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}