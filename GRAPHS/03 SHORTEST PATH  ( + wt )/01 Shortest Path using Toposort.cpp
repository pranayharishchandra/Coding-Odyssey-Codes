#include <vector>
#include <set>
#include <queue> 
#include <stack> 
#include <iostream>
#include <algorithm>
using namespace std;

/* APPROACH
element on the top will be the node which is not dependent on anyone

Time Complexity: 
BFS + (Finding distance from the src -- using toposort)
O(E + V) + O(V) ~ O(E + V), which is BETTER than DIJKSTRA's Algo (E log V)
*/
class Solution {
private:
    // Simple DFS to populate the stack with nodes in topological order
    void dfs(vector<pair<int, int>> adj[], vector<int>& vis, int src, stack<int>& st) {
        vis[src] = 1;
        for (const auto& edge : adj[src]) {
            int nbr = edge.first;   // Extracting neighbor
            int _   = edge.second;  // Ignoring weight

            if (!vis[nbr]) 
                dfs(adj, vis, nbr, st);
        }
        st.push(src); // for toposort
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {

        // STEP 1
        vector<pair<int, int>> adj[N];
        for (const auto& edge : edges) {
            int src = edge[0],
                nbr = edge[1],
                wt  = edge[2];

            adj[src].emplace_back(nbr, wt); // don't use {} for inserting pairs
          //adj[src].push_back({nbr, wt});
        }

        // STEP 2:  Performing DFS to get nodes in topological order
        stack<int> st;
        vector<int> vis(N);
        for (int i = 0; i < N; ++i) 
            if (!vis[i]) 
                dfs(adj, vis, i, st);

        
        // STEP 3
        vector<int> dist(N, INT_MAX); // Initializing distances to INT_MAX

        dist[0] = 0; // Source node's distance is ALWAYS 0 TO ITSELF ofcourse

        // Calculating shortest paths using topological order
        while (!st.empty()) {

            int src = st.top(); 
            st.pop();

            // src -> nbr
            // if we don't know the distance of src from 0, 
            // then how can we use it't distance 
            // i.e. INT_MAX for calculating distance of nbr from 0

            if (dist[src] == INT_MAX) continue; // Ignore unreachable nodes

            for (const auto& edge : adj[src]) {
                int nbr   = edge.first;
                int wt    = edge.second;
                dist[nbr] = min(dist[nbr], dist[src] + wt);
            }
        }

        // STEP 4: Handling unreachable nodes
        for (int& d : dist) 
            if (d == INT_MAX) 
                d = -1;
    

        return dist;
    }
};


/** APPROACH 2 : SLIGH MODIFICATION OF APPROACT - 1
KEEP ON REMOVING THE STACK'S TOP ELEMENT UNTIL THE ORIGINAL SOURCE IS ON THE TOP
Because I want the distance to be calculated from the Original Source node
Not from the topmost element of the stack
*/

class Solution {
private:
    // Simple DFS to populate the stack with nodes in topological order
    void dfs(vector<pair<int, int>> adj[], vector<int>& vis, int src, stack<int>& st) {
        vis[src] = 1;
        for (const auto& edge : adj[src]) {
            int nbr = edge.first; // Extracting neighbor
            int _ = edge.second; // Ignoring weight
            if (!vis[nbr]) dfs(adj, vis, nbr, st);
        }
        st.push(src);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {

        int original_source = 0; // assuming the original source is 0

        vector<pair<int, int>> adj[N];
        for (const auto& edge : edges) {
            int src = edge[0], nbr = edge[1], wt = edge[2];
            adj[src].push_back({nbr, wt});
        }

        stack<int> st;
        vector<int> vis(N);
        for (int i = 0; i < N; ++i) 
            if (!vis[i])    
                dfs(adj, vis, i, st);
        

        vector<int> dist(N, INT_MAX);
        dist[original_source] = 0; // Source node's distance is 0
        

        while (st.top() != original_source) 
            st.pop();

        // Calculating shortest paths using "topological order -- stack"
        while (!st.empty()) {

            int src = st.top(); 
            st.pop();

            // if (dist[src] == INT_MAX) continue; // Ignore unreachable nodes

            for (const auto& edge : adj[src]) {
                int nbr   = edge.first;
                int wt    = edge.second;
                dist[nbr] = min(dist[nbr], dist[src] + wt);
            }
        }

        // Handling unreachable nodes
        for (int& d : dist) 
            if (d == INT_MAX) 
                d = -1;
        

        return dist;
    }
};