//.https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.length(); ++right) {
        char currentChar = s[right];

        // If the current character is already in the set, shrink the window from the left
        while (charSet.find(currentChar) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }

        // Add the current character to the set
        charSet.insert(currentChar);

        // Update the maximum length if needed
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}
