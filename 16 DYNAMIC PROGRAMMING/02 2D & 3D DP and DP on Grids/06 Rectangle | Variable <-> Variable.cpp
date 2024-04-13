/*
  * APPROACH: no uniformity - can't use greedy, have to find all paths - using recursion - overlapping sub-problems - DYNAMIC PROGRAMMING

*/

/*============================================================================================================
    Variable Starting and Ending Points | DP on Grids

    max path sum if we end at (n-1, 0) is "p"
    max path sum if we end at (n-1, 1) is "q"
    .
    .
    .
    .
    max path sum if we end at (n-1, m-1) is "t"

    now take the max of "p, q, ..... t" and that will be your answer
    
============================================================================================================*/

/*============================================================================================================
    so here we will start from the (n-1, j)th col and will go till all the columns of the top row
    and then we will have the base case in the top row
    then will backtrack down again after hitting the base case and this is how we will get our answer

    so one src and "m" destinations
    we will do this "m" times
============================================================================================================*/



/*
*============================================================================================================
    SOLUTION 1 - MEMOIZATION - (stupid function call) - TLE in leetcode
    
  * TC: O(nxm), but actually it's much more than nxm because :
 
 *> Recursion Overhead: Recursive function calls incur overhead due to function call stack management. For large input matrices, the number of recursive calls can grow exponentially, leading to a significant performance hit.

 
 *> Suboptimal Memoization: Although you're using memoization to avoid redundant calculations, the memoization table may not be filled optimally. Depending on the input matrix, there might be a large number of subproblems, and not all of them need to be computed. If the memoization table is not efficiently filled, it can still result in a high time complexity.

 
 *> Complexity of the Problem: The problem of finding the minimum falling path sum is inherently complex, especially when solved recursively. Even with memoization, the time complexity can still be high, leading to TLE errors for large inputs.
============================================================================================================*/

#include <vector>
using namespace std;

class Solution {
    int getMinUtil(int i, int j, int m, vector<vector<int>> &matrix, 
                        vector<vector<int>> &dp) {
        if (j < 0 || j >= m)
            return 1e9;
    
        if (i == 0)
            return matrix[0][j];
    
        if (dp[i][j] != -1)
            return dp[i][j];
    
        int up            = getMinUtil(i - 1,     j, m, matrix, dp);
        int leftDiagonal  = getMinUtil(i - 1, j - 1, m, matrix, dp);
        int rightDiagonal = getMinUtil(i - 1, j + 1, m, matrix, dp);
    
        return dp[i][j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector<vector<int>> dp(n, vector<int>(m, -1));
    
        int mini = INT_MAX;
    
        for (int j = 0; j < m; j++) {
            int ans = getMinUtil(n - 1, j, m, matrix, dp);
            mini = min(mini, ans);
        }
    
        return mini;
    }
};



/*============================================================================================================
    SOLUTION 2 - MEMOIZATION - (smart function call) - TLE in leetcode

    -- one src and "m" destinations
    -- then taking the best answer by iterting over the all 'm' srcs
============================================================================================================*/

class Solution {
    int getMinUtil(int i, int j, int m, vector<vector<int>> &matrix, 
                        vector<vector<int>> &dp) {
        // if (j < 0 || j >= m)
        //     return 1e9;
    
        //* BASE CASE: "DESTINATION"
        if (i == 0)
            return matrix[0][j];
    
        if (dp[i][j] != -1)
            return dp[i][j];
    
        int up            =              getMinUtil(i - 1, j,     m, matrix, dp);
        int leftDiagonal  = (j-1 >= 0) ? getMinUtil(i - 1, j - 1, m, matrix, dp) : 1e9;
        int rightDiagonal = (j+1 <  m) ? getMinUtil(i - 1, j + 1, m, matrix, dp) : 1e9;
    
        return dp[i][j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector<vector<int>> dp(n, vector<int>(m, -1));
    
        int mini = INT_MAX;
    
        //* CALLING FROM EACH "SOURCE"
        for (int j = 0; j < m; j++) {
            int ans = getMinUtil(n - 1, j, m, matrix, dp);
            mini = min(mini, ans);
        }
    
        return mini;
    }
};



/*============================================================================================================
    SOLUTION 3 - TABULATION - (using solution - 2) --  (space optimised) -- see SOLUTION 6
============================================================================================================*/

class Solution {
int getMinUtil(int sc, int n, int m, vector<vector<int>> &matrix) {

    vector<int> prev(m, INT_MAX);

    // sc -> src col
    // top to bottom -- src to dest


    //* in the [dp array i.e. prev], only for the "SOURCE COLUMN" i wrote matrix[0][sc] and in the rest of the sources let it be INT_MAX or invalid, 
    //* i am making each col "source column" one by one, since this solution is "TABULATION of above Memoization"
    //* YOU OBSERVE THAT WE ARE MAKING EACH COL THE "SRC COL" ONE BY ONE... WE COULD MAKE ALL OF THEM THE VALID "SRC COL" AT ONCE BY NOT LEAVING THEM AS "INT_MAX".. see the immediate next solution
    prev[sc] = matrix[0][sc];

    for (int i = 1; i < n; i++) {
        vector<int> curr(m);
        for (int j = 0; j < m; j++) {

            int up            = prev[j];
            int leftDiagonal  = (j-1 >= 0) ? prev[j-1] : INT_MAX;
            int rightDiagonal = (j+1 <  m) ? prev[j+1] : INT_MAX;

            int minOfAll = min(up, min(leftDiagonal, rightDiagonal));

            if (minOfAll != INT_MAX)
                curr[j] = matrix[i][j] + minOfAll;
            else 
                curr[j] = INT_MAX;
        }
        prev = curr;
    }

    //* VARIABLE DESTINATION - CHECKING WHICH DESTINATION IS MINIUM
    int mini = prev[0];
    for (int j = 1; j < m; j++)
        mini = min(prev[j], mini);

    return mini;
    
}

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int mini = INT_MAX;

        for (int j = 0; j < m; j++) {
            int ans = getMinUtil(j, n, m, matrix);
            mini = min(mini, ans);
        }

        return mini;
    }
};


/*============================================================================================================
    SOLUTION 4 - TABULATION (space optimised) -- see SOLUTION 3
============================================================================================================*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        
        vector<int> prev(m, INT_MAX);

        // sc -> src col
        // top to bottom -- src to dest

        //* VARIABLE SOURCE -- filling all cells means "ALL ARE VALID or (!= INT_MAX) SRC" -- NO NEED OF CALLILNG THE FUNCTION EACH TIME FOR EVERY SOURCE
        for (int j = 0; j < m; j++)
            prev[j] = matrix[0][j];

        // prev[sc] = matrix[0][sc];

        for (int i = 1; i < n; i++) {
            vector<int> curr(m);
            for (int j = 0; j < m; j++) {

                int up            = prev[j];
                int leftDiagonal  = (j-1 >= 0) ? prev[j-1] : INT_MAX;
                int rightDiagonal = (j+1 <  m) ? prev[j+1] : INT_MAX;

                int minOfAll = min(up, min(leftDiagonal, rightDiagonal));

                if (minOfAll != INT_MAX)
                    curr[j] = matrix[i][j] + minOfAll;
                else 
                    curr[j] = INT_MAX;
            }
            prev = curr;
        }

        //* VARIABLE DESTINATION - CHECKING WHICH DESTINATION IS MINIUM
        int mini = prev[0];
        for (int j = 1; j < m; j++)
            mini = min(prev[j], mini);

        return mini;
        
        return mini;
    }
};