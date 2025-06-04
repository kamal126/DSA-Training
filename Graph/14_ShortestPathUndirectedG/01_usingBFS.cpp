#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = adj.size();
        
        vector<int>dist(V,-1);
        queue<int>q;
        
        dist[src]=0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int j=0;j<adj[node].size();j++){
                int neighbour = adj[node][j];
                if(dist[neighbour]==-1){
                    dist[neighbour] = dist[node]+1;
                    q.push(neighbour);
                }
            }
        }
        

        return dist;
    }
};