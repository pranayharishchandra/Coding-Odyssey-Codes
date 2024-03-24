/**https://leetcode.com/problems/pascals-triangle/description/*/
#include <vector>
using namespace std;
/* 1D DP to solve 
Time Complexity: O(N) approx., where N = size of the array.

Space Complexity: O(N).
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prevRow;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> currentRow(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            }
            
            result.push_back(currentRow);
            prevRow = currentRow;
        }
        
        return result;
    }
};