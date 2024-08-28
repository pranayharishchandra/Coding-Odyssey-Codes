// https://leetcode.com/problems/find-eventual-safe-states/description/

/*
* Intution
(1) since a terminal node or a node with path going to terminal node (avoiding cycle)

* (2) in exmaple 1 (leetcode): 
0 and 1 are involved in a loop, and their indegree arn't 0
and they come before 2, 3 and 5
so since 0 and 1 can't have indegree 0, hence 2, 3, 5 also can't have indegree 0
since the bond (from 0 or 1) to them was never broken

- so that's whey you need to reverse the graph directions, 
so parents invoved in the cycle don't hamper the child nodes from getting added into answer (reaching the teminal node)

* - travel from the terminal node and come back to the other (prev/parent) nodes
* hence the direction needs to be changed, as from terminal (end node) we are coming back
*/
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




/* using BFS | Kahn's Algo | using TOPOSORT 

        APPROACH
the node with outdegree 0 is the terminal node and the nodes 
part of the cycle i.e. with indegree not 0 OR outdegree not 0
are not safe nodes

-> now since the nodes with outdegree 0 are safe nodes
> we can reverse the graph so 
> outdegree becomes indegree 
> hence we can now use TOPOSORT
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        
        // Create a "REVERSE" adjacency list to represent incoming edges
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
        

        // originally: i -> j
        // reverse   : i <- j
        for (int i = 0; i < V; ++i) {
            for (int j : graph[i]) {
                adjRev[j].push_back(i);
                indegree[i]++;
            }
        }
        
        // Perform topological sorting using BFS
        queue<int> q;
        vector<int> safeNodes;
        for (int i = 0; i < V; ++i) 
            if (indegree[i] == 0) 
                q.push(i); // Enqueue nodes with indegree 0


        while (!q.empty()) {

            int node = q.front();
            q.pop();
            // safeNodes.push_back(node); 

            for (int neighbor : adjRev[node]) 
                if (--indegree[neighbor] == 0) 
                    q.push(neighbor); 

        }

        // sort(safeNodes.begin(), safeNodes.end());

        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                safeNodes.push_back(i);
        
        return safeNodes;
    }
};

