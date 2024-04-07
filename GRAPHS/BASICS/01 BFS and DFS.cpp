#include <vector>
#include <queue>
using namespace std;

/**
Time Complexity: For a directed graph,    O(N) + O(E), 
                 FOR UNDIRECTED GRAPH,    O(N) + O(2E),
Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

Space Complexity: O(3N) ~ O(N), 
Space for queue data structure visited array and an adjacency list
 */
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        queue<int> q;

        vis[0] = 1; 
        q.push(0); 

        vector<int> bfs; 

        while(!q.empty()) { // O(N) - total nodes
           // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 

            // traverse for all its UNVISITED neighbours - mark dthem visited and add in q
            for(auto it : adj[node]) { // O(2E) - total degrees
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};

/*D ==================== DFS ==================== */
/*
Time Complexity: For an undirected graph, O(N) + O(2E), 
                 For a directed graph,    O(N) + O(E), 
  Because for every node we are calling the recursive function once, 
  the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.

Space Complexity: O(2N) + O(E) [adj list] ~ O(N), Space for dfs "stack space" for recursion call, 
visiteod array and an adjacency list.
*/

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        // create a list to store dfs
        

        // call dfs for starting node
        vector<int> ls; 
        int start = 0;
        dfs(start, adj, vis, ls); // assuming only one component in graph 
                                 // othewise travel over all nodes
        return ls;
    }
};


