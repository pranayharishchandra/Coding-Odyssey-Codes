/*
 * QUESTION: LINK: https://leetcode.com/problems/minimum-path-sum/description/

 * PROBLEM STATEMENT: Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path. Note: You can only move either down or right at any point in time.

 * APPROACH: since in the question it's given that all the eleemtns are non-negative, which means that adding any element will not decrease the sum for sure, hence we must addd as many elements, hence we must take the longest path we can make by only going right and down (it's lenght will be ((n-1)+(m-1)) ), 
 *>>>> and since we can only move right and down hence for longest path we must "START: (0,0) AND DESTINATION: (N-1, M-1)"

 * Hence this problem is "FIXED SRC AND FIXED DEST" problem
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 * This question same as prev 2 questions

 * Greedy can't be applied, because no uniformity
 
 */


/*
 * :================: MEMOIZATION :================: 
 * TIME COMPLEXITY: O(NXM), because
we will find answer of each subproblem ONLY ONCE
(there are total nxm subproblems in a matrix of size nxm)  

 * SPACE COMPLEXITY: O(n-1 + m-1) + O(nxm), path length + dp 
 */

#include<vector>
using namespace std;

class Solution { 
public:
    int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

        if (i == 0 && j == 0)
            return matrix[0][0]; 

        // if (i < 0 || j < 0)
        //     // return 1e9; 
        //     return INT_MAX;
            
        if (dp[i][j] != -1)
            return dp[i][j]; 

        int up = INT_MAX, left = INT_MAX;

        if (i >= 1) up   = minSumPathUtil(i - 1, j, matrix, dp);
        if (j >= 1) left = minSumPathUtil(i, j - 1, matrix, dp);


        return dp[i][j] = matrix[i][j] + min(up, left);
    }


    int minPathSum( vector<vector<int>> &matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1)); 
        
        return minSumPathUtil(n - 1, m - 1, matrix, dp); 
    }
};


/*
 * :================: TABULATION :================: 
 * TIME COMPLEXITY: O(NXM), because
we will find answer of each subproblem ONLY ONCE
(there are total nxm subproblems in a matrix of size nxm)  

 * SPACE COMPLEXITY: O(n-1 + m-1) + O(nxm), path length + dp 
 */

class Solution { 
public:
    int minPathSum( vector<vector<int>> &matrix) {

        //* HERE I TOOK n -> cols, m -> rows

        int n = matrix[0].size();
        int m = matrix.size();

        vector<vector<int>> dp(m, vector<int>(n, -1)); 

        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) {
              dp[i][j] = matrix[0][0]; 
              continue;
            }

            int up = INT_MAX, left = INT_MAX;

            if (i >= 1) up   = dp[i-1][j];
            if (j >= 1) left = dp[i][j-1];

            dp[i][j] = matrix[i][j] + min(up, left);

          }
          
        }

        return dp[m-1][n-1];
    }
};



//* SPACE OPT
class Solution { 
public:
    int minPathSum( vector<vector<int>> &matrix) {

        //* HERE I TOOK n -> cols, m -> rows

        int n = matrix[0].size();
        int m = matrix.size();

        // vector<vector<int>> dp(m, vector<int>(n, -1)); 
        vector<int> prev (n);

        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) {
              prev[j] = matrix[0][0]; 
              continue;
            }

            int up = INT_MAX, left = INT_MAX;

            if (i >= 1) up   = prev[j];
            if (j >= 1) left = prev[j-1];

            prev[j] = matrix[i][j] + min(up, left);

          }
          
        }

        return prev[n-1];
    }
};

