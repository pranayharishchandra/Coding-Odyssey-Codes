// https://leetcode.com/problems/rotting-oranges/description/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/* NOTE: why  queue< pair <pair<int,int>, int >> rotten; is very fast 
and 
queue< vector<int>> rotten; is very slow

ANSWER

The performance difference between using `queue<pair<pair<int,int>, int>>` and 
`queue<vector<int>>` can be attributed to several factors:

1. Memory Allocation Overhead: `vector<int>` typically involves dynamic memory allocation and 
deallocation, whereas `pair<pair<int,int>, int>` is often implemented using stack allocation, which can be more efficient. This difference in memory allocation can contribute to performance discrepancies.

2. Memory Access Patterns: Accessing elements within a `vector<int>` involves additional indirection compared to accessing elements within a `pair<pair<int,int>, int>>`. This additional indirection can result in slower memory access times, especially if the vector grows large.

3. Data Contiguity: Elements within a `vector<int>` may not be contiguous in memory, especially after resizing operations, which can lead to poor cache performance due to cache misses. On the other hand, elements within a `pair<pair<int,int>, int>>` are typically contiguous in memory, resulting in better cache locality and 
potentially faster access times.

4. Size and 
Overhead: Each element in a `vector<int>` has more overhead compared to each element in a `pair<pair<int,int>, int>>`. The additional overhead in `vector<int>` can lead to increased memory usage and 
slower performance, especially when dealing with large numbers of elements.

5. Copying Overhead: `pair<pair<int,int>, int>` may involve less copying overhead compared to `vector<int>`, especially when passing elements between functions or pushing elements onto the queue. This reduced copying overhead can contribute to faster performance.

Overall, while `vector<int>` provides more flexibility and 
convenience in terms of data manipulation, it may incur additional overhead compared to `pair<pair<int,int>, int>>` in certain scenarios, leading to differences in performance. The choice between them depends on the specific requirements of your application and 
the trade-offs between memory usage, flexibility, and 
performance.
*/

// solution - 1
class Solution {
public:
int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int m    = grid.size(),
            n    = grid[0].size(),
            days = 0,
            tot  = 0,
            cnt  = 0; 

        queue< pair <pair<int,int>, int >> rotten;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++; // total oranges to be rottened
                if(grid[i][j] == 2) {      // rottened oranges
                    rotten.push({{i, j}, 0}); // {i,}
                    cnt++;
                } 
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while(rotten.size()){

            int x = rotten.front().first.first, 
                y = rotten.front().first.second;

            int currDay = rotten.front().second;
            days = max(days, currDay);

            rotten.pop(); // remove in the end, silly mistake to write it above
                          // you will not get error but will get wrong answer
                          // i just did this silly mistake

            for(int i = 0; i < 4; ++i){

                int nx = x + dx[i], ny = y + dy[i];
                
                // invalid boundary or already visited
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) 
                    continue;

                grid[nx][ny] = 2; // marking visited or "not 1" or 2
                rotten.push({{nx, ny}, currDay + 1});
                cnt++;
            }
        }
        
        
        return tot == cnt ? days : -1;
    }
};

// solution - 2 - without storing the day the orange rottened
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        if (grid.empty()) return 0;

        // Get the dimensions of the grid
        int m    = grid.size(),
            n    = grid[0].size(),
            days = 0,
            tot  = 0,
            cnt  = 0;

        // Create a queue to store coordinates of rotten oranges
        queue<pair<int, int>> rotten;
        
        // Iterate through the grid to count total oranges and push rotten oranges into the queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) tot++;  // Count total oranges
                if (grid[i][j] == 2) rotten.push({i, j});  // Push rotten oranges into the queue
            }
        }
        
        // Define "4" directions for neighboring cells - tldr
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while (!rotten.empty()) {

            int k = rotten.size();
            cnt += k;   // Increment count of processed oranges
            // days++;  // wrong output, input: grid: [[2,0]] expected: 0 output: 1

            // Perform BFS until all rotten oranges have been processed
            // we are only rottening k oranges because we
            while (k--) {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();

                // Check all four neighboring cells
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], 
                        ny = y + dy[i];

                    // Check boundary and  whether the cell contains fresh orange
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;

                    // Mark the fresh orange as rotten and push it into the queue
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            // If there are still rotten oranges in the queue, increment the number of days
            if (!rotten.empty()) days++;
        }
        
        // If all oranges have been processed, return the number of days
        // If there are still fresh oranges left, return -1 indicating impossibility
        return tot == cnt ? days : -1;
    }
};

// solution - 3 -- using 2 queues 
// 1st queue to store oranges rottened on nth day
// 2nd queue to store oranges rottened on (n+1)th day
// pepcoding -- level order traversal