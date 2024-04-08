// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// article link: https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/

#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

/* USING DFS 

APPROCH

in case of DIRECTED GRAPH even if there is a cycle but not 
actually the cycle by the directed edges, so you will use 
2 visited arrays i.e. visited and pathVisited:


-Visited will ensure you don't re-explore the already explored paths
-pathVisited will help you know that the cycle being formed was in 
the same path or the visited node was explored while exploring 
some other path

refer following video is not understood
https://youtu.be/9twcmtQj4DU?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=228
*/
class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it] && dfsCheck(it, adj, vis, pathVis) == true) 
					return true;
			
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) 
				return true;
		}

		pathVis[node] = 0;
		return false;
	}

public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[50]     = {0};  // V = 50
		int pathVis[50] = {0};  // V = 50

		for (int i = 0; i < V; i++) 
			if (!vis[i]) 
				if (dfsCheck(i, adj, vis, pathVis) == true) return true;

		return false;
	}
};


/* using BFS - The BFS-based cycle detection algorithm I provided is based on Kahn's algorithm for topological sorting. 

It utilizes the concept of in-degrees to determine the order in which nodes should be processed, ensuring that nodes with no incoming edges (in-degree of 0) are processed first. If, after processing all nodes, there are still nodes remaining, it indicates the presence of a cycle in the graph. */

class Solution {
public:
    // Function to detect cycle in a directed graph using BFS.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0); // Store in-degree of each node
        queue<int> q;

        // Calculate in-degree of each node
        for (int i = 0; i < V; ++i) {
            for (int j : adj[i]) {
                ++inDegree[j];
            }
        }

        // Push nodes with in-degree 0 into the queue
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0; // Count of visited nodes

        // Perform BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ++visited;

            // Traverse neighbors of the current node
            for (int neighbor : adj[node]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return visited != V; // If not all nodes are visited, there is a cycle
    }
};
