// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cmath>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortAndMeasure(int argc, char **argv);

private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    // Generate the Jacobsthal-like sequence t_k
    // Formula: t_k = (2^(k+1) + (-1)^k) / 3
    // This sequence determines optimal insertion group sizes
    std::vector<size_t> generateJacobsthalSequence(size_t maxSize);

    // Generate the actual insertion order based on Jacobsthal sequence
    // This creates the "pendulum" pattern that minimizes comparisons
    std::vector<size_t> generateInsertionOrder(size_t pendSize);

    void printInitialSequence(char **argv, int argc);

    template <typename Container>
    void mergeInsertSort(Container &container);

    template <typename Container>
    void binaryInsert(Container &container, int value, size_t maxPos);

    template <typename Container>
    void printSortedSequence(const Container &container);

    template <typename Container>
    void printTime(double time, const Container &container, const std::string &containerName);
};

#endif