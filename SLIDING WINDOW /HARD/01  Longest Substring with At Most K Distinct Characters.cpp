// LEETCODE PREMIUM

/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
 */

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> charCount;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.length(); ++right) {
        // Increment count of current character in the window
        charCount[s[right]]++;

        // Shrink the window if the number of distinct characters exceeds K
        while (charCount.size() > k) {
            // Decrement count of character at left pointer and remove if count becomes zero
            charCount[s[left]]--;

            if (charCount[s[left]] == 0) 
                charCount.erase(s[left]);
            
            // Move the left pointer to the right
            left++;
        }

        // Update the maximum length if needed
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}


