This is an excellent question that goes right to the heart of why the Ford-Johnson sorting algorithm (also known as Merge Insertion) is so efficient, achieving the mathematical minimum number of comparisons. The use of Jacobsthal numbers governs the precise sequence of insertions performed using binary search, guaranteeing optimal performance.

Here is how the Jacobsthal numbers are used to structure the **binary search insertion** process:

### 1. Context: The Insertion Phase

After the initial pairing, internal sorting, and recursive sorting of the larger ("leading") elements, you have two groups:
1.  **The main chain ($A$):** The recursively sorted list of leading elements.
2.  **The non-leading elements ($B$):** The smaller elements from the initial pairs, awaiting insertion.

The goal is to insert every element from group $B$ into the sorted main chain $A$.

### 2. The Role of the Jacobsthal Sequence

The **Jacobsthal numbers** are critical because they define the order in which the non-leading elements are inserted into the main chain. This specific order is chosen to maximize the information gained during each binary search, minimizing the required comparisons.

The sequence of Jacobsthal numbers, denoted $t_k$, starts:
$$t_k = (1, 3, 5, 11, 21, \dots)$$

These numbers specify which elements (by their original indices in the paired non-leading group) are inserted. The sequence of indices used for insertion is structured as follows:

$$b_1; \quad b_3, b_2; \quad b_5, b_4; \quad b_{11}, b_{10}, \dots, b_6; \quad \dots$$

Where $b_j$ refers to the $j^{th}$ element in the list of non-leading elements.

### 3. How Binary Search is Applied (The Mechanism)

The crucial efficiency is gained through two specific rules related to binary search:

#### A. Insertion of the First Element
The very first non-leading element ($b_1$) is inserted **without any comparisons**. This is because it is already known to be smaller than its leading partner, and that partner is the smallest element in the sorted main chain $A$.

#### B. Restricted Binary Search
For every subsequent non-leading element ($b_j$), the search for its correct position is **restricted**.

When inserting $b_j$, you already know that $b_j$ is smaller than its original leading partner, $a_j$. Since $a_j$ is already sorted within the main chain, you only need to perform the binary search within the portion of the main chain that precedes $a_j$.

> **The insertion is done with binary search, searching from the beginning array, up to the leading partner element.**

By restricting the search space in this way, the algorithm ensures that the size of the set where the element $b_j$ can fall is a power of 2 minus 1 ($2^k - 1$), which allows the standard binary insertion technique to insert the element using precisely the minimum $k$ comparisons. The sequence $t_k$ is defined by the recurrence **$t_k + t_{k-1} = 2^k$**, which mathematically relates the maximum size of the already sorted subchain ($t_{k-1} + (t_k - t_{k-1}) = t_k$ elements) to the available depth $k$ for binary insertion.

#### C. Inserting Backward in Groups
The Jacobsthal sequence defines groups of elements to be inserted consecutively (e.g., $b_3, b_2$; or $b_{11}, \dots, b_6$). After inserting the element corresponding to the new Jacobsthal index ($t_k$), the algorithm **goes backwards from this position until the previous Jacobsthal index** ($t_{k-1}$).

For example, when $t_k=5$:
1. $b_5$ is inserted first (using binary search restricted up to its leading partner).
2. Then $b_4$ is inserted (going backward from 5 until 3).

This reverse insertion order is crucial because, once $b_{t_k}$ has been successfully placed, the constraints for locating $b_{t_k-1}, b_{t_k-2}, \dots$ are maximized, keeping the comparisons needed for these elements within the same small bound ($k$). This grouping ensures that the maximum number of comparisons for any insertion is minimized, fulfilling the constraint needed to reach the mathematical lower bound for the entire sort.

For an array of 11 elements, the sequence of indices inserted is $1, 3, 2, 5, 4$ (plus any remaining stragglers). For $b_5$ (which is '7' in the example walk-through, inserted at the index '5' position in the non-leading group), the restriction limits the search only up to the element '8' (its original leader).

In essence, the Jacobsthal numbers provide the **optimal schedule** for inserting the non-leading elements, while the binary search provides the **tool** to perform the insertion efficiently within the narrowly defined, optimal search window. This combination minimizes wasted comparisons by exploiting all previously obtained ordering information.