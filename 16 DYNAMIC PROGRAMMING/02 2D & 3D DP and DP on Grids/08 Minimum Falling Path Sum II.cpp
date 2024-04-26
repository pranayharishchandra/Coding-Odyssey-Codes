// https://leetcode.com/problems/minimum-falling-path-sum-ii/description/?envType=daily-question&envId=2024-04-26

#include <vector>
#include <cmath>
using namespace std;

// SOLUTION - 1, SOLUTION IS HANDELING BASE CASE BETTER IN MY OPENION
// WE CAN DIRECTLY USE SOLUTION 2 FOR TABULATION
class Solution {
public:
    int dp[201][201];

    int f(vector<vector<int>>& arr, int i, int j) {
        if(i == arr.size())
            return 0; // 0 becase there is not value in that cell
                      // if it was max ways then 

        if(dp[i][j] != -1)
            return dp[i][j];

        // if last row then ans should be the current element
        // we want to do this so we can execute this atleast once arr[i][j] + asf
    
        int ans = (i == arr.size() - 1) ? arr[i][j] : INT_MAX;
        for(int k = 0; k < arr[0].size(); k++) {
            if(k == j) continue;
            int asf = f(arr, i + 1, k);
            if (asf != INT_MAX) {
                int curr = arr[i][j] + asf;
                ans = min(ans, curr);
            }
        }
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int ans = INT_MAX;
        memset(dp, -1, sizeof dp);
        for(int j = 0; j < arr[0].size(); j++) {
            ans = min(ans, f(arr, 0, j));
        }
        return ans;
    }
};

/** MEMOIZATION : SOLUTION 2 -- JUST CALLING BASECASE IN A DIFFERENT WAY*/
class Solution {
public:
    int dp[201][201];

    // i -> current row, j -> current col, k -> col of next row
    int f(vector<vector<int>>& arr, int i, int j) {
        // base case - if we are on the last row, return the value of the cell
        if(i == arr.size() - 1) {
            return arr[i][j];
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for(int k = 0; k < arr[0].size(); k++) {
            if(k == j) continue;
            int asf = f(arr, i + 1, k);

            if (asf != INT_MAX) {
                int curr = arr[i][j] + asf;
                ans = min(ans, curr);
            }
        }
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int ans = INT_MAX;
        memset(dp, -1, sizeof dp);

        for(int j = 0; j < arr[0].size(); j++) {
            ans = min(ans, f(arr, 0, j));
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

/*
 * TABULATION
 * TABULATING THE ABOVE SOLUTION - 2
 * ADVICE: always try writing a recursive code in which you don't do stupid calls
 */


#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        // Create a dp table to store minimum falling path sum
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Copy the last row of the grid to dp table as base case
        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = arr[n - 1][j];
        }

        // i, j are the chaning parameters 
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; j++) {

                // -------- copy paste from memoization -------
                int ans = INT_MAX;

                for(int k = 0; k < arr[0].size(); k++) {
                    if(k == j) continue;
                    // int asf = f(arr, i + 1, k);
                    int asf = dp[i+1][k];

                    if (asf != INT_MAX) {
                        int curr = arr[i][j] + asf;
                        ans = min(ans, curr);
                    }
                }
                dp[i][j] = ans;
                // ---------- till here ------------------------
            }
        }

        // Find the minimum falling path sum from the first row
        // many src and many dest// many src and many dest
        int minSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[0][j]);
        }

        return minSum;
    }
};
