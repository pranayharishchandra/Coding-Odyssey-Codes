/** REFERENCES
 * VIDEO: https://youtu.be/_-0mx0SmYxA?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=920

 * QUESTION: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/solutions/3991740/simple-c-solution/
 */

/* 
* ============ CONSTRAINATS OF THIS QUESTION: ==========

 1 <= n <= 200
 n - 1 <= roads.length <= n * (n - 1) / 2
 roads[i].length == 3
 0 <= ui, vi <= n - 1
*1 <= timei <= 109
*ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.


* ========== CONSTRAINTS OF PREVIOUS QUESTION: ==========
* YOU CAN'T USE "int" and you should use "long long" to calculate distance

* YOU CAN USE "int" for distance in this question
 1 <= n <= 100
 0 <= flights.length <= (n * (n - 1) / 2)
 flights[i].length == 3
 0 <= fromi, toi < n
 fromi != toi
* 1 <= pricei <= 104
 There will not be any multiple flights between two cities.
 0 <= src, dst, k < n
 src != dst


*/

#include <vector>
#include <set>
#include <queue> 
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // STEP 1: Creating an adjacency list for the given graph.
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
           // adj[u].push_back({v, wt})
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        //* STEP2 : Initialize pq, dist, ways, modulo
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Define modulo value
        int mod = (int)(1e9 + 7);

        // Iterate through the graph with the help of priority queue
        //* STEP 4: just as we do in Dijkstra's Algorithm.
        while (!pq.empty())
        {
            // STEP: 4.1
            long long dis = pq.top().first;
            int      node = pq.top().second;
            pq.pop();


            //* Step 4.2: visiting nbr in search of a smaller path to them (to nbr)
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW     = it.second;


                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});


                  //* number of ways in which parent can reach the the nbr from the current node
                  //* in the shortest way, then number of ways to reach the node(parent) will be
                  //* number of ways to reach the nbr(of parent node)
                    ways[adjNode] = ways[node];
                }

                //* if you were already reaching the nbr in some ways 
                //* and now you have explored some more paths to reach nbr 
                //* then  add up those new number of ways 
                //* since all the ways are same distance 
                else if (dis + edW == dist[adjNode])
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;

            }
        }
        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;
    }
};

/*
 *can't use queue because we not just want the min distance but also 
 * is should be of the min distance
 */