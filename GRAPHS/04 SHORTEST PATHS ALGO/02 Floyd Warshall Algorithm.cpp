/** REFERENCES:
 * VIDEO: INTUTION: https://youtu.be/YbY8cVwWAvw?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=958
 * VIDEO: NEGATIVE:CYCLE:DETECTION: https://youtu.be/YbY8cVwWAvw?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=1362
 (the cost from a node to itself should be 0, but if there is a negative cycle then it will be less than 0, so then there is no point of continuing the algo since cost will keep on reducing on every iteration )
  * ARTICLE:  https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/
*/

/* This algo is not that intutive like other algo.
@Floyd-Warshall algorithm is used to find the shortest paths between all pairs 
of vertices in a weighted graph, including negative-weight edges (but no negative cycles). 

*If the graph has a negative cycle (In this case Dijkstra's algorithm fails to minimize the distance, keeps on running, and goes into an infinite loop. As a result it gives TLE error).


Here are some important points about the Floyd-Warshall algorithm:

* 0. REACHING "i" to "j" VIA "k".

* 1. All-Pairs Shortest Paths: 
Floyd-Warshall computes the shortest paths between all pairs of vertices in a graph.

* 2. Dynamic Programming: 
It is a dynamic programming algorithm, based on the principle of solving subproblems and using their solutions to build up to the final solution.

* 3. Negative Edge Weights: It can handle graphs with negative edge weights "but not negative cycles".

* 4. Time Complexity: O(V^3)
The time complexity of Floyd-Warshall algorithm is O(V^3), where V is the number of vertices in the graph.

* 5. Space Complexity: O(V^2)
The space complexity of the algorithm is O(V^2), where V is the number of vertices.

6. Matrix-Based Implementation: It is commonly implemented using a matrix to represent the distances between all pairs of vertices.

7. All-Pairs Shortest Path Matrix: The algorithm computes and fills a matrix where each entry [i][j] represents the shortest distance from vertex i to vertex j.

8. Iterative Approach: Floyd-Warshall iteratively improves the shortest path estimates until reaching the optimal solution.

9. Negative Cycle Detection: It can be used to detect the presence of negative cycles in a graph.

10. Transitive Closure: Besides finding shortest paths, Floyd-Warshall can also be used to compute the transitive closure of a graph, i.e., determining whether there is a path between every pair of vertices.*/



#include <vector>
#include <set>
#include <queue> 
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size(); 

        //* Replace all -1 entries in the matrix with a large value to represent infinity
        //* Set the diagonal entries (self-loops) to 0
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9; // Large value to represent infinity
                if (i == j)
                    matrix[i][j] = 0;   // Set diagonal entries to 0
            }


        // Compute shortest distances between all pairs of vertices using Floyd-Warshall algorithm
        // * i to j via k
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    // Update the shortest distance between vertex i and vertex j
                    // by considering vertex k as an intermediate vertex
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);



        //* Restore -1 entries in the matrix to represent unreachable vertices
        // Set the large values back to -1 for better representation
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1e9)
                    matrix[i][j] = -1; // Restore -1 entries
    }
};
