// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string str) {

        int n = str.size();
        if (n == 0)
            return 0;

        int maxans = 0;
        int left = 0;
        int right = 0; 
        unordered_set <char> us;

        while (right < n) {

            // if you can't able to add right char as it's in HashSet, remove elements from the left
            while (us.find(str[right]) != us.end()) // keep removing until right removed
            {
                us.erase(str[left]);
                left++;
            }
            us.insert(str[right]);
            right++;
            // maxans = max(maxans, right - left);
            maxans = max(maxans, (int)us.size());
        }
        return maxans;
    }
};