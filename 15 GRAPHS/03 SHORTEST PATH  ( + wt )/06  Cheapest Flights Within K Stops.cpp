// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

/* 
*CONSTRAINATS OF THIS QUESTION:
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


* CONSTRAINTS OF NEXT QUESTION:
* YOU CAN'T USE "int" and you should use "long long" to calculate distance

 1 <= n <= 200
 n - 1 <= roads.length <= n * (n - 1) / 2
 roads[i].length == 3
 0 <= ui, vi <= n - 1
*1 <= timei <= 109
*ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
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
    int findCheapestPrice(int n, vector<vector<int>> &flights,
                       int src, int dst, int K)
    {
        // Create the adjacency list to depict airports and flights in
        // the form of a graph.
        vector<pair<int, int>> adj[n];

        for (auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});


        // Create a queue which stores the node and their distances from the
        //* source in the form of {stops, {node, dist}} with ‘stops’ indicating 
        // the no. of nodes between src and current node.
        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {src, 0}});

        // Distance array to store the updated distances from the source.
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // Iterate through the graph using a queue like in Dijkstra with 
        // popping out the element with min stops first.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node  = it.second.first;
            int cost  = it.second.second;

            //* We stop the process as soon as the limit for the stops reaches.
            if (stops > K)
                break;

            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW     = iter.second;

                int newCost = cost + edW;

                //* If you get better cost withing K stops, update dist
                if (newCost < dist[adjNode])
                {
                    dist[adjNode] = newCost;
                    q.push({stops + 1, {adjNode, newCost}});
                }
            }
        }

        // If the destination node is unreachable within K stops, return ‘-1’
        // else return the calculated dist from src to dst.
        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};

