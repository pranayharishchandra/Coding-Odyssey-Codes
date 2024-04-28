//* https://leetcode.com/problems/merge-intervals/description/

#include <vector>
#include <algorithm>
using namespace std;

/** GOOD FOR READ ABLITY.. LEARN HOW WE EXTRACED THEM IN VARIABLES - a,b,c,d - 
 *refer the below code for logic*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        vector<int> curr = intervals[0];

        // first pair of a,b
        // second pair of c,d 
        // { {a,b}, {c,d} }

        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {
            //* GOOD CODE READABILITY
            int a = curr[0];
            int b = curr[1];
            int c = intervals[i][0];
            int d = intervals[i][1];

            if (b >= c) {
                // continue or extend the same intervel
                int maxi = max(b,d);
                curr[1] = maxi;
            }
            else {
                // add prev intervel to ans and make new intervel
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};

/** MY / BETTER LOGIC THAN ABOVE */
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1)
        return intervals;

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    output.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (output.back()[1] >= intervals[i][0])
            output.back()[1] = max(output.back()[1], intervals[i][1]);
        else
            output.push_back(intervals[i]);
    }
    return output;
}


// * SOLUTION - 2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (output.back()[1] >= intervals[i][0])
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            else
                output.push_back(intervals[i]);
        }
        return output;
    }

};