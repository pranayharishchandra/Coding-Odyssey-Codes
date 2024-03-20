#include <vector>
#include <string>
using namespace std;


/** BRUTE : checking all the pairs
Time Complexity: O(N2), where N = size of the array.
Reason: There are two loops(i.e. nested) 
each running for approximately N times.

Space Complexity: O(1) as we are not using any extra space.
 */
vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}

/** OPTIMAL : using hashmap
Time Complexity: O(N), where N = size of the array.
Reason: The loop runs N times in the worst case and searching 
in a hashmap takes O(1) generally. So the time complexity is O(N).

Note: In the worst case(which rarely happens), 
the unordered_map takes O(N) to find an element. 
In that case, the time complexity will be O(N2). 
If we use map instead of unordered_map, 
the time complexity will be O(N* logN) as the 
map data structure takes logN time to find an element.

Space Complexity: O(N) as we use the map data structure.

Note: We have optimized this problem enough. But if in the interview,
 we are not allowed to use the map data structure, 
 then we should move on to the following approach i.e. two pointer approach. 
 This approach will have the same time complexity as the better approach.
 */
vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

/** OPTIMAL : 2 pointer
Time Complexity: O(N) + O(N*logN), where N = size of the array.
Reason: The loop will run at most N times. 
And sorting the array will take N*logN time complexity.

Space Complexity: O(1) as we are not using any extra space.
 */
vector<int> twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return {arr[left], arr[right]};
        }
        else if (sum < target) left++;
        else right--;
    }
    return { -1, -1};
}