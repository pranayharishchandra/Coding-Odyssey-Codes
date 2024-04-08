
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// fastest solution 
class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int newcolor, int oldcolor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || 
            image[sr][sc] != oldcolor || ans[sr][sc] == newcolor)
              return;

        ans[sr][sc] = newcolor;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrow[i];
            
            int ncol = sc + delcol[i];
            dfs(nrow, ncol, ans, image, newcolor, oldcolor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        if (image[sr][sc] == newcolor)
            return image;

        vector<vector<int>> ans = image;
        int oldcolor = image[sr][sc];
        dfs(sr, sc, ans, image, newcolor, oldcolor);
        return ans;
    }
};

// BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        if (image[sr][sc] == newcolor)
            return image;

        int m = image.size();
        int n = image[0].size();
        int oldcolor = image[sr][sc];
        
        vector<vector<int>> ans = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            ans[r][c] = newcolor;
            
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                    && image[nrow][ncol] == oldcolor && ans[nrow][ncol] != newcolor) {
                      q.push({nrow, ncol});
                }
            }
        }
        
        return ans;
    }
};
