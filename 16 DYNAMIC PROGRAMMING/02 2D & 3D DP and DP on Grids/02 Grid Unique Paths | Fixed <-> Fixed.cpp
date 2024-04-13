/*
* QUESTION:LINK: https://leetcode.com/problems/unique-paths/description/

* (0,0) to (n-1, m-1)
* f(p,q) means that it will have the best answer for (0,0) to (p,q)
* overlapping sub problems -> dp
*/

/* SOLUTION - 1
 *  RECURIVE SOLUTION
 * TIME COMPLEXITY: O(2^(nxm)), 2 is because we can go 2 directions from each node/cell i.e. (right and down)
 * TIME COMPLEXITY is "exponential" in recursion

 * SPACE COMPLEXITY: O(path length) ~ O(n + m) - recursion call stack
 
 * APPROACH: 
    we have to go from (0,0) to (n-1,m-1) to reach there we can go - (right and down),
    *> since recursion is top-down, hence we will start from the bigger problem (n-1, m-1) and move towards (0,0) and we will (left and up)

    *> why (left and up)? just reverse the direction of arrows eg: 
    * ( ---> ) will be reversed to ( <--- )
    
 */


/*
 * ================MEMOIZATION================: 
 * TIME COMPLEXITY: O(NXM), because
 * we will find answer of each subproblem ONLY ONCE
 * (there are total nxm subproblems in a matrix of size nxm)  
 * 
 * SPACE COMPLEXITY: O(n-1 + m-1) + O(nxm), path length + dp
 * */


#include <vector>
using namespace std;

class Solution {
public:
    int countWaysUtil(int i, int j, vector<vector<int>>& dp) {

        if (i == 0 && j == 0) //* only 1 way to go from (0,0) to (0,0)
            return 1;

        // if (i < 0 || j < 0)   //* out of boundary, invalid, no way
        //     return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = 0, left = 0;

        //* Calculate the number of ways by moving up and left recursively.
        if (i >= 1)
            up = countWaysUtil(i - 1, j, dp);
        if (j >= 1)
            left = countWaysUtil(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countWaysUtil(m - 1, n - 1, dp);
    }
};

/* 
* :================:TABULATION:================:
* Time Complexity: O(M*N)
Reason: There are two nested loops

* Space Complexity: O(M*N)
Reason: We are using an external array of size ‘M*N’.

* APPROACH: 
we can do row wise(inside column wise) or column wise (inside it row wise) traversal   
it doesn't matter   
*/

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n

int countWaysUtil(int m, int n, vector<vector<int>>& dp) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //* Base condition
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    // The result is stored in the bottom-right cell (m-1, n-1).
    return dp[m - 1][n - 1];
}




int countWays(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countWaysUtil(m, n, dp);
}



/* 
* :================:TABULATION (space opt):================:
* Time Complexity: O(M*N)
Reason: There are two nested loops

* Space Complexity: O(N)
Reason: We are using an external array of size ‘N’ to store only one row.


* THOUGHT PROCEESS:
first i thought that if my curr (i,j) cell depends on (i, j-1) and (i-1, j) 
so may be i can use 2 vectors, one to store "prevRow" and second to store "prevCol" 
so space complexity would be O(n+m)

*> but after doing dry run i realised we just need prevRow to get (i-1,j) value and (i,j-1) value would have been just updated , so new SC: O(n)
*/

class Solution {
public:
        int uniquePaths(int m, int n) {
            
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    prev[j] = 1;
                    continue;
                }

                int up   = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j];

                if (j > 0)
                    left = prev[j - 1];

                prev[j] = up + left;
            }

        }
        return prev[n - 1];
    }
};