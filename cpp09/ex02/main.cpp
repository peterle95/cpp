#include "PmergeMe.hpp"

bool isSorted(int argc, char **argv) 
{
    for (int i = 1; i < argc - 1; i++) 
    {
        int current = std::atoi(argv[i]);
        int next = std::atoi(argv[i + 1]);
        if (current > next)
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive_integer_sequence>" << std::endl;
        return 1;
    }

        // Check if input is already sorted
    if (isSorted(argc, argv)) 
    {
        std::cout << "Input sequence is already sorted!" << std::endl;
        // Print the sequence
        std::cout << "Sequence: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << std::endl;
        return 0;
    }

    PmergeMe sorter;
    sorter.sortAndMeasure(argc, argv);

    return 0;
}