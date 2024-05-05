#include <vector>
#include <string>
using namespace std;



/** BRUTE : checking all the pairs
Time Complexity: O(N2), where N = size of the array+1.
Reason: In the worst case i.e. if the missing number is N itself, 
the outer loop will run for N times, 
and for every single number the inner loop will also run for approximately N times. 
So, the total time complexity will be O(N2).

Space Complexity: O(1)  as we are not using any extra space.
 */
int missingNumber(vector<int>&a, int N) {

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++) {

        // flag variable to check if (i)th element exists
        int flag = 0;

        // Searching the (i)th element using linear search
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // finding the (i)th element mark flag = 1 to understand it was found
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
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