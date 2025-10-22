#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename Container>
void PmergeMe::mergeInsertSort(Container &C)
{
    if (C.size() <= 1)
        return;

    Container S;
    Container pend;
    typename Container::iterator it;

    for (it = C.begin(); it != C.end();)
    {
        int first = *it++;
        if (it != C.end())
        {
            int second = *it++;
            if (first > second)
                std::swap(first, second);
            S.push_back(second);
            pend.push_back(first);
        }
        else
        {
            pend.push_back(first);
        }
    }

    mergeInsertSort(S);

    for (size_t i = 0; i < pend.size(); ++i)
    {
        typename Container::iterator pos = std::lower_bound(S.begin(), S.end(), pend[i]);
        S.insert(pos, pend[i]);
    }
    C = S;
}

void PmergeMe::printInitialSequence(char **argv, int argc)
{
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::printSortedSequence(const Container &container)
{
    std::cout << "After:  ";
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::printTime(double time, const Container &container, const std::string &containerName)
{
    std::cout << "Time to process a range of " << container.size()
              << " elements with std::" << containerName << ": "
              << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}

void PmergeMe::sortAndMeasure(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!isdigit(arg[j]))
            {
                std::cerr << "Error: Invalid character in input." << std::endl;
                return;
            }
        }
        int value = atoi(argv[i]);
        if (value < 0)
        {
            std::cerr << "Error: Negative numbers are not allowed." << std::endl;
            return;
        }
        _vec.push_back(value);
        _deq.push_back(value);
    }

    printInitialSequence(argv, argc);

    clock_t start_vec = clock();
    mergeInsertSort(_vec);
    clock_t end_vec = clock();
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

    clock_t start_deq = clock();
    mergeInsertSort(_deq);
    clock_t end_deq = clock();
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

    printSortedSequence(_vec);
    printTime(time_vec, _vec, "vector");
    printTime(time_deq, _deq, "deque");
}