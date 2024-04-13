// https://leetcode.com/problems/unique-paths-ii/description/

//* exactly prev question, just obstacles (1) added

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {

        int n = matrix[0].size();
        int m = matrix.size();
            
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                //* BASE CASE 1: wirte this base case 1st otherwise you get OP: 1 for IP:[[1]]                
                if (matrix[i][j] == 1) {
                    prev[j] = 0;
                    continue;
                }

                //* BASE CASE 2: If you write this base case on top then [[1]] will give wrong answer 1 but it should be 0
                if (i == 0 && j == 0) {
                    prev[j] = 1;
                    continue;
                }

                int up   = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j];

                if (j > 0)
                    left = prev[j - 1];

                prev[j] = up + left;
            }

        }
        return prev[n - 1];
    }
};