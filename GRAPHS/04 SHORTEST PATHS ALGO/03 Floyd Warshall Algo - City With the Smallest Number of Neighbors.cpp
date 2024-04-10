/** REFERENCES:
 * VIDEO: QUESTION: https://youtu.be/PwMVNSJ5SLI?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&t=58
 * 

*/

/* APPROACHES:
* 1.DIJKSTRA'S ALGO:
you can also solve this using dijksta's algo (dist from 1 src to V-1 nodes) for all V nodes
* 2. BELLMAN FORD ALGO:
multi src algo
we have used it in here

* 

*/

#include <vector>
#include <set>
#include <queue> 
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {

        vector<vector<int>> matrix(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i==j)
                    matrix[i][j]=0; //* distance a node to itself should be 0 and self loops should be avoided


        //* making the matrix with avalible knowledge of graph
        //* the matrix only have info of distance between "DIRECTLY CONNECTED EDGES"
        for(auto it:edges){
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }

        //* now after we have the matrix with smallest distance after using 
        //* "FLOYD WARSHALL algo" we are finding the city as per given condition
        int ans=INT_MAX,num=0;
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j]<=dT){
                    tmp++;
                }
            }
            if(tmp<=ans){
                ans=tmp;
                num=max(num,i);
            }
        }
        return num;
    }
};