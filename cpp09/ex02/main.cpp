#include "PmergeMe.hpp"

int main(int argc, char **argv)
{

    // Should I imiplement functions for already sorted stacks?
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive_integer_sequence>" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    sorter.sortAndMeasure(argc, argv);

    return 0;
}