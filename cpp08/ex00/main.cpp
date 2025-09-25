#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>

/*
A first easy exercise is the way to start off on the right foot.
Write a function template easyfind that accepts a type T. It takes two parameters:
the first one is of type T, and the second one is an integer.
Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.
If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.
Of course, implement and turn in your own tests to ensure everything works as ex￾pected.

You don’t have to handle associative containers.
*/

int main() 
{
    std::cout << "\033[91mTestng Vector:\033[0m" << std::endl;
    std::vector<int> myVector;
    for (int i = 0; i < 10; ++i) {
        myVector.push_back(i * 2);
    }

    try 
    {
        std::cout << "Searching for 8 in vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(myVector, 8);
        std::cout << "Found: " << *result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Searching for 42 in vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(myVector, 42);
        std::cout << "Found: " << *result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n\033[91mTestng List:\033[0m" << std::endl;
    // Test with std::list
    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    try 
    {
        std::cout << "Searching for 30 in list..." << std::endl;
        std::list<int>::iterator result = easyfind(myList, 30);
        std::cout << "Found: " << *result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Searching for 99 in list..." << std::endl;
        std::list<int>::iterator result = easyfind(myList, 99);
        std::cout << "Found: " << *result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n\033[91mTestng Deque:\033[0m" << std::endl;
    // Test with std::deque (double-ended queue)
    std::deque<int> myDeque;
    myDeque.push_back(100);
    myDeque.push_back(200);
    myDeque.push_front(50);  // deque allows insertion at both ends
    myDeque.push_back(300);

    try 
    {
        std::cout << "Searching for 50 in deque..." << std::endl;
        std::deque<int>::iterator result = easyfind(myDeque, 50);
        std::cout << "Found: " << *result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Searching for 150 in deque..." << std::endl;
        std::deque<int>::iterator result = easyfind(myDeque, 150);
        std::cout << "Found: " << *result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n\033[91mTestng Edge Cases:\033[0m" << std::endl;
    // Test with empty container
    std::vector<int> emptyVector;
    try 
    {
        std::cout << "Searching for 1 in empty vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(emptyVector, 1);
        std::cout << "Found: " << *result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test with single element
    std::list<int> singleElementList;
    singleElementList.push_back(42);
    try 
    {
        std::cout << "Searching for 42 in single-element list..." << std::endl;
        std::list<int>::iterator result = easyfind(singleElementList, 42);
        std::cout << "Found: " << *result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
