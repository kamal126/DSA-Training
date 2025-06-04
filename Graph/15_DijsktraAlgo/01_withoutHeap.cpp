#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // 1. create adj list 
        vector<pair<int,int>>adj[V];
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        
        // 2. create a explored and distance(src->dest) array
        vector<bool>explored(V,0);
        vector<int>dist(V,INT_MAX);
        
        // 3. dist of src to src is 0
        dist[src]=0;
        
        // 6. reapeat same work all vertex
        int count = V;
        while(count--){
        //4.find minimum distance and explored mark 1
        int node = -1, wt = INT_MAX;
        for(int i=0;i<V;i++){
            if(!explored[i] && dist[i]<wt){
                node = i;
                wt = dist[i];
            }
        }
        explored[node] = 1;
        
        // 5. explore or visit node's neighbours
        for(int j=0;j<adj[node].size();j++){
            int neighbour = adj[node][j].first;
            int wt = adj[node][j].second;
            // a. check not explored neighbor alredy then dist[node] + wt < dist[neighbour] then dist[neghbour] = dist[node]+wt
            if(!explored[neighbour] && dist[node]+wt < dist[neighbour]){
                dist[neighbour] = dist[node]+wt;
            }
        }// end for 
        }// end while loop
        
        return dist;
        
    }
};