#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

void Trick () {
    vector<pair<string, int>> v = {{"apple", 3}, {"banana", 1}, {"orange", 5}};

    // Sorting in descending order based on the second element of the pair
    sort(v.begin(), v.end(), [&](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second; 
    });

    // Printing the sorted vector
    for (const auto& p : v) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
}


// https://leetcode.com/problems/relative-ranks/?envType=daily-question&envId=2024-05-08

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank(nums.size());
        
        // Initialize rank vector with indices
        for (int i = 0; i < nums.size(); ++i)
            rank[i] = i;

        // Sort rank in descending order based on nums values
        sort(rank.begin(), rank.end(), [&](int a, int b) { return nums[a] > nums[b]; });
             
        vector<string> ranks(nums.size());

        // Assign ranks
        for (int i = 3; i < nums.size(); ++i) {
            ranks[rank[i]] = to_string(i + 1);
        }

        // Assign medals
        if (!nums.empty()) ranks[rank[0]] = "Gold Medal";
        if (nums.size() > 1) ranks[rank[1]] = "Silver Medal";
        if (nums.size() > 2) ranks[rank[2]] = "Bronze Medal";

        return ranks;
    }
};


