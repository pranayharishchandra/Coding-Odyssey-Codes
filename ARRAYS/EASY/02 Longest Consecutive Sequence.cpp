/** https://leetcode.com/problems/longest-consecutive-sequence/submissions/1213055976/ */
#include <vector>
using namespace std;
/** Brute Force Approach: Using Array(Three Nested Loop). 

    Time Complexity : O(N^3), The outer loop runs exactly N times, and because currentNumber increments by 1
    during each iteration of the while loop, it runs in O(N) time. Then, on each iteration of the while loop, an
    O(N) operation in the array is performed. Therefore, this brute force algorithm is really three nested O(N)
    loops, which compound multiplicatively to a cubic runtime. Where N is the size of the Array(nums).

    Space Complexity : O(1), Constant space.

    Note : This will give TLE.
*/
class Solution {
private: 
    // searching if element present or not
    bool longestConsecutive(vector<int>& nums, int target){
        int n = nums.size();

        for(int i=0; i<n; i++)
            if(nums[i] == target)
                return true;
            
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int longestConsecutiveSequence = 0;

        for(auto num : nums){
            int currentNumber = num;
            int currentConsecutiveSequence = 1;

            while(longestConsecutive(nums, currentNumber+1)){
                currentNumber += 1;
                currentConsecutiveSequence += 1;
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
        }

        return longestConsecutiveSequence;
    }
};




/*Brute Better Approach.(Solved using Array + Sorting)

    Time Complexity : O(NlogN), The main for loop does constant work N times, so the algorithm's time complexity
    is dominated by the invocation of sorting algorithm, which will run in O(NlogN) time for any sensible
    implementation. Where N is the size of the Array(nums).

    Space Complexity : O(1), For the implementations provided here, the space complexity is constant because we
    sort the input array in place.
*/

// assuming each element occur only once - leetcode
class Solution {
public:
    int longestConsecutive(vector<int>&a) {
        int n = a.size();
        if (n == 0) return 0;

        //sort the array:
        sort(a.begin(), a.end());

        int lastSmaller = INT_MIN;

        int cnt = 0;
        int longest = 1;

        //find longest sequence:
        for (int i = 0; i < n; i++) {

            if (a[i] == lastSmaller + 1) {
                cnt += 1;
                lastSmaller = a[i];
            }
            else if (a[i] != lastSmaller) {
                cnt = 1;
                lastSmaller = a[i];
            }
            longest = max(longest, cnt);
        }
        return longest;

    }
};





/*Optimise Approach.(Solved using Array + Hash Table(Unordered set).)

    Time Complexity : O(N), Although the time complexity appears to be quadratic due to the while loop nested
    within the for loop, closer inspection reveals it to be linear. Because the while loop is reached only when
    marks the beginning of a sequence (i.e. currentNumber-1 is not present in nums), the while loop can only run
    for N iterations throughout the entire runtime of the algorithm. This means that despite looking like O(N^2)
    complexity, the nested loops actually run in O(N+N)=O(N) time. All other computations occur in constant
    time, so the overall runtime is linear. Where N is the size of the Array(nums).

    Space Complexity : O(N), Unordered set space.
*/
#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        
        for(int num : nums)
            set.insert(num);
        
        int longestConsecutiveSequence = 0;

        for(int num : nums){
            if(set.find(num-1) == set.end()){
                int currentNumber = num;
                int currentConsecutiveSequence = 1;

                while(set.find(currentNumber+1) != set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }

        return longestConsecutiveSequence;
    }
};