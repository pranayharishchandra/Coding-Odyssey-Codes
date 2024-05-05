// Rotate matrix by 90 degree
// https://leetcode.com/problems/rotate-image/description/
#include <vector>
#include <iostream>
using namespace std;

/** Approach - 1 
TC : O(nxn) : traversing over whole matrix
SC : O(nxn) : extra matrix
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = rotated;
    }
};

/** Approach - 2
Time Complexity: O(N*N) + O(N*N).
One O(N*N) is for transposing the matrix 
and the other is for reversing the matrix.

Space Complexity: O(1).
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transposing the matrix
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < i; j++) 
                swap(matrix[i][j], matrix[j][i]);
        
        // reversing each row of the matrix
        for (int i = 0; i < n; i++) 
            reverse(matrix[i].begin(), matrix[i].end());
    }
};