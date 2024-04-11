// https://leetcode.com/problems/longest-repeating-character-replacement/description/

/* QUESTION 
You are given a string s and an integer k. You can choose any character of 
the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can 
get after performing the above operations.


Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.


Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/* THOUGHT PROCESS
-> SUBSTING (contions part of the string)=> sliding window

-> just be concerned about the majority times occuring element
because that only can give you most optimal replacement, 

-> sometimes you may think that "A" character is in majority but is not actually contious 
and the gap is more than k (max replacements we can do)
    but you will observe that the characters that are coming in between "A" were actually once 
*/

// https://leetcode.com/problems/longest-repeating-character-replacement/description/

/** RUN THE CODE FOR FOLLOWING INPUT and observe the output
INPUT
s = "AABBBAAACCCC"
k = 0

Stdout
s[right] : A, maxCount : 1
s[right] : A, maxCount : 2
s[right] : B, maxCount : 2
s[right] : B, maxCount : 2
s[right] : B, maxCount : 3
s[right] : A, maxCount : 3 <- this 3 is because of the 3 B above, s[A] has become 0 in the prev teation
s[right] : A, maxCount : 3
s[right] : A, maxCount : 3
s[right] : C, maxCount : 3
s[right] : C, maxCount : 3
s[right] : C, maxCount : 3
s[right] : C, maxCount : 4
 */

// maxCount is used to keep track of the maximum count of MAJORITY character 
// within the current window. This variable is crucial for determining if we can 
// still perform replacements within the window without violating the constraint 
// of making at most k replacements.



class Solution {
public:

int characterReplacement(string s, int k) {
    int n = s.size();
    int maxLength = 0;
    int left = 0;
    int maxCount = 0;
    unordered_map<char, int> um;

    for (int right = 0; right < n; ++right) {
        
        um[s[right]]++;
        // Update the maximum count of any character in the current window
        maxCount = max(maxCount, um[s[right]]);
        
        cout << "s[right] : " << s[right] << ", maxCount : " << maxCount << endl;

        // If the length of the window minus the maximum count exceeds k,
        // shrink the window from the left

        while (int changes = right - left + 1 - maxCount > k) {
            // Decrement the count of the character at the left pointer
            um[s[left]]--;
        
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}
};


