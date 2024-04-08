// https://leetcode.com/problems/01-matrix/description/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;


/* USING BFS */
class Solution {
private:
    // Checks if the x and y coordinates are within the range of the matrix 
    bool isValidCoordinate(vector<vector<int>>& matrix, int x, int y) {
        return (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size());
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // Initializes the answer matrix with all INT_MAX values
        vector<vector<int>> distances(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        queue<pair<int,int>> q;

        // Finding cells with value 0 and updating their distances to 0
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    distances[i][j] = 0;
                    q.push({i, j}); // Pushing coordinates of 0-value cells into the queue
                }
            }
        }

        // Possible directions to explore: right, down, up, left
        vector<pair<int,int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            // Taking the top-most element in the queue
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Exploring adjacent cells
            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Checks if it is valid to move to newX, newY
                if (isValidCoordinate(matrix, newX, newY)) {
                    // If the new distance is shorter, update the distance 
                    // and push the coordinates into the queue
                    if (distances[newX][newY] > distances[x][y] + 1) {
                        distances[newX][newY] = distances[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return distances;
    }
};


/* COULD NOT FIND ANY OPTIMAL SOLUITON THAT DON'T GIVE 
    TIME LIMIT EXCEEDED
    FOR THIS QUESTION 
    (CHATGPT AND LEETCODE SOLUTIONS)
*/
