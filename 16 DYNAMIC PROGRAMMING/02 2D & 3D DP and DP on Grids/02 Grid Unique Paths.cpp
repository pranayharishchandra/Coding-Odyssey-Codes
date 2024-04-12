/*
* QUESTION:LINK: https://www.naukri.com/code360/problems/unique-paths_1081470?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int countWaysUtil(int i, int j, vector<vector<int>>& dp) {

    if (i == 0 && j == 0) //* only 1 way to go from (0,0) to (o,o)
        return 1;

    if (i < 0 || j < 0) //* out of boundary, invalid, no way
        return 0;


    if (dp[i][j] != -1)
        return dp[i][j];

    //* Calculate the number of ways by moving up and left recursively.
    int up   = countWaysUtil(i - 1, j, dp);
    int left = countWaysUtil(i, j - 1, dp);

    // Store the result in the dp table and return it.
    return dp[i][j] = up + left;
}

int countWays(int m, int n) {
    // Create a memoization table (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Call the utility function with the bottom-right cell as the starting point.
    return countWaysUtil(m - 1, n - 1, dp);
}


/* 
* ================:TABULATION:================:
* 

*/

int countWaysUtil(int i, int j, vector<vector<int>>& dp) {
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;

    // If we go out of bounds or reach a blocked cell, there are no ways.
    if (i < 0 || j < 0)
        return 0;

    // If we have already computed the number of ways for this cell, return it.
    if (dp[i][j] != -1)
        return dp[i][j];

    // Calculate the number of ways by moving up and left recursively.
    int up = countWaysUtil(i - 1, j, dp);
    int left = countWaysUtil(i, j - 1, dp);

    // Store the result in the dp table and return it.
    return dp[i][j] = up + left;
}

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n
int countWays(int m, int n) {
    // Create a memoization table (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Call the utility function with the bottom-right cell as the starting point.
    return countWaysUtil(m - 1, n - 1, dp);
}