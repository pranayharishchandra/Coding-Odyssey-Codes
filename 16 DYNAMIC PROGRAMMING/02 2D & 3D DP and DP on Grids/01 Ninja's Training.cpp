/*
* QUESTION LINK: https://www.naukri.com/code360/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

* APPROACH: GREEDY will fail, we must explore all the Sub-Answers i.e. recursion optimised using DP (since we have overlapping sub problems)

* index : day, last: (prev day activity)

* Sub-Answers: for each index or day, there are 3 activities, hence 3 sub-answers for every day are possible... but we will choose maxium of the 3 sub-answers and the maxium will be our answer for that Nth day


* 2D dp because: "2 changing parameters on which your sub-answer depends" that are -> "day" as well as "last" activity you performed
*/







/* SOLUTION -1 
*============= memoization =================
* Time Complexity: O(N*4*3)
Reason: There are N*4 states and for every state, we are running a for loop iterating three times.

* Space Complexity: O(N) + O(N*4)
Reason: We are using a recursion stack space(O(N)) and a 2D array (again O(N*4)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/
#include <vector>
#include <iostream>
using namespace std;


int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {

  if (dp[day][last] != -1) return dp[day][last];

  //* STEP 1: Base case: When we reach the first day (day == 0)
  //* f(day, last) => f(0, _ )  
  //* if you did training for only 1 day and you had to collect max points then you would have found out max point activity ofcourse
  // * that is what we are doing here
  if (day == 0) {
    int maxi = 0;

    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }

    // Store the result in dp array and return it
    return dp[day][last] = maxi;
  }


  // * STEP 2: CHECKING EACH ANSWER
  int maxi = 0;
  // Iterate through the activities for the current day
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      //* If we choose to do "i"th activity then it's points for today will be added points[day][i] 
      //* and the recursion will caculate and give use the max points we could collect if we do "i"th activity today
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }

  // Store the result in dp array and return it
  return dp[day][last] = maxi;
}

// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points) {
  // Create a memoization table (dp) to store intermediate results
  vector<vector<int>> dp(n, vector<int>(4, -1));
  // Start the recursive calculation from the last day with no previous activity
  return f(n - 1, 3, points, dp);
}


/* SOLUTION - 2
*============= Tabulation =================
* Time Complexity: O(N*4*3)
Reason: There are three nested loops

* Space Complexity: O(N*4)
Reason: We are using an external array of size ‘N*4’.
*/


int ninjaTraining(int n, vector<vector<int>>& points) {
  // Create a 2D DP (Dynamic Programming) table to store the maximum points
  // dp[i][j] represents the maximum points at day i, considering the last activity as j
  vector<vector<int>> dp(n, vector<int>(4, 0));

  //* STEP1: BASE CASE: Initialize the DP table for the first day (day 0)
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  //* STEP 2: memoization recursion call -- iteratively
  for (int day = 1; day < n; day++) {          // * index i.e. day
    for (int last = 0; last < 4; last++) {     // * condition for each index/day

      dp[day][last] = 0; // we have to collect maxium points so initiallizing with min answer i.e. 0

      //* STEP 3: copy paste body of Memoization code
      for (int task = 0; task <= 2; task++) {
        if (task != last) {

          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);

        }
      }
    }
  }

  // The maximum points for the last day with any activity can be found in dp[n-1][3]
  return dp[n - 1][3];
}

/* SOLUTION - 2
*============= space opt =================
* Time Complexity: O(N*4*3)
Reason: There are three nested loops

* Space Complexity: O(4)
*ARICLE LINK: https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
**/

int ninjaTraining(int n, vector<vector<int>>& points) {
  // Initialize a vector to store the maximum points for the previous day's activities
  vector<int> prev(4, 0);

  // Initialize the DP table for the first day (day 0)
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }
    prev = temp;
  }

  //* for the last day, tasks to be one today is not dependent on the previous day, prev[3] will be storing max(task1, task2, task3)
  return prev[3];
}
