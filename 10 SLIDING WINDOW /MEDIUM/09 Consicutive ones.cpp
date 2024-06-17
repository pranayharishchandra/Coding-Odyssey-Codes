class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> zeroIndices;  // Deque to store the indices of zeros
        int start = 0;  // Start pointer of the window
        int maxLength = 0;  // Maximum length of the subarray with at most k zeros

        for (int end = 0; end < nums.size(); ++end) {
            // If the current element is zero, add its index to the deque
            if (nums[end] == 0) {
                zeroIndices.push_back(end);
            }

            // If the zero count exceeds k, adjust the start pointer
            if (zeroIndices.size() > k) {
                start = zeroIndices.front() + 1;  // Move start to the next index after the first zero in the deque
                zeroIndices.pop_front();  // Remove the first zero's index from the deque
            }

            // Update the maximum length
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;  // Return the maximum length
    }
};

