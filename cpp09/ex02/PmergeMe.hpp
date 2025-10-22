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

    template <typename Container>
    void mergeInsertSort(Container &container);

    void printInitialSequence(char **argv, int argc);

    template <typename Container>
    void printSortedSequence(const Container &container);

    template <typename Container>
    void printTime(double time, const Container &container, const std::string &containerName);
};

#endif