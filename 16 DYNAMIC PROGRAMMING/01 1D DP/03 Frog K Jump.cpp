#include <vector>
using namespace std;

/** Prev question
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);

    int jumpTwo = INT_MAX;
    if(ind>=2)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}
*/

/*
*============= memoization =================
* Time Complexity: O(N * K)
Reason: The overlapping subproblems will return the answer in constant time. 
Therefore the total number of new subproblems we solve is ‘n’. 
At every new subproblem, we are running another loop for K times. 
Hence total time complexity is O(N * K).

* Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). 
Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/

int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {

    // * STEP 1: BASE CASE: energy req to go from 0th stair/height to 0th stari/height
    if (ind == 0) return 0; 

    // * STEP 2:
    if (dp[ind] != -1) return dp[ind];

    int subAns = INT_MAX;

    //* STEP 3: FORMULA: frog will do jump of min size 1 and max size k
    for (int j = 1; j <= k; j++) {
      //* j -> jump size
        int jump = INT_MAX;
        if (ind - j >= 0) {
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
        }
        subAns = min(jump, subAns);
    }
    return dp[ind] = subAns;
}

int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1);
    return solveUtil(n - 1, height, dp, k);
}

/**============= Tabulation =================
Time Complexity: O(N*K)
Reason: We are running two nested loops, where outer loops run from 1 to n-1 and the inner loop runs from 1 to K

Space Complexity: O(N)
Reason: We are using an external array of size ‘n’.
*/

int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {
    // * STEP 1: BASE CASE
    dp[0] = 0;

    // * "ind" will be decreasing in memo, here "ind" or "i" will be increasing 
    // overall tc - O(n*k)
    for (int i = 1; i < n; i++) { // O(n)
      
        int subAns = INT_MAX;
        for (int j = 1; j <= k; j++) { // O(k)
          int jump = INT_MAX;
            if (i - j >= 0) {
                jump = dp[i - j] + abs(height[i] - height[i - j]);
            }
            subAns = min(jump, subAns);
        }
        dp[i] = subAns;

    }
    return dp[n - 1];
}

int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1);
    return solveUtil(n, height, dp, k);
}


// * space opt can't be done because: (height[i - j]) "i-j" value is not fixed, and will be maximum "n"... 