// https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include <iostream>
#include <vector>

using namespace std;

/** EXAMPLES

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/
int longestOnes(vector<int>& A, int K) {
    int maxLength = 0;
    int left = 0;
    int zeroCount = 0;

    for (int right = 0; right < A.size(); ++right) {
        if (A[right] == 0) 
            zeroCount++;
        

        // Shrink the window until the number of zeros
        // within the window is less than or equal to K
        while (zeroCount > K) {
            if (A[left] == 0) 
                zeroCount--;
            
            left++;
        }

        // Update the maximum length if needed
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}


