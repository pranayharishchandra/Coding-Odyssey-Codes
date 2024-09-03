// https://leetcode.com/problems/is-graph-bipartite/description/

/*
* Bipertitie graph: 
alternate nodes should have different colors
and we should be able to color the graph with only 2 color
 */
#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

/*
* APPROACH 2 (code not written) 
color
    0: unvisited
    1: color1
    2: color2

vector<int> color (graph.size(), 0)
color[node] = color[parent] == 2 ? 1 : 2
*/

/* USING BFS 
* Approach
Since we need to color the node with some color lets say (-1), 
its neighbouring node cannot have color (-1) so we color them with (1) and so on.
If we encounter any node that we already colored and its same as its neighbour
then we return false else return true.
*/

class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, 
                       vector<int>& color, vector<int>& vis) {

        queue<int> q;
        q.push(node);
        vis[node] = 1;
        color[node] = 1;

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            for (int adjNode : graph[curr]) {
                if (!vis[adjNode]) {
                    color[adjNode] = -color[curr]; // MARKING OTHER NODE WITH DIFFERENT COLOR, BY CHANGING THE SIGN, 1 TO -1 AND -1 TO 1
                    vis[adjNode] = 1;
                    q.push(adjNode);
                } 
                else if (color[adjNode] == color[curr]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Initial color of all nodes
        vector<int> vis(n, 0);    // Visited array

        for (int i = 0; i < n; ++i) {
            if (!vis[i] && !bfs(i, graph, color, vis)) {
                return false; // If any component is not bipartite, return false
            }
        }

        return true;
    }
};


/** USING DFS */
class Solution {
private:
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = c;
        
        for (int neighbor : graph[node]) {
            if (color[neighbor] == 0) {
                if (!dfs(neighbor, -c, graph, color)) return false; // return the result
            } 
            else if (color[neighbor] == color[node]) { // if not same, don't need to further calls
                return false;
            }
        }
        
        return true; // keep checking
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0 && !dfs(i, 1, graph, color)) return false;
        }
        
        return true;
    }
};