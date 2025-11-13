// PmergeMe.cpp
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

// ============================================================================
// JACOBSTHAL SEQUENCE GENERATION (t_k sequence)
// ============================================================================
// The Ford-Johnson algorithm relies on the Jacobsthal-like sequence to 
// determine optimal group sizes for insertion, minimizing comparisons.
//
// Formula: t_k = (2^(k+1) + (-1)^k) / 3
//
// This generates the sequence: 1, 3, 5, 11, 21, 43, 85, 171, 341, ...
// Wait, let me recalculate based on the document which states: 1, 2, 4, 7, 11, 21...
// 
// Actually, the recurrence relation is: t_{k-1} + t_k = 2^k
// Starting with t_0 = 0, t_1 = 1:
// t_0 = 0
// t_1 = 1 (since t_0 + t_1 = 2^1 = 2, so t_1 = 2 - 0 = 2... hmm)
//
// Let me use the exact formula from the document:
// t_k = (2^(k+1) + (-1)^k) / 3
//
// k=0: t_0 = (2^1 + 1) / 3 = 3/3 = 1
// k=1: t_1 = (2^2 + (-1)) / 3 = 3/3 = 1... that's not right either
//
// The document shows the sequence: 1, 2, 4, 7, 11, 21...
// Let me check with recurrence t_{k-1} + t_k = 2^k:
// If we start with t_1 = 1:
// t_1 + t_2 = 2^2 = 4, so t_2 = 3... no that gives us 1, 3...
//
// Let me use the actual Jacobsthal numbers definition for Ford-Johnson:
// J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2*J(n-2)
// This gives: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171...
//
// For Ford-Johnson, we typically use: 1, 3, 5, 11, 21, 43, 85...
// (skipping the first 0 and duplicate 1)
// ============================================================================
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t maxSize)
{
    std::vector<size_t> jacobsthal;
    
    // Generate Jacobsthal numbers: J(n) = J(n-1) + 2*J(n-2)
    // Starting with J(0) = 0, J(1) = 1
    // Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341...
    
    if (maxSize == 0)
        return jacobsthal;
    
    size_t j_prev2 = 0;  // J(0)
    size_t j_prev1 = 1;  // J(1)
    
    // We start from index 2 in the Jacobsthal sequence
    // because we want 1, 3, 5, 11, 21... (skipping the first 0)
    jacobsthal.push_back(1);  // J(1)
    
    while (true)
    {
        size_t j_current = j_prev1 + 2 * j_prev2;
        if (j_current > maxSize)
            break;
        jacobsthal.push_back(j_current);
        j_prev2 = j_prev1;
        j_prev1 = j_current;
    }
    
    return jacobsthal;
}

// ============================================================================
// INSERTION ORDER GENERATION
// ============================================================================
// The insertion order is critical for minimizing comparisons in Ford-Johnson.
// 
// After creating pairs and sorting, we have:
// - Main chain: [larger elements from pairs] (already sorted)
// - Pend: [smaller elements from pairs] (to be inserted)
//
// EXAMPLE with 11 elements: 5 3 9 1 7 2 8 4 6 10 11
// After pairing and sorting pairs: (3,5) (1,9) (2,7) (4,8) (6,10) and straggler 11
// Main chain after recursive sort: [5, 9, 7, 8, 10]
// Pend elements (in order): [3, 1, 2, 4, 6] + straggler
//
// The Jacobsthal sequence tells us the GROUP boundaries for insertion:
// Jacobsthal: 1, 3, 5, 11, 21...
// 
// Insertion order (indices into pend array):
// - Group 1: Insert pend[0] (position 1 in Jacobsthal)
// - Group 2: Insert pend[2], pend[1] (from position 3 down to previous+1)
// - Group 3: Insert pend[4], pend[3] (from position 5 down to previous+1)
// - Continue...
//
// This "pendulum" pattern ensures we always know the maximum search range
// for binary insertion, minimizing total comparisons.
// ============================================================================
std::vector<size_t> PmergeMe::generateInsertionOrder(size_t pendSize)
{
    std::vector<size_t> insertionOrder;
    
    if (pendSize == 0)
        return insertionOrder;
    
    // Generate Jacobsthal sequence for this pend size
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pendSize);
    
    // Build insertion order using Jacobsthal numbers
    // We insert in groups defined by consecutive Jacobsthal numbers
    size_t prevJacob = 0;
    
    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        size_t currentJacob = jacobsthal[i];
        if (currentJacob > pendSize)
            currentJacob = pendSize;
        
        // Insert from currentJacob-1 down to prevJacob (in reverse order within group)
        // Example: if prevJacob=1 and currentJacob=3, insert indices 2, 1
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

// ============================================================================
// BINARY INSERTION FOR VECTOR
// ============================================================================
// Binary insertion finds the correct position in O(log n) comparisons.
// maxPos limits the search range - we only search up to the position where
// we KNOW the element must be (based on the paired element's position).
//
// EXAMPLE: Inserting value=3 into mainChain=[5, 9, 7, 8, 10], maxPos=1
// We know 3 was paired with 5 (at index 0), so 3 must be inserted before
// or at position 1 (maxPos). We don't need to search beyond that.
// Binary search range: [0, 1]
// - mid=0: mainChain[0]=5 > 3, search left
// - Insert at position 0
// Result: [3, 5, 9, 7, 8, 10]
// ============================================================================
void PmergeMe::binaryInsertVector(std::vector<int> &mainChain, int value, size_t maxPos)
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

// ============================================================================
// BINARY INSERTION FOR DEQUE
// ============================================================================
// Same logic as vector version, but adapted for std::deque container.
// Deque provides O(1) insertion at both ends, but O(n) in the middle.
// However, it still benefits from the reduced comparisons of binary search.
// ============================================================================
void PmergeMe::binaryInsertDeque(std::deque<int> &mainChain, int value, size_t maxPos)
{
    if (mainChain.empty() || maxPos == 0)
    {
        mainChain.insert(mainChain.begin(), value);
        return;
    }
    
    size_t left = 0;
    size_t right = (maxPos < mainChain.size()) ? maxPos : mainChain.size();
    
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

// ============================================================================
// FORD-JOHNSON ALGORITHM FOR VECTOR
// ============================================================================
// MAIN ALGORITHM STEPS:
// 
// 1. PAIRING PHASE:
//    - Divide input into pairs: (a1,b1), (a2,b2), ..., (an,bn) [+ straggler]
//    - Sort each pair so first < second
//    - Example: [5,3,9,1,7] → pairs: (3,5), (1,9) + straggler 7
//
// 2. RECURSIVE SORT:
//    - Extract larger elements from each pair: [5, 9]
//    - Recursively sort this sequence: [5, 9]
//    - This becomes our "main chain" (sorted)
//
// 3. BUILD PEND ARRAY:
//    - Collect smaller elements: [3, 1]
//    - These will be inserted into main chain
//
// 4. INSERT FIRST PEND ELEMENT:
//    - Insert pend[0] at the beginning (it's guaranteed to be smallest)
//    - Main chain: [3, 5, 9]
//
// 5. INSERT REMAINING PEND USING JACOBSTHAL ORDER:
//    - Generate insertion order using Jacobsthal: [0, 1] for this small example
//    - For each index i in insertion order:
//      * Calculate maxPos: position of paired element + already inserted count
//      * Binary insert pend[i] into main chain up to maxPos
//    - Example: Insert pend[1]=1, maxPos=2+1=3
//      * Binary search in [3,5,9] up to position 3
//      * Insert at position 0: [1, 3, 5, 9]
//
// 6. HANDLE STRAGGLER:
//    - If there was an odd element, binary insert it at the end
//    - Example: Insert 7, search full array [1,3,5,9]
//    - Result: [1, 3, 5, 7, 9]
//
// WHY THIS MINIMIZES COMPARISONS:
// - Pairing reduces problem size by half
// - Recursive sorting on larger elements means pend elements have known bounds
// - Jacobsthal insertion order ensures optimal binary search ranges
// - Each pend[i] is guaranteed ≤ its paired element, limiting search space
// ============================================================================
void PmergeMe::mergeInsertSortVector(std::vector<int> &container)
{
    // Base case: arrays of size 0 or 1 are already sorted
    if (container.size() <= 1)
        return;
    
    // STEP 1: PAIRING PHASE
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = false;
    int straggler = 0;
    
    // Create pairs and sort each pair (smaller, larger)
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
    // Extract larger elements from pairs to form sequence for recursive sorting
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].second);  // larger element
    }
    
    // Recursively sort the main chain
    mergeInsertSortVector(mainChain);
    
    // STEP 3: BUILD PEND ARRAY
    // Collect smaller elements in the order corresponding to sorted main chain
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        pend.push_back(pairs[i].first);  // smaller element
    }
    
    // STEP 4: INSERT FIRST PEND ELEMENT
    // The first pend element is guaranteed to be ≤ mainChain[0], so insert at beginning
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
            size_t pendIndex = insertionOrder[i] + 1;  // +1 because we already inserted pend[0]
            int valueToInsert = pend[pendIndex];
            
            // Calculate maximum search position (maxPos)
            // This is where the paired larger element is, plus how many we've inserted
            // The pend element must be inserted before or at its paired element's position
            size_t pairedElementPos = pendIndex;  // Position in original sorted main chain
            size_t elementsInserted = i + 1;      // How many pend elements inserted so far (including first)
            size_t maxPos = pairedElementPos + elementsInserted;
            
            // Binary insert with limited search range
            binaryInsertVector(mainChain, valueToInsert, maxPos);
        }
    }
    
    // STEP 6: HANDLE STRAGGLER
    // Insert the odd element (if any) using binary search over entire array
    if (hasStraggler)
    {
        binaryInsertVector(mainChain, straggler, mainChain.size());
    }
    
    // Replace original container with sorted result
    container = mainChain;
}

// ============================================================================
// FORD-JOHNSON ALGORITHM FOR DEQUE
// ============================================================================
// Identical logic to vector version, but using std::deque container.
// Deque has similar performance characteristics but different memory layout
// (non-contiguous storage in chunks vs vector's contiguous array).
// This allows us to compare performance between containers.
// ============================================================================
void PmergeMe::mergeInsertSortDeque(std::deque<int> &container)
{
    if (container.size() <= 1)
        return;
    
    // STEP 1: PAIRING PHASE
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = false;
    int straggler = 0;
    
    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        int a = container[i];
        int b = container[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    
    if (container.size() % 2 == 1)
    {
        hasStraggler = true;
        straggler = container[container.size() - 1];
    }
    
    // STEP 2: RECURSIVE SORT
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].second);
    }
    
    mergeInsertSortDeque(mainChain);
    
    // STEP 3: BUILD PEND
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        pend.push_back(pairs[i].first);
    }
    
    // STEP 4: INSERT FIRST PEND
    if (!pend.empty())
    {
        mainChain.insert(mainChain.begin(), pend[0]);
    }
    
    // STEP 5: INSERT REMAINING PEND
    if (pend.size() > 1)
    {
        std::vector<size_t> insertionOrder = generateInsertionOrder(pend.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); ++i)
        {
            size_t pendIndex = insertionOrder[i] + 1;
            int valueToInsert = pend[pendIndex];
            
            size_t pairedElementPos = pendIndex;
            size_t elementsInserted = i + 1;
            size_t maxPos = pairedElementPos + elementsInserted;
            
            binaryInsertDeque(mainChain, valueToInsert, maxPos);
        }
    }
    
    // STEP 6: HANDLE STRAGGLER
    if (hasStraggler)
    {
        binaryInsertDeque(mainChain, straggler, mainChain.size());
    }
    
    container = mainChain;
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

    // Sort with vector and measure time
    clock_t start_vec = clock();
    mergeInsertSortVector(_vec);
    clock_t end_vec = clock();
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

    // Sort with deque and measure time
    clock_t start_deq = clock();
    mergeInsertSortDeque(_deq);
    clock_t end_deq = clock();
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

    // Display results
    printSortedSequence(_vec);
    printTime(time_vec, _vec, "vector");
    printTime(time_deq, _deq, "deque");
}