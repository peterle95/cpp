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
void PmergeMe::binaryInsert(Container &mainChain, int value, size_t maxPos)
{
    if (mainChain.empty() || maxPos == 0)
    {
        mainChain.insert(mainChain.begin(), value);
        return;
    }
    
    // Limit search to the range [0, maxPos]
    size_t left = 0;
    size_t right = (maxPos < mainChain.size()) ? maxPos : mainChain.size();
    
    // Binary search for insertion position
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (mainChain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    mainChain.insert(mainChain.begin() + left, value);
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t maxSize)
{
    std::vector<size_t> jacobsthal;
    
    if (maxSize == 0)
        return jacobsthal;
    
    size_t j_prev2 = 0;  // J(0) = 0
    size_t j_prev1 = 1;  // J(1) = 1
    
    jacobsthal.push_back(1);  // Start with J(1) = 1
    
    // Generate sequence until exceed maxSize
    while (true)
    {
        size_t j_current = j_prev1 + 2 * j_prev2;  // Recurrence relation
        if (j_current > maxSize)
            break;
        jacobsthal.push_back(j_current);
        j_prev2 = j_prev1;
        j_prev1 = j_current;
    }
    
    return jacobsthal;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t pendSize)
{
    std::vector<size_t> insertionOrder;
    
    if (pendSize == 0)
        return insertionOrder;
    
    // Generate Jacobsthal sequence for this pend size
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pendSize);
    
    // Build insertion order using Jacobsthal numbers as group boundaries
    size_t prevJacob = 0;
    
    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        size_t currentJacob = jacobsthal[i];
        if (currentJacob > pendSize)
            currentJacob = pendSize;
        
        // Insert from currentJacob-1 down to prevJacob (reverse order within group)
        // This creates the "pendulum" pattern
        for (size_t j = currentJacob; j > prevJacob; --j)
        {
            insertionOrder.push_back(j - 1);  // Convert to 0-based index
        }
        
        prevJacob = currentJacob;
        if (currentJacob >= pendSize)
            break;
    }
    
    // Add any remaining elements not covered by Jacobsthal sequence
    for (size_t i = prevJacob; i < pendSize; ++i)
    {
        insertionOrder.push_back(i);
    }
    
    return insertionOrder;
}

// comparator function for sorting pairs by their larger element (second)
static bool pairSecondLess(const std::pair<int,int> &p1, const std::pair<int,int> &p2)
{
    return p1.second < p2.second;
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container &container)
{
    // Base case: arrays of size 0 or 1 are already sorted
    if (container.size() <= 1)
        return;
    
    // STEP 1: PAIRING PHASE
    // Store pairs as (smaller, larger) to maintain the constraint
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = false;
    int straggler = 0;
    
    // Create pairs and sort each pair internally
    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        int a = container[i];
        int b = container[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));  // (smaller, larger)
    }
    
    // Handle odd element (straggler)
    if (container.size() % 2 == 1)
    {
        hasStraggler = true;
        straggler = container[container.size() - 1];
    }
    
    // STEP 2: RECURSIVE SORT ON LARGER ELEMENTS
    // Extract larger elements to form the main chain
    Container mainChain;
    // IMPORTANT: sort pairs by their larger element before extracting the main chain
    // This preserves the correspondence between a larger element and its paired smaller
    // element when we later insert the pend values.
    // sort using file-scope comparator
    std::sort(pairs.begin(), pairs.end(), pairSecondLess);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].second);  // larger element
    }
    
    // Recursively sort the main chain
    mergeInsertSort(mainChain);
    
    // STEP 3: BUILD PEND ARRAY
    // Collect smaller elements (to be inserted)
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        pend.push_back(pairs[i].first);  // smaller element
    }
    
    // STEP 4: INSERT FIRST PEND ELEMENT
    // pend[0] is guaranteed ≤ mainChain[0], so insert at beginning (0 comparisons!)
    if (!pend.empty())
    {
        mainChain.insert(mainChain.begin(), pend[0]);
    }
    
    // STEP 5: INSERT REMAINING PEND USING JACOBSTHAL ORDER
    if (pend.size() > 1)
    {
        // Generate optimal insertion order based on Jacobsthal sequence
        std::vector<size_t> insertionOrder = generateInsertionOrder(pend.size() - 1);
        
        // Insert each pend element according to the order
        for (size_t i = 0; i < insertionOrder.size(); ++i)
        {
            size_t pendIndex = insertionOrder[i] + 1;  // +1 because already inserted pend[0]
            int valueToInsert = pend[pendIndex];
            
            // Calculate maximum search position (maxPos)
            // Formula: maxPos = pairedElementPos + elementsInserted
            size_t pairedElementPos = pendIndex;
            size_t elementsInserted = i + 1;
            size_t maxPos = pairedElementPos + elementsInserted;
            
            binaryInsert(mainChain, valueToInsert, maxPos);
        }
    }
    
    // STEP 6: HANDLE STRAGGLER
    // Insert the odd element (if any) using binary search over entire array
    if (hasStraggler)
    {
        binaryInsert(mainChain, straggler, mainChain.size());
    }
    
    // Replace original container with sorted result
    container = mainChain;
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

void PmergeMe::printInitialSequence(char **argv, int argc)
{
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortAndMeasure(int argc, char **argv)
{
    // Input validation and parsing
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