/**https://leetcode.com/problems/set-matrix-zeroes/description/*/

//* My article link https://leetcode.com/problems/set-matrix-zeroes/solutions/5196573/4-approaches/
#include <vector>
using namespace std;

// TC: (nxm + nxm), SC: O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // if we have to mark entire col to zero
        // in that case we will store 1 in the row, col

        // Traverse the matrix:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // mark ith index of row wih 1:
                    row[i] = 1;

                    // mark jth index of col wih 1:
                    col[j] = 1;
                }
            }
        }

        // Finally, mark all (i, j) as 0
        // if row[i] or col[j] is marked with 1.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};