Understanding the Ford-Johnson Algorithm
The Ford-Johnson algorithm is a comparison sorting algorithm that aims to minimize the number of comparisons needed to sort a list.[1][2] It's a complex algorithm that combines elements of both merge sort and insertion sort.[1] Here's a conceptual breakdown of the steps involved:
Pairing: The initial list of numbers is divided into pairs. If there's an odd number of elements, one will be left unpaired.
Pair Sorting: Each pair is sorted internally.
Recursive Sort: A new sequence is formed from the larger number of each pair. This new sequence is then sorted recursively using the same Ford-Johnson algorithm.
Main Chain and Pend Elements: The recursively sorted sequence of larger numbers forms what is called the "main chain." The smaller numbers from the pairs are designated as "pend" elements.
Insertion: The pend elements are then inserted into the sorted main chain one by one. The key to the algorithm's efficiency lies in the specific order of insertion, which is determined by Jacobsthal numbers.[3][4] This optimized insertion order, combined with binary search, helps to reduce the total number of comparisons.[3]
Choosing the Containers
The exercise requires the use of two different STL containers. For this implementation, the std::vector and std::deque are suitable choices. std::vector is a dynamic array, providing fast random access, while std::deque (double-ended queue) also allows for efficient insertions and deletions at both its beginning and end.
Measuring Performance
To compare the efficiency of the algorithm with the two containers, we'll need to measure the execution time. The <chrono> library in C++ is the standard and most accurate way to do this.[5][6] By recording the time before and after the sorting process, we can calculate the duration with high precision.[5]