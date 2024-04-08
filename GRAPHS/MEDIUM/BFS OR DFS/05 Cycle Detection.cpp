#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/** USING BFS
* ASSUME A BIDIRECTIONAL GRPAH WITH 2 NODES
Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 
2E is for total degrees as we traverse all adjacent nodes. 
In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
 */
// USING BFS
class Solution {
  private: 
  bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not 
              // it's own parent node, hence cycle
              else if(parent != adjacentNode) 
                  return true; 
              
          }
      }
      // there's no cycle
      return false; 
  }

  public:
    bool isCycle(int V, vector<int> adj[]) {

        int vis[50] = {0}; // int vis[V] = {0}

        for(int i = 0;i<V;i++) 
            if(!vis[i]) 
                if(detect(i, adj, vis)) return true; 

        return false; 
    }
};


/* USING DFS 
Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 
2E is for total degrees as we traverse all adjacent nodes. 
In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.

*/
// USING DFS
class Solution {
  private: 
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // unvisited adjacent node
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != parent) return true; 
        }
        return false; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[50] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
};

/**NOTE: (BFS) QUEUE VS CALL STACK (DFS)

For small input sizes and shallow recursion depths,
using recursion for DFS may be more concise and straightforward.
Recursion utilizes the call stack,
and if the recursion depth is shallow (i.e.,
the number of recursive calls is limited),
the chance of encountering a stack overflow is minimal.


On the other hand,
BFS using a queue typically does not involve recursion 
and relies on an explicit data structure (the queue).
It is often more memory-efficient than recursion and may 
perform better in scenarios where the depth of the search tree or graph is large.


However,
for very deep recursion depths or large problem instances,
using recursion for DFS may lead to stack overflow errors due to the limited size of the call stack.
In such cases,
BFS using a queue would be a safer choice.
*/