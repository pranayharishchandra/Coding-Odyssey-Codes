// https://leetcode.com/problems/binary-subarrays-with-sum/description/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*SOLUTION 1 - USING HASHMAP
this pproach provided will work for arrays with any elements, 
not just arrays containing 0s and 1s.
*/
int numSubarraysWithSum(vector<int>& nums, int sum) {
    int count = 0;
    int prefixSum = 0;
    unordered_map<int, int> um;

    // Initialize prefix sum with 0 count
    um[0] = 1;

    for (int num : nums) {
        // Calculate prefix sum
        prefixSum += num;

        int remove = prefixSum - sum;
        // Count the number of subarrays with the current prefix sum
        // EQUATION: remove + k = curr_prefix_sum
        if (um.find(remove) != um.end()) 
            count += um[remove];
        
        // Increment the count of the current prefix sum
        um[prefixSum]++;
    }

    return count;
}



/*SOLUTION 2 - SLIDING WINDOW
sliding window approach provided will work for arrays with any elements, 
not just arrays containing 0s and 1s.
*/


/** BEFORE ATTEMPTING THIS PROBLEM, MAKE SURE YOU SEE THE SOLUTION OF : 
    ===> {01 Length, count subarray with sum <=k}
*/
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int left1 = 0, left2 = 0, right = 0;
    int sum1 = 0,  sum2 = 0;
    int count = 0;

    for (int right = 0; right < n; right++) {

        // Update sum1 and sum2
        sum1 += nums[right];
        sum2 += nums[right];

        // Finding the respective sum (sum1 and sum2) <= goal
        // like we did in "01 Length, count subarray with sum <=k" 
        /**
            while (sum > k) {
                sum -= nums[left];
                ++left;
            }
        */
        while (left1 <= right && sum1 >= goal + 1) {
            sum1 -= nums[left1];
            left1++;
        }
        
        while (left2 <= right && sum2 >= goal) {
            sum2 -= nums[left2];
            left2++;
        }

        // number of subarrys with "sum <= GOAL" formula : count += right - left + 1;
        int cnt1 = right - left1 + 1; // no. of subarrays with sum <= goal + 1
        int cnt2 = right - left2 + 1; // no. of subarrays with sum <= goal 

        // Update count
        count += cnt1 - cnt2; // no. of subarrays with sum exactly equals to goal

        // count += left2 - left1; // or you may dirctly use this formula
    }

    return count;
}

/**
   |||||||||||  goal + 1
 - ||||||||||   goal
   -------------------------
             |  exact goal
   ------------------------- 
 */
