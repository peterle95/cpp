#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    // Test with std::vector
    std::vector<int> myVector;
    for (int i = 0; i < 10; ++i) {
        myVector.push_back(i * 2);
    }

    try {
        std::cout << "Searching for 8 in vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(myVector, 8);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nSearching for 42 in vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(myVector, 42);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test with std::list
    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    try {
        std::cout << "\nSearching for 30 in list..." << std::endl;
        std::list<int>::iterator result = easyfind(myList, 30);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nSearching for 99 in list..." << std::endl;
        std::list<int>::iterator result = easyfind(myList, 99);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}