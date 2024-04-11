// https://leetcode.com/problems/number-of-provinces/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// WHITHOUT USING MATRIX
/*NOTE : The codes should work correctly for both bidirectional and unidirectional graphs.*/
class Solution
{
    // total tc: O(nxn)
    int n, vis[201] = {0};
    void dfs(vector<vector<int>> &matrix, int src, int &c) {
        int row = src;
        vis[row] = true;
        c++;
        // O(n)
        // go to the unvisited nbr of row
        for (int col = 0; col < n; col++)
            if (!vis[col] && matrix[row][col])
                dfs(matrix, col, c);
    }

public:
    int findCircleNum(vector<vector<int>> &matrix) {
        n = matrix.size();
        int res = 0, c = 0;
        // O(n)
        for (int row = 0; row < n; row++) {
            if (!vis[row]) {
                c = 0;
                dfs(matrix, row, c);
                res++;
                cout << "src: " << row << ", nodes in curr components: " << c << "\n";
            }
        }

        return res;
    }
};

// USING ADJ MATRIX
class Solution {
private:
    // dfs traversal function
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[node] = 1;

        // visit nbrs
        for (auto it : adjLs[node]) 
            if (!vis[it]) 
                dfs(it, adjLs, vis);
    }

public:
    int findCircleNum(vector<vector<int>> adj) {
        int V = adj.size();
        vector<int> adjLs[V];

        // to change adjacency matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // self nodes are not considered
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    // adjLs[j].push_back(i); // no need to do, automatically will be done, since matrix is also bidirectional
                }
            }
        }
        // int vis[V] =  {0}; // this may give you error,
        // in leetcode i got error, so write the constraint better i.w. 201

        int vis[201] = {0};
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            // if the node is not visited
            if (!vis[i]) {
                // counter to count the number of provinces
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};
