// https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*SOLUTION 1 - USING HASHMAP*/
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

/*SOLUTION 2 - SLIDING WINDOW*/
int numSubarraysWithSum(vector<int>& nums, int sum) {
    int n = nums.size();
    int left1 = 0, left2 = 0, right = 0;
    int sum1 = 0,  sum2 = 0;
    int count = 0;

    for (int right = 0; right < n; right++) {

        // Update sum1 and sum2
        sum1 += nums[right];
        sum2 += nums[right];

        // Move left pointers while sum1 or sum2 exceeds sum
        while (left1 <= right && sum1 > sum) {
            sum1 -= nums[left1];
            left1++;
        }
        
        while (left2 <= right && sum2 >= sum) {
            sum2 -= nums[left2];
            left2++;
        }

        // Update count
        count += left2 - left1;
    }

    return count;
}
