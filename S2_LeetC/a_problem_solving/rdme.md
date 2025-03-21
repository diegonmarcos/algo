## 1. Dynamic Programming Algorithms**

* **Key Characteristics:**
    * Optimal substructure
    * Overlapping subproblems
    * Memoization (top-down) or tabulation (bottom-up)
    * Optimization problems
* **Examples:**
    * **Fibonacci Sequence:** Efficient calculation of Fibonacci numbers.
    * **Longest Common Subsequence (LCS):** Finding the longest common subsequence of two strings.
    * **Knapsack Problem (0/1 and Unbounded):** Optimizing item selection with weight constraints.
    * **Edit Distance (Levenshtein Distance):** Calculating the minimum operations to transform one string into another.
    * **Matrix Chain Multiplication:** Finding the optimal order for matrix multiplication.
    * **Shortest Path Algorithms:**
        * Floyd-Warshall algorithm (all-pairs shortest paths)
        * Bellman-Ford algorithm (single-source shortest paths with negative weights)
    * **Binomial Coefficient:** Calculating binomial coefficients efficiently.
    * **Optimal Binary Search Tree:** Constructing the optimal binary search tree.
    * **Subset Sum Problem:** Determining if a subset of a set sums to a given value.
    * **Rod Cutting:** Optimizing the cutting of a rod to maximize profit.
    * **Traveling Salesman Problem (TSP) (using Held-Karp):** An optimal solution, but very expensive.

## 2. Backtracking Algorithms**

* **Key Characteristics:**
    * Exploration of all possible solutions
    * Recursive approach
    * Pruning of invalid solutions
    * Search problems
* **Examples:**
    * **N-Queens Problem:** Placing N queens on a chessboard without conflicts.
    * **Sudoku Solver:** Solving Sudoku puzzles.
    * **Knight's Tour:** Finding a path for a knight to visit all squares on a chessboard.
    * **Maze Solving:** Finding a path through a maze.
    * **Subset Sum Problem (alternative to DP):** Finding subsets that sum to a target.
    * **Permutations and Combinations:** Generating all permutations or combinations of a set.
    * **Graph Coloring:** Assigning colors to vertices of a graph without adjacent vertices having the same color.
    * **Hamiltonian Cycle:** Finding a cycle that visits every vertex exactly once.
    * **Word Search:** Finding words in a grid of letters.

## 3. Greedy Algorithms**

* **Key Characteristics:**
    * Locally optimal choices
    * No backtracking
    * Efficient execution
    * Optimization problems (often approximations)
* **Examples:**
    * **Activity Selection Problem:** Selecting the maximum number of non-overlapping activities.
    * **Coin Change Problem (for canonical coin systems):** Finding the minimum number of coins.
    * **Dijkstra's Algorithm (single-source shortest paths with non-negative weights):** Finding the shortest paths from a single source.
    * **Prim's Algorithm (Minimum Spanning Tree):** Finding the minimum spanning tree of a graph.
    * **Kruskal's Algorithm (Minimum Spanning Tree):** Finding the minimum spanning tree of a graph.
    * **Fractional Knapsack Problem:** Optimizing item selection with fractional weights.
    * **Huffman Coding:** Compressing data using variable-length codes.
    * **Job Sequencing with Deadlines:** Optimizing job scheduling with deadlines.

## 4. Concurrent Algorithms**

* **Key Characteristics:**
    * Multiple threads or processes executing simultaneously
    * Synchronization and communication mechanisms
    * Increased performance (potentially)
    * Complexity in managing shared resources
* **Examples:**
    * **Producer-Consumer Problem:** Coordinating producers and consumers of data.
    * **Readers-Writers Problem:** Managing concurrent read and write access to a shared resource.
    * **Dining Philosophers Problem:** Illustrating deadlock and resource contention.
    * **Parallel Sorting Algorithms:**
        * Parallel Merge Sort
        * Parallel Quick Sort
    * **Concurrent Data Structures:**
        * Concurrent Queues
        * Concurrent Hash Maps
    * **MapReduce:** Distributed data processing.
    * **Message Passing Interface (MPI) algorithms:** used in High Performance Computing.
    * **Thread pool algorithms:** Managing a pool of threads to execute tasks.
    * **Distributed consensus algorithms:** (Paxos, Raft) used in distributed systems.
