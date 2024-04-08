// https://leetcode.com/problems/find-eventual-safe-states/description/

#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

/* using DFS - my 3rd sem or 1 old solution
    JUST SLIGHT CHANGE IN CHECH IF CYCLE CODE
*/
class Solution {

    // Depth-First Search (DFS) function to detect cycles and find eventual safe nodes
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVisited) {

        visited[src]     = 1;  // Mark the current node as visited
        pathVisited[src] = 1;  // Mark the current node as visited on the current path

        // Traverse the neighbors of the current node
        for (int neighbor : graph[src]) {
            // If the neighbor is unvisited, recursively call DFS on it
            if (visited[neighbor] == 0 && dfs(neighbor, graph, visited, pathVisited)) {
                    return true; // If a cycle is detected, return true

            } else if (pathVisited[neighbor] == 1) {
                // If the neighbor is visited on the current path, a cycle is detected, return true
                return true;
            }
        }

        // Mark the current node as visited and remove it from the current path
        // This will mean that this node was not part of the cycle
        pathVisited[src] = 0;

        return false; // No cycle detected, return false
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size(); 
        vector<int> visited(n, 0);      // Array to track visited nodes during DFS
        vector<int> pathVisited(n, 0);  // Array to track visited nodes on the current path


        // Perform DFS for each unvisited node to find eventual safe nodes
        // we don't care if there is any cycle or not -- we just need to visit all the nodes
        // to know that which all part of cycle and which are not
        // by marking them part of cycle initially, if they weren't then unmarking them 
        for (int i = 0; i < n; ++i) 
            if (visited[i] == 0) 
                dfs(i, graph, visited, pathVisited); 

        // Collect NODES THAT ARE NOT PART OF CYCLE (or eventual safe nodes)
        vector<int> ans;
        for (int i = 0; i < n; ++i) 
            if (pathVisited[i] == 0) 
                ans.push_back(i); 

        return ans; 
    }
};





/* using BFS */
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size(); // Number of nodes
        
        // Create a reverse adjacency list to represent incoming edges
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
        
        // Calculate indegrees for each node and create reverse adjacency list
        for (int i = 0; i < V; ++i) {
            for (int j : graph[i]) {
                adjRev[j].push_back(i);
                indegree[i]++;
            }
        }
        
        // Perform topological sorting using BFS
        queue<int> q;
        vector<int> safeNodes;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i); // Enqueue nodes with indegree 0
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node); // Add the current node to the list of safe nodes
            for (int neighbor : adjRev[node]) {
                indegree[neighbor]--; // Decrement the indegree of adjacent nodes
                if (indegree[neighbor] == 0) {
                    q.push(neighbor); // Enqueue adjacent nodes with updated indegree 0
                }
            }
        }

        // Sort the list of safe nodes
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};

