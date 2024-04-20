
// https://leetcode.com/problems/max-area-of-island/

#include<vector>
using namespace std;

class Solution {
    int AreaOfIsland(vector<vector<int>>& grid, int i, int j){

        // valid block
        if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() 
                                                            && grid[i][j] == 1){
            grid[i][j] = 0;

            // current block and surrounding block
            return 1 + AreaOfIsland(grid, i+1, j) 
                     + AreaOfIsland(grid, i-1, j) 
                     + AreaOfIsland(grid, i, j-1) 
                     + AreaOfIsland(grid, i, j+1);
        }

        // in case of an invalid block or out of boundary, current area of such block is 0
        return 0;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1)
                    max_area = max(max_area, AreaOfIsland(grid, i, j));

        return max_area;
    }
};