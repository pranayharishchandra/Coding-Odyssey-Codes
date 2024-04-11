/* 
* question : https://leetcode.com/problems/house-robber/
* APPROACH: the constaint you have is: 
* > "you must not rob 2 adjcent houses" 
* >>>> OR it means "you can rob houses with atleast 1 gap" <<<<<<<======
*/

#include <vector>
using namespace std;

/*
*============= memoization =================
* Time Complexity: O(N)
Reason: The overlapping subproblems will return the answer in constant time O(1). 
Therefore the total number of new subproblems we solve is ‘n’.
Hence total time complexity is O(N).

* Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). 
Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/

int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {

    if (dp[ind] != -1)
        return dp[ind];

    // * if there is only 1 house then we must rob that "only" house
    if (ind == 0) 
        return arr[0];

    // *  as per question we must give atleast 1 gap when robbing houses
    // * hence If there were only 2 houses, then we must rob the house which have max money
    if (ind == 1)   
        return max(arr[0], arr[1]);

    // * FORMULA
    // * if i rob current house then i cant rob the next house (since aleast 1 gap have to give), "-2"
    // * if i don't rob current house then i can rob the next house, "-1"
    int pick    = arr[ind] + solveUtil(ind - 2, arr, dp);
    int nonPick = 0        + solveUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

int f(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return solveUtil(n - 1, arr, dp);
}

/*
*============= tabulation =================
* Time Complexity: O(N)
Reason: We are running a simple iterative loop

* Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
*/
class Solution {
public:

    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);

        // * STORING BASE CASE - SUB-ANSWERS
        if (n >= 1) dp[0] = arr[0];
        if (n >= 2) dp[1] = max(arr[1], arr[0]);
    

        for (int ind = 2; ind < n; ind++) {

            int pick    = arr[ind] + dp[ind-2];
            int nonPick = 0        + dp[ind-1];

            dp[ind] = max(pick, nonPick);
        }
        return dp[n-1];
    }
};
/**============= tabulation (space optimaization)=================
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
*/
class Solution {
public:

    int rob(vector<int>& arr) {

        int n = arr.size();
        if (n == 1) return arr[0];
        // vector<int> dp(n, -1);
        int prev2, prev, curr;


        if (n >= 1) prev2 = arr[0];
        if (n >= 2) prev  = max(arr[1], arr[0]);

        for (int ind = 2; ind < n; ind++) {

            int pick    = arr[ind] +  prev2;
            int nonPick = 0        +  prev;

            curr = max(pick, nonPick);

            prev2 = prev;
            prev  = curr;
        }
        return prev;
    }
};



/** VARIANT: HOUSE ROBBER 2*/
//*  making 2 cases so we ensure that we don't include 
//*  0th and (n-1)th index
//*  rest the question is same as previous

class Solution {
public:
    int maxRob(vector<int>& nums, int start , int n , vector<int>& dp ){
        if(n == start) return nums[start];
        if( n < start ) return 0; 
        if( dp[n] != -1 ) return dp[n];

        int pick = nums[n] + maxRob(nums,start, n-2, dp);  
        int notPick = 0 + maxRob(nums,start, n-1, dp); 
        return dp[n] = max(pick, notPick); 
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if( n == 1 ) return nums[0];

        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        
        //*  making 2 cases so we ensure that we don't include 
        //*  0th and (n-1)th index
        //*  rest the question is same as previous

        int case1 = maxRob(nums,0, n-2, dp1); 
        int case2 = maxRob(nums,1, n-1, dp2);  

        return max(case1, case2); 
    }
};