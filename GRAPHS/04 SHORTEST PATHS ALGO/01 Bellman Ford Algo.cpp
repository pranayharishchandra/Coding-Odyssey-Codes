 /* REFERENCES
 *Video: https://youtu.be/0vVofAhAYjc?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=911
 * question: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
 */
 
 /*
  * Some important points about the Bellman-Ford algorithm:

* 0. Edge relaxation: updating the distance of a vertex to a shorter path from a bigger path (initiallly: INT_MAX).

* 1. Single Source Shortest Path: 
Bellman-Ford algorithm is used to find the shortest paths from a single source vertex to all other vertices in a weighted graph, even in the presence of negative weight edges.

*2. Dynamic Programming: 
It is based on dynamic programming paradigm. It computes shortest paths in a bottom-up manner by relaxing edges iteratively.

*3. Negative Weight Cycles: (infinitely decreasing cost)
It can detect negative weight cycles in the graph. If there is a negative weight cycle reachable from the source vertex, the algorithm indicates that no shortest paths exist due to the infinitely decreasing cost along the cycle.

4. Edge Relaxation: 
At each iteration, the algorithm relaxes every edge (reduces the cost of reaching a vertex if a shorter path is found). This process is repeated for |V| - 1 times, where |V| is the number of vertices in the graph.

5. Optimization: Bellman-Ford algorithm can be optimized by stopping the process if no relaxation occurred during an iteration. This indicates that the shortest paths have already been found.

*6. Time Complexity: O(V-1 * E) + O(E) = O(V*E)
The time complexity of the Bellman-Ford algorithm is O(V*E), where V is the number of vertices and E is the number of edges in the graph.

*7. Space Complexity: O(V) (since single source)
The space complexity of the algorithm is O(V), where V is the number of vertices, as it requires space to store the distances from the source vertex to all other vertices.

8. Initialization: Before the algorithm starts, distances from the source vertex to all other vertices are initialized to infinity, except for the source itself (which is set to 0).

*9. Detection of Negative Cycles: If the algorithm detects a negative cycle during the |V| - 1 iterations, it indicates that the graph contains a negative cycle reachable from the source vertex.

10. Relaxation Operation: The relaxation operation involves comparing the current shortest distance to a vertex with the sum of the distance to its neighboring vertex plus the weight of the edge connecting them. If the latter is smaller, the distance to the vertex is updated.
 */


#include <vector>
#include <set>
#include <queue> 
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    /*  
        Function to implement Bellman Ford algorithm to find the shortest paths from a single source vertex to all other vertices in a weighted graph.
        
        edges: vector of vectors representing the graph with each inner vector containing three integers (u, v, wt), where u and v are the vertices of the edge and wt is the weight of the edge.
        S    : source vertex to start traversing the graph from.
        V    : number of vertices in the graph.
        
        Returns a vector containing the shortest distances from the source vertex to all other vertices. If a negative cycle is detected, returns {-1}.
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {

        // Initialize distances from source to all vertices as infinity (1e8).
        vector<int> dist(V, 1e8); 
        
        dist[S] = 0; // Distance from source to itself is 0.

        //* Perform V-1 iterations for edge relaxation.
        for (int i = 0; i < V - 1; i++) { // * O(V-1)
            // Iterate over all edges.
            for (auto it : edges) { // * O(E)
                int u  = it[0];
                int v  = it[1];
                int wt = it[2];

                // Relax the edge if a shorter path is found.
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) 
                    dist[v] = dist[u] + wt;
            }
        }

        //* Check for negative cycles 
        //* by checking if the distance is "STILL REDUCING" in "V" time relaxation
        for (auto it : edges) { // * O(E)
            int u  = it[0];
            int v  = it[1];
            int wt = it[2];

            // If relaxation is possible even after V-1 iterations, a negative cycle exists.
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) 
                return { -1 };
            
        } 

        // Return the shortest distances from the source vertex to all other vertices.
        return dist;
    }
};
