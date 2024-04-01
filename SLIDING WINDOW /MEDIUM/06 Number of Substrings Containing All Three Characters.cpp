// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int countSubstringsContainingAllThreeChars(string s) {
    unordered_map<char, int> um;
    int count = 0;
    int left  = 0;

    for (int right = 0; right < s.length(); ++right) {
        // Increment the count of the current character in the window
        um[s[right]]++;

        // Shrink the window from the left until all three characters are present
        while (um['a'] > 0 && um['b'] > 0 && um['c'] > 0) {
            // Increment the count by the length of the remaining substring
            count += s.length() - right;

            // Decrement the count of the character at the left pointer
            um[s[left]]--;

            // Move the left pointer to the right
            left++;
        }
    }

    return count;
}
