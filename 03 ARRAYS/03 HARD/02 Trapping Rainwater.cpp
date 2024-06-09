// https://leetcode.com/problems/trapping-rain-water/solutions/5270570/3-approaches/

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int waterTrapped = 0;

        // Loop through each element in the array
        for (int i = 0; i < n; i++) {
            int leftMax = 0, rightMax = 0;

            // Find the maximum height to the left of the current element
            for (int j = i; j >= 0; j--) {
                leftMax = max(leftMax, arr[j]);
            }

            // Find the maximum height to the right of the current element
            for (int j = i; j < n; j++) {
                rightMax = max(rightMax, arr[j]);
            }

            // Calculate the water trapped at the current element
            waterTrapped += min(leftMax, rightMax) - arr[i];
        }

        return waterTrapped;
    }
};
// Optimal 
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int waterTrapped = 0;
        int maxLeft = 0, maxRight = 0;

        // Traverse the height array from both ends
        while (left <= right) {
            // Process the left side if the left height is less than or equal to
            // the right height
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left]; // Update maxLeft
                } else {
                    waterTrapped +=
                        maxLeft - height[left]; // Calculate trapped water
                }
                left++;
            } else { // Process the right side
                if (height[right] >= maxRight) {
                    maxRight = height[right]; // Update maxRight
                } else {
                    waterTrapped +=
                        maxRight - height[right]; // Calculate trapped water
                }
                right--;
            }
        }
        return waterTrapped;
    }
};