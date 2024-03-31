#include <iostream>
#include <vector>

using namespace std;
// total time complexity is O(n + n)

// use the sliding window technique
int longestSubarrayWithSumLessThanOrEqualToK(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLength = 0; 
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];

        // after "expainding" window by adding nums[right], 
        // keep "shrinking" the window until the sum of the window is <= sum
        while (sum > k) {
            sum -= nums[left];
            ++left;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}


