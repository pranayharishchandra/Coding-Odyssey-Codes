#include <vector>
using namespace std;

//* EXACTLY PREVIOUS QUESTION
//* https://leetcode.com/problems/partition-equal-subset-sum/description/
//* HARD QEUSTION -- LEAVE THIS FOR NOW

/*
=====================: TABULATION :=====================



*/

#include <vector>
#include <algorithm>
#include <numeric> // For accumulate
#include <cmath>   // For abs

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate total sum

        int N = n / 2; // Divide into two equal parts
        vector<vector<int>> left(N + 1), right(N + 1); // Left and right arrays

        // Generate all possible sums in left and right parts using bit masking
        for (int mask = 0; mask < (1 << N); ++mask) {
            int idx = __builtin_popcount(mask); // Count set bits
            int lSum = 0, rSum = 0;
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) {
                    lSum += nums[i];
                    rSum += nums[i + N];
                }
            }
            left[idx].push_back(lSum);
            right[idx].push_back(rSum);
        }

        for (int idx = 0; idx <= N; ++idx) {
            sort(right[idx].begin(), right[idx].end()); // Sort right part for binary search
        }

        int res = abs(totalSum - 2 * left[N][0]); // Initialize minimum difference

        // Iterate over left part
        for (int idx = 1; idx < N; ++idx) {
            for (int a : left[idx]) {
                int b = (totalSum - 2 * a) / 2; // Calculate target sum for right part
                int rightIdx = N - idx;
                auto& v = right[rightIdx];
                auto it = lower_bound(v.begin(), v.end(), b); // Binary search

                if (it != v.end()) {
                    res = min(res, abs(totalSum - 2 * (a + (*it)))); // Update minimum difference if needed
                }
            }
        }

        return res;
    }
};
