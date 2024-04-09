// https://leetcode.com/problems/course-schedule-ii/

/* QUESTION:
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. 
So the correct course order is [0,1].
*/

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

/*Intuition:
The intuition behind this approach is that if there is a cycle in the 
graph, there will be at least one node that cannot be visited since it 
will always have a nonzero indegree. On the other hand, if there are no 
cycles, all the nodes can be visited by starting from the nodes with no 
incoming edges and removing their outgoing edges one by one. If all the 
nodes are visited in the end, it means that it is possible to finish 
all the courses.*/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n); 
        vector<int> indegree(n, 0); 
        vector<int> ans;            

        // Build adjacency list and calculate indegrees
        // the pair [0, 1], indicates that 
        // to take course 0 you have to first take course 1
        // [0,1] means graph: 0 <- 1
        for (const auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);  
            indegree[p[0]]++;          
        }

        // Perform topological sort using Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < n; ++i) 
            if (indegree[i] == 0) 
                q.push(i); // Add courses with indegree 0 to the queue


        // Process courses in the queue and update indegrees
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.emplace_back(curr); 

            // Decrement indegree of adjacent courses
            for (auto next : adj[curr]) 
                if (--indegree[next] == 0) 
                    q.push(next); // Add course to the queue if its indegree becomes 0

        }

        if (ans.size() < n) return {};
        return ans;
    }
};

/*GOOD PRACTICES
some best practices and enhance readability. Here's the optimized version:

Use const References: When iterating over the prerequisites vector,
use const reference to avoid unnecessary copying of the elements.

Use emplace_back() Instead of push_back(): emplace_back() is more
efficient than push_back() when constructing objects in vectors.

Use auto for Container Iterators: Use auto for iterators to simplify
code and improve readability.

Use Range-based for Loop: Use range-based for loop for iterating over
containers whenever possible.

Add Comments: Add comments to clarify the purpose of each section of
the code.
*/