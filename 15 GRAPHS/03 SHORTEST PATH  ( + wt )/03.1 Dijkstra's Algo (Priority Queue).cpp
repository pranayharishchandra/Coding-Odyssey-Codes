#include <vector>
#include <set>
#include <queue> // OR PRIORITY QUEUE
#include <iostream>
#include <algorithm>
// #include <priority_queue> // #include <queue>
using namespace std;

/* 
* NOTE: Dijkstra can be implemented only for + edge weights
* in case of negative weights
* it will fall in an INFINITE LOOP

simple intutuion - we have to "GIVE" something to go somewhere
if I "GET" something for going somewhere then I will keep on going
*/


/**
 * Dijkstra's algorithm works for both directed and undirected graphs. 
 * The same code can be used for both types of graphs without any modification. 
 * The only difference lies in how you construct the adjacency list.
*/



/* 1) Shortest Path in DAG - USING PRIORITY QUEUE (min heap)

-> Time Complexity: O( E log(V) ),   
Where E = Number of edges and V = Number of Nodes.

-> Space Complexity: O( |E| + |V| ), 
Where E = Number of edges and V = Number of Nodes.


*/

class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        int original_src = 0; // assuming the source to be 0 
                              // since source not give -- assume it 0

        // STEP 1:  conver edge into adj list
        vector<pair<int, int>> adj[N];

        for (auto ed : edges)
        {
            int src = ed[0];
            int nbr = ed[1];
            int wt  = ed[2];

            adj[src].push_back({nbr, wt});  // direct graph
         // adj[src].emplace_back(nbr, wt); // direct graph
        }

        // SETP 2: PQ, DIST
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> pq;

        vector<int> dis(N, INT_MAX);

        pq.push({0, original_src}); // pq -> {distance, node}, 
                                    // dist -> min dist found so far till node from original_src
        dis[original_src] = 0;

        // STEP 3: 
        while (pq.size() > 0)
        {
            auto it = pq.top();
            pq.pop();
            
            int wsf = it.first;
            int src = it.second;

            for (auto ed : adj[src])
            {
                int nbr  = ed.first;
                int edwt = ed.second;

                // if you get a better(shorter) distance then update
                if (dis[nbr] > wsf + edwt)
                {
                    dis[nbr] = wsf + edwt;
                    pq.push({dis[nbr], nbr});
                }
            }
        }

        for (int i = 0; i < N; i++)
            if (dis[i] == INT_MAX)
                dis[i] = -1;


        return dis;
    }
};



