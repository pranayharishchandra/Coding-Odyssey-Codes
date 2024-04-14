#include <vector>
using namespace std;


/*

*   ===================================:  RECURSION  :========================================
 * Time Complexity: O(2^N), because we have 2 choices, either pick or not pick

* Space Complexity: O(N), stack space



*   ===================================: MEMOIZATION :========================================
 * Time Complexity: O(N*K), on both the parameters N,K results are changing
Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

* Space Complexity: O(N*K) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).
 */

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    //* If the target sum is 0, we have found a subset
    if (target == 0)
        return true;

    //* If we have reached the first element in 'arr'
    if (ind == 0)
        return arr[0] == target;

    // If the result for this subproblem has already been computed, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Try not taking the current element into the subset
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    //* Try taking the current element into the subset if it doesn't exceed the target
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the dp array to avoid recomputation
    return dp[ind][target] = notTaken || taken;
}

bool subsetSumToK(int n, int k, vector<int>& arr) {

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);
}


/*
*   ===================================: TABULATION :========================================
* Time Complexity: O(N*K)
Reason: There are two nested loops

* Space Complexity: O(N*K)
Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.
 */

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    //* Base case: if (target == 0) return true
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    //* Fill the DP array iteratively 
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[ind - 1][target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

/*
*   ===================================: TABULATION (space opt):========================================
* Time Complexity: O(N*K)
Reason: There are two nested loops

* Space Complexity: O(N*K)
Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.
 */


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a vector 'prev' to store the previous row of the DP table
    vector<bool> prev(k + 1, false);

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++) {
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            // Store the result in the current DP table row for the current subproblem
            cur[target] = notTaken || taken;
        }

        // Update 'prev' with the current row 'cur' for the next iteration
        prev = cur;
    }

    // The final result is stored in prev[k]
    return prev[k];
}
