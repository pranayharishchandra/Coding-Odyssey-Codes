#include <vector>
#include <set>
#include <queue> 
#include <stack> 
#include <iostream>
#include <algorithm>
using namespace std;

/* APPROACH: 
since the distance is uniform (1 here)
so we just need to check how many nodes are coming in between
the Original Source node and the Target Node

and for just knowing how "minium" many nodes far is one node from other
we can just use "BFS algo" 

EXAMPLE:
  Suppose there are no nodes between src and target node
  i.e. they are diretly connected then 
  the distnace between them would be
  answer = (uniform wt b/w any 2 nodes) x (nodes inbetwee + 1)
                                      1 x 1 = 1
*/

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Create an adjacency list for storing the undirected graph.
        vector<vector<int>> adj(N); 
        for (const auto& it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        // A dist array initialised with INT_MAX to indicate untraversed nodes.
        vector<int> dist(N, INT_MAX);

        // BFS Implementation.
        queue<int> q;
        q.push(src); 
        dist[src] = 0; 

        while (!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for (int neighbor : adj[node]) {
                if (dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = 1 + dist[node]; 
                    q.push(neighbor); 
                }
            }
        }

        // Unreachable nodes are marked as -1. 
        for (int i = 0; i < N; ++i) 
            if (dist[i] == INT_MAX) 
                dist[i] = -1; 

        return dist; 
    }
};



