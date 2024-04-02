#include <iostream>
#include <vector>

using namespace std;
// total time complexity is O(n + n)

/** 01) length of the longest subarray with sum <= k */
int longestSubarrayWithSumLessThanOrEqualToK(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLength = 0; 
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];

        // after "expainding" window by adding nums[right], 
        // keep "shrinking" the window until the sum of the window is <= sum
        // make the window a valid window by making sure that sum of all the 
        // elements in that window is  "<= k" or "less than or equal to k"
        // as soon as the window becomes valid, stop shrinking, so you get a large window
        while (sum > k) {
            sum -= nums[left];
            ++left;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

/** 2) COUNT NUMBER OF SUBARRAYS WITH SUM <= K */
int countSubarraysWithSumLessThanOrEqualToK(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];

        // make the window a valid window by making sure that sum of all the 
        // elements in that window is  "<= k" or "less than or equal to k"
        while (sum > k) {
            sum -= nums[left];
            ++left;
        }

        // Number of subarrays ending at right index with sum <= k is (right - left + 1)
        count += right - left + 1;
    }

    return count;
}


/** NOTE
MAX LENGTH OF SUBARRAYS WITH SUM K
maxLength = max(maxLength, right - left + 1);

=> COUNTING NUMBER OF SUBARRAYS WITH SUM K
count += right - left + 1;
 */




// BONOUS QUESTION : count Subarrays With Sum >= K
int countSubarraysWithSumGreaterThanOrEqualToK(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 0;
    int count = 0;

    while (right < n) {
        sum += nums[right];

        // Move left pointer while sum is greater than or equal to k
        while (sum >= k) {
            // if my sum of my current subarray is >= k then, 
            // if i add any positive number (i.e. on the right of my current subarray)
            // then my current subarray sum will increase i.e still sum >= k
            // so in the count i am counting my current subarray and the subarrays on right of it
            count += n - right; 
            sum -= nums[left];
            left++;
        }

        right++;
    }

    return count;
}