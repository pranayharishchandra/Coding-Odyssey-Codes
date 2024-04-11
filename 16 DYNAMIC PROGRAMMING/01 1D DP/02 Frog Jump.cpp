#include <vector>

using namespace std;
/* 
* QUESTION: can only climb 1 or 2 steps at a time 
* question: https://www.naukri.com/code360/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

/*
*============= memoization =================
* Time Complexity: O(N)
Reason: The overlapping subproblems will return the answer in constant time
O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total
time complexity is O(N).

* Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)).
Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/

// * NOTE: we are doing smart function call (ind >= 2) so we don't need extra base case i.e. (ind < 0) return INT_MAX
int solve(int ind, vector<int>& height, vector<int>& dp) {

    // * STEP 1: BASE CASE : energy required to jump from 0th stair/height to (ind)th i.e. 0th stair is 0 (no energy)
    if (ind == 0)
        return 0;

    // if (ind < 0) return INT_MAX; // energy required to go from 0th stair/height to a stair/height that don't exist

    // * STEP 2: return if already computed
    if (dp[ind] != -1)
        return dp[ind];

    // * STEP 3: FORMULA
    int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

    // * just in case doing 2 step jump not possible then jumpTwo should be INT_MAX
    int jumpTwo = INT_MAX;
    if (ind >= 2)
        jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    // * STORE THE SUB-ANSWER AND RETURN 
    return dp[ind] = min(jumpOne, jumpTwo);
}

int f(vector<int> height) {
    int n = height.size();
    vector<int> dp(n, -1);
    solve(n - 1, height, dp);
}

/*
*============= Tabulation =================
* Time Complexity: O(N)
Reason: We are running a simple iterative loop

* Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
*/

int f(vector<int> height) {

    int n = height.size();
    vector<int> dp(n, -1);

    // energy required to go from the stair on which we are to which we are is 0
    dp[0] = 0;

    for (int ind = 1; ind < n; ind++) {

        int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);

        int jumpTwo = INT_MAX;
        if (ind >= 2)
            jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);

        dp[ind] = min(jumpOne, jumpTwo);
    }
    return dp[n - 1];
}

/*
*============= Tabulation (space opt)=================
* Time Complexity: O(N)
Reason: We are running a simple iterative loop

* Space Complexity: O(1)
Reason: We are not using any extra space.
*/

int f(vector<int> height) {
    int n     = height.size();
    int prev  = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++) {

        int jumpOne = prev + abs(height[i] - height[i - 1]);

        int jumpTwo = INT_MAX;
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        int cur_i = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}