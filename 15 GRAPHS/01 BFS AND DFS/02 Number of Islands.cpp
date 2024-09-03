// https://leetcode.com/problems/number-of-islands/
// 2D matrix. Each "1" represents a land cell, and each "0" represents a water cell. 
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// USING DFS - no visited matrix
class Solution {
    void DFS(vector<vector<char>>& grid, int i, int j) {
        // boundary checking
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        // return if current position is of water or is already visited
        // '2' -> visited,             '0' water
        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
        
        // mark the current as visited
        grid[i][j] = '2';
        
        //2. visit all nbr
        // do DFS in all 4 directions - tldr
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i-1, j);
        DFS(grid, i, j+1);
    }    

public:
    
    int numIslands(vector<vector<char>>& grid) {
        // We can treat the matrix grid as a grid. Each Island is a
        // connected component. The task is to find no. of disconnectedd components
        // in the graph.
        
        int islands = 0;
        // We make each 1 as 2 in when it is visited
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // do DFS in case ('1' -> unvisited) and there is land
                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    ++islands;
                } 
            }
        }
        return islands;
    }
};

/** NOTE: IF U WERE ASKED TO GO "8" DIRECTIONS THEN USE i: -1 to 1 and j: -1 to 1*/
// using BFS
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void BFS(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});

        // Mark the current cell as visited
        grid[i][j] = '2';

        // Define directions for exploration:   top,   down,    left,    right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            // Explore all four directions
            for (auto dir : directions) { 
                int x = curr.first  + dir.first;
                int y = curr.second + dir.second;

                // Boundary and validity checks
                if (x >= 0 && x < grid.size() && y >= 0 &&
                        y < grid[0].size() && grid[x][y] == '1') {

                    grid[x][y] = '2';
                    q.push({x, y});

                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    BFS(grid, i, j);
                    ++islands;
                }
            }
        }
        return islands;
    }
};
/**Time Complexity:
 BFS: For each cell in the grid, BFS explores its neighboring cells, which takes constant time. 
Since there are m * n cells in the grid, the time complexity of BFS is O(m * n).
numIslands Function: The numIslands function iterates over all cells in the grid. For each cell,
it calls BFS, which takes O(m * n) time. Therefore, the overall time complexity is O(m * n).


Space Complexity:
BFS: The space complexity of BFS primarily depends on the maximum size of the queue. In the worst case,
if all land cells are connected and need to be explored, the queue can contain all these cells. 
Therefore, the space complexity of BFS is O(m * n).
numIslands Function: Apart from the input grid, the space complexity is dominated by the queue used in BFS,
which is O(m * n).*/