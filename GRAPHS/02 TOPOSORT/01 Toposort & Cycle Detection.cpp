// https://www.geeksforgeeks.org/problems/topological-sort/1

// https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21/

/* TOPOSORT 
-> the graph whose toposort we have to find will always be a DAG (directed acyclic graph)
*/

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

/* using DFS
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. 
There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and 
the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.
*/

class Solution {
private:
    void dfs(int src, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[src] = 1; // Marking the current node as visited

        for (int nbr : adj[src]) 
            if (vis[nbr] == -1) 
                dfs(nbr, adj, vis, st); // Recursive DFS traversal for unvisited neighbors


        // while backtracking we are adding the node.. so we first add the deepest node first
        // Pushing the current node into the stack after visiting all neighbors
        st.push(src); 
    }

public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> vis(V, -1); // Initialize the visited array with -1
        stack<int> st;

        // Perform DFS from each unvisited node
        for (int i = 0; i < V; ++i) 
            if (vis[i] == -1) 
                dfs(i, adj, vis, st);


        vector<int> topo; // Stores the topologically sorted nodes

        // Pop elements from the stack to get the topological order
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};


/* BFS | Kahn's Algorithm | Topological Sort Algorithm 

Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0); // Initialize indegree array with zeros

        // Calculate indegree for each vertex
        for (int i = 0; i < V; ++i) 
            for (int nbr : adj[i]) 
                indegree[nbr]++;


        queue<int> q;
        for (int i = 0; i < V; ++i) 
            if (indegree[i] == 0) 
                q.push(i); // Push vertices with indegree 0 into the queue
   

        vector<int> topo; // Stores the topologically sorted nodes

        // O(V + E)
        while (!q.empty()) {
            int src = q.front();
            q.pop();
            topo.push_back(src); // Push the current node into the result

            // Decrement the indegree of all neighbors of src
            for (int nbr : adj[src]) 
                if (--indegree[nbr] == 0) 
                    q.push(nbr); // Push neighbors with indegree 0 into the queue
               
        }

        return topo;
    }
};

/* CYCLE DETECTION: (modify Kahn's algo or BFS code)

    return topo.size() < V; // cycle detected

    CYCLE DETECTION: TOPOSORT DFS code can't me modified to determine if graph has cycle
*/