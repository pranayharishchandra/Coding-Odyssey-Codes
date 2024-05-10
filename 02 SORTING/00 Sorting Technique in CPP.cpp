#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

void Trick () {
    vector<pair<string, int>> v = {{"apple", 3}, {"banana", 1}, {"orange", 5}};

    //* Sorting in descending order based on the second element of the pair
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
        //* it's like sorting pair of (nums[i], rank[i]) in descending order
        sort(rank.begin(), rank.end(), [&](int a, int b) { return nums[a] > nums[b]; });
             
        vector<string> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int originalIndex = rank[i]; // Get the original index from the sorted rank vector
            int ranking = i + 1; // Get the ranking of the current student
            
            if      (ranking == 1) ans[originalIndex] = "Gold Medal";
            else if (ranking == 2) ans[originalIndex] = "Silver Medal";
            else if (ranking == 3) ans[originalIndex] = "Bronze Medal";
            else                   ans[originalIndex] = to_string(ranking);

            cout << ranking << " ";
        }

        return ans;
    }
};


