// https://leetcode.com/problems/surrounded-regions/description/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
*        *** INTUTION: ***
* "Y" are immune to infection
* since we are changing the same matrix, we don't need "visited" matrix
* "O" in the boundary or connected to the boundry "O" will only become immune i.e. "Y"

 */

/* using BFS */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        // BFS queue
        queue<pair<int, int>> bfsQueue;
        
        // Enqueue 'O's on the border
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O')     bfsQueue.push({i, 0});
            if (board[i][n - 1] == 'O') bfsQueue.push({i, n - 1});
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O')     bfsQueue.push({0, j});
            if (board[m - 1][j] == 'O') bfsQueue.push({m - 1, j});
        }

                
        // Define directions for traversal: up, down, left, right
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        // Perform BFS
        while (!bfsQueue.empty()) {
            auto [x, y] = bfsQueue.front();
            bfsQueue.pop();
            board[x][y] = 'Y'; // Mark as visited
            
            // Check four directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + dirs[i];
                int newY = y + dirs[i + 1];
                
                if (newX >= 0 && newX < m && newY >= 0 
                    && newY < n && board[newX][newY] == 'O') {
                      bfsQueue.push({newX, newY});
                }
            }
        }
        
        // Mark surrounded 'O's as 'X' and restore marked 'Y's to 'O's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};


/* DFS */
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
        
        board[i][j] = 'Y'; // Mark as visited
        
        dfs(board, i + 1, j); // Check down
        dfs(board, i - 1, j); // Check up
        dfs(board, i, j + 1); // Check right
        dfs(board, i, j - 1); // Check left
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        // Check borders for 'O's and perform DFS
        // 1st and last row
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        
        // 1st and last column
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        
        // Mark surrounded 'O's as 'X' and restore 'Y's to 'O's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};


//* APPROACH - 2
/*
we can create a new matrix named ans

and we will initialize everything with 'X'
visited means: board cell is O and ans cell is O
unvisited means: board cell is O and ans cell is X
and we don't care when board cell is X

and so just by using 2 matrices

ans matrix (returning as answrer)
and board
we can keep track of visited 
 */