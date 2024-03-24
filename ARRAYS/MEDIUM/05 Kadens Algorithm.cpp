#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& arr) {

        if (arr.size() == 0) return 0;

        int n = arr.size();
        int ans = INT_MIN;
        int curr = 0;

        int start = 0;
        int end = 0;
        int temp_start = 0;

        for (int i = 0; i < n; i++)
        {
            // mark temp_start only when we are starting a new subarray
            if (curr == 0) 
                temp_start = i;
            
            // finding sum of subarray
            curr += arr[i];

            // if our subarray is better than what we had, 
            // then update permanent start and stop
            if (curr > ans) {
                start = temp_start;
                end = i;
                ans = curr;
            }

            // if sum going negative then better not include it OR 0
            if (curr <= 0)
                curr = 0;
        }

        cout << start << endl << end << endl;

        // return 0 if you will allowed to include empty subarray
        // return (ans > 0) ? ans : 0;

        return ans;
        // return {start, end};
    }
};