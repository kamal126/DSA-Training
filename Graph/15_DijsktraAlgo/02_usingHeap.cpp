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
        // min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            if(explored[node]) continue;
            
            explored[node] = 1;
            
            for(int j=0;j<adj[node].size();j++){
            int neighbour = adj[node][j].first;
            int wt = adj[node][j].second;
            // a. check not explored neighbor alredy then dist[node] + wt < dist[neighbour] then dist[neghbour] = dist[node]+wt
            if(!explored[neighbour] && dist[node]+wt < dist[neighbour]){
                dist[neighbour] = dist[node]+wt;
                
                pq.push({dist[neighbour], neighbour});
            }
        }// end for 
        }
        
        return dist;
    }
};