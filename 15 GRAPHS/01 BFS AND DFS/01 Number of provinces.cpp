// https://leetcode.com/problems/number-of-provinces/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// USING MATRIX (V x V or N x N) - (WHITHOUT ADJ list) 
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
        // nbr that are unvisited
        for (int col = 0; col < n; col++)
            if (matrix[row][col] && !vis[col])
                dfs(matrix, col, c);
    }

public:
    int findCircleNum(vector<vector<int>> &matrix) {
        n = matrix.size();
        int res = 0, c = 0;
        // O(n) or O(V)
        for (int row = 0; row < n; row++) { // 'row' or 'src'
            // giving oppotunity to every node to become 'src' if they are unvisited 
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
    void dfs(int src, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[src] = 1;

        // visit nbrs
        for (auto nbr : adjLs[src]) 
            if (!vis[nbr]) 
                dfs(nbr, adjLs, vis);
    }

public:
    int findCircleNum(vector<vector<int>> adj) {
        int V = adj.size();
        vector<int> adjLs[V];

        // to change adjacency matrix to list
        for (int i = 0; i < V; i++) {                // i: node1
            for (int j = 0; j < V; j++) {            // j: node2
                // if link betweeen node1 and node2 exists and it's not "self loop" case i.e. i != j
                if (adj[i][j] == 1 && i != j) {      
                    adjLs[i].push_back(j);
                    // adjLs[j].push_back(i); // no need to do, automatically will be done, since matrix is also bidirectional
                }
            }
        }
        // int vis[V] =  {0}; //! this may give you error,
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
