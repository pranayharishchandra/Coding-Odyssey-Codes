/* https://leetcode.com/problems/rearrange-array-elements-by-sign/ */

#include <vector>
using namespace std;

class Solution {
public:
    // TC: O(n) single traversal, SC:O(n) for newArray
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveIndex = 0;
        int negativeIndex = 1;
        std::vector<int> newArray(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            // + and 0
            if (nums[i] >= 0) {
                newArray[positiveIndex] = nums[i];
                positiveIndex += 2;
            } 
            // -
            else {
                newArray[negativeIndex] = nums[i];
                negativeIndex += 2;
            }
        }

        return newArray;
    }
};