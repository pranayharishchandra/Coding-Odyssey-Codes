// https://leetcode.com/problems/trapping-rain-water/solutions/5270570/3-approaches/

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