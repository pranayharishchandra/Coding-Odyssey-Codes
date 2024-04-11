// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

// if you want to know what's "DISTINCT" MEANS ( WITHtime stamp) - https://youtu.be/7zmgQSJghpo?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=104

#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;



/* MY FOLLOWING 1 YEAR OLD SOLUTION HAD ISSUES LIKE 
To improve the given solution, we can make a few optimizations:


Avoid Using Global Arrays for Directions: Instead of passing drow[] 
and dcol[] as arguments to the DFS function, 
we can define them locally within the function.


Use const References Where Possible: We can use const references 
for the grid parameter since it's not modified within the function.


Replace the Use of set with unordered_set: Since ordering is not important
for storing distinct islands, we can use unordered_set for
better performance.


Change pair to Custom Hashable Type: Since pair is not hashable by default,
we can define a custom hash function and use a custom struct instead of pair.


Use Early Returns in countDistinctIslands: We can return early if the 
grid dimensions are invalid or empty, avoiding unnecessary computation.
*/

// why refRow, refCol (with time stamp) - https://youtu.be/7zmgQSJghpo?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=267
class Solution {
private:
    // DFS
    void dfs(int row, int col, 
      vector<vector<int>> &grid, 
      vector<pair<int, int>> &comp, 
      vector<vector<int>> &vis, 
      int drow[], int dcol[], int refRow, int refCol)
    {
        int n = grid.size();
        int m = grid[0].size();

        // mark visited and work(adding into comp)
        vis[row][col] = 1;
        comp.push_back({row - refRow, col - refCol});

        // calling the unvisited nbrs
        for (int i = 0; i < 4; i++)
        {
            int r = row + drow[i];
            int c = col + dcol[i];

            if (r >= 0 && c >= 0 && r < n && c < m)
            {
                // it unvisited then call for the nbr
                // calling unvisited 1
                if (vis[r][c] == -1 && grid[r][c] == 1)
                {
                    dfs(r, c, grid, comp, vis, drow, dcol, refRow, refCol);
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        set<vector<pair<int, int>>> comps; // for storing distnict components
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, -1));
        
        int totalComp = 0; 

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == -1 && grid[i][j] == 1)
                {
                    vector<pair<int, int>> comp;
                    dfs(i, j, grid, comp, vis, drow, dcol, i, j);
                    comps.insert(comp);
                    totalComp++;
                }
            }
        }
        // cout << totalComp << endl;

        return comps.size();
    }
};