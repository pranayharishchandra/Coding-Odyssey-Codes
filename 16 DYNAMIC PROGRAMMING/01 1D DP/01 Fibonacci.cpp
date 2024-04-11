#include <vector>

using namespace std;

/*
*============= memoization =================
*Time Complexity: O(N)
Reason: The overlapping subproblems will return the answer in constant time O(1). 
Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).

*Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). 
Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/

int f(int n, vector<int>& dp){

    //* Step 1: Base Case
    if(n<=1) return n;
    
    //* Step 2: memoization to avoid recomputing the result
    if(dp[n]!= -1) return dp[n];

    //* Step 3: Formula & Store & Return
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}


/*
*============= Tabulation =================
* Time Complexity: O(N)
Reason: We are running a simple iterative loop

* Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
*/

int f(int n){
  vector<int> dp(n+1,-1);
  
  //* Step1: Base Cases
  dp[0]= 0;
  dp[1]= 1;
  
  //* Step 2: Going after the base case i.e. "1" till the end i.e "n"
  for(int i=2; i<=n; i++){
      //* Step 3: Formula
      dp[i] = dp[i-1]+ dp[i-2];
  }
  return dp[n];
}



/* 
* ============= Tabulation (space opt )=================
* INUTUION: 
>dp[i-1]+ dp[i-2], only (prev) and (prev to prev) result being used, then why making "n+1" size array
if we just need to tell the fibonacci of only 1 value (i.e. "n")

> because our dp array will store the results for each subproblem from 0 to n.

* Time Complexity: O(N)
Reason: We are running a simple iterative loop

* Space Complexity: O(1)
Reason: we are using only 2 extra variables to solve this problem
*/
int f(int n){

  vector<int> dp(n+1,-1);
  
  int prev2 = 0; //prev to prev
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int curr = prev2 + prev;
      prev2    = prev;
      prev     = curr;
  }

  return prev;
}  