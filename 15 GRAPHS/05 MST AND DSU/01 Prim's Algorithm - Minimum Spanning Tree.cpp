/** REFERENCES:
 * VIDEO: DRYRUN: https://youtu.be/mJcZjjKzeqk?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=131
 * ARTICLE: https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/
 */


#include <vector>
#include <set>
#include <queue> 
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), 
 where E = no. of given edges.
 * > The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a "POP" operation that will take "logE" time. This will result in the "first O(E*logE)" time complexity. 
 
 * > Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a "PUSH" operation and for that, we need a "logE" time complexity. So this will result in the "second O(E*logE)." 



 * Space Complexity: O(E) + O(V), 
 where E = no. of edges and V = no. of vertices. 
 O(E) occurs due to the size of the priority queue and O(V) due to the visited array. 
 > If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.

 * Intuition:
The intuition of this algorithm is the greedy technique used for every node. 
If we carefully observe, for every node, we are greedily selecting its unvisited adjacent node 
with the minimum edge weight(as the priority queue here is a min-heap and the topmost element is the node with the minimum edge weight). Doing so for every node, we can get the sum of all the edge weights of the minimum spanning tree and the spanning tree itself(if we wish to) as well.

 * APPROACH:
We are greedly making the MST because we konw that we have to connect all the nodes 
such that V nodes having Spanning Tree have V-1 Edges.

We are at some node initally .. now we will choose the node with minium weight 
> we will keep on checking the min weight having edge in the priority queue and will use it to 
construct the MST, because we want the overall sum of the tree to be minium

> so unlike previous BFS questions where we were marking visited in the beginning 
and when we add in the q or set or pq

> here we will make a node visited only when we will add all it's nbrs into the pq, so we can compare the edge to be taken on the basis of it's weight from it's parent

> If we encounter a same node again whose all the nbrs we have already added in the pq, we will ignore that node ofcourse

 * using visited not distance matrix (like dijksta) because :
 we are not concerned about the distance, we are concenrnd about the edge weight between two nodes that we already know... 

 */


class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        // (min heap) Priority queue to store "EDGES" in ascending order of weights
        priority_queue<pair<int, int>, 
                      vector<pair<int, int>>, 
                      greater<pair<int, int>>> pq;
        
        // Vector to mark "visited nodes"
        vector<int> vis(V, 0);

        // Push the first node (node 0) with weight 0 to start the traversal
        pq.push({0, 0});
        
        // Initialize sum to store the total weight of the MST
        int sum = 0;

        // Loop until the priority queue is empty
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            // If the node is already visited, skip it
            if (vis[node] == 1) continue;

            // Mark the current node as visited and add its weight to the sum
            vis[node] = 1;
            sum += wt;

            // Explore the adjacent nodes of the current node
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];

                // If the adjacent node is not visited, push it to the priority queue
                if (!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }
        // Return the total weight of the MST
        return sum;
    }
};

// * QUESTION 2 - CONSTRUCTING A MST
class Solution
{
public:
    vector<pair<int,int>> spanningTree(int V, vector<vector<int>> adj[])
    {

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        vector<int> vis(V,0);

        pq.push({0,{0,-1}});
        // vis[0] = 1; // don't do it here

        bool flag = false;         // * using it to ignore the first pair into MST i.e. (parent, src) (0, -1)
        int   sum = 0;
        vector<pair<int,int>> MST; // {{parent,src}}
        
        // time complexity of this loop --> E x log E
        while (pq.size() > 0) // O(E) // E edges will be inserted into it in worst case
        {
            auto it = pq.top(); // O(log E)
            pq.pop();

            int wt     = it.first;
            int src    = it.second.first;
            int parent = it.second.second;

            if (vis[src] == 1) continue;     // if already visited
            else               vis[src] = 1; // mark it as visited

            sum += wt;
            if (flag == false) { // * first time it was a dummy node, that we should not add, so to ignore that I have used fla
                flag = true;
            }
            else {
                MST.push_back({parent,src});
            }

            // time complexity of this loop --> E x log E
            for (auto ed : adj[src])             // max E edges can be possibe of a node
            {
                int nbr  = ed[0];
                int edwt = ed[1];
            
                pq.push({edwt, {nbr, src}}); // O(log E) // {edwt, {src, parent}}    
            }
        }

        // for (auto it : MST) cout << it.first << " " << it.second << endl;
        return MST;
    }
};



/*
 * NOTE 1: 1ST OCCURANCE OF A NODE TOP OF PQ ONLY HAS SIGNIFICANCE.
 * you may push a node (let's say node1) more than once but whenever the node1 will be on the top of the pq
 * then it will always be the node1 with the min distance/weight on the top of pq
 * after it all the node1 with wt2,or may be wt3 and so on will be always more than w1
 * so I CAN SAY THAT ONLY THE 1ST TIME I GOT NODE1 HAS SIGNIFICANCE AND OTHER EDGES OF NODE1 DON'T HAVE ANY SIGNIFICANCE
 * AND THE ARE JUST WASTE AND ARE IGNORED BY OUR PROGRAM becuase of the condtions we use ... 
 * more distance than previously got... IGNORE
 * here, already visited previously ... IGNORE
 
 * and to save one of such useless iteration(s) we use set and erase them in DIJKSTRA'S ALGO.
 */

/*
 * NOTE 2: CAN'T USE QUEUE
 * UNLIKE DIJKSTRA'S ALGO WE CAN'T SOLVE THIS PROBLEM ALSO USING QUEUE
 * because we only want the 1st and smallest wt having edge from the nbr.
 * then you will get sum more than or equal to the min sum... since your program is acutally not considering the smallest wt edge... so this point was obvious.
 */

/*
 * NOTE 3: 
 * use parent when you are asked to construct the MST -- in this question they haven't asked to us to create it
 * but to write code of both construct and sum in once prog. I have used it.
 */