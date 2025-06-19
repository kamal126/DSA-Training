#include<bits/stdc++.h>
using namespace std;

void DFS(int node,int parent,vector<int>adj[],vector<int>&visited,vector<vector<int>>Bridges,vector<int>&low,vector<int>& disc, int &time){

    disc[node]=low[node]=time;
    visited[node] = 1;

    for(auto& nbr : adj[node]){
        if(nbr==parent) 
            continue;
        else if(!visited[nbr]){
            time++;
            DFS(nbr, node, adj,visited,Bridges, low, disc, time);
            low[node] = min(low[node], low[nbr]);

            if(disc[node]<low[nbr]){
                Bridges.push_back({node, nbr});
            }
        }else{
            low[node] = min(low[node], low[nbr]);
        }
    }
}

vector<vector<int>>criticalConnections(int n, vector<vector<int>>connections){
    
    vector<int>adj[n];
    for(auto& edge : connections){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>visited(n,0);
    vector<vector<int>>Bridges;
    vector<int>low(n,0);
    vector<int>disc(n,0);
    int time = 0;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(i,-1,adj,visited,Bridges, low, disc, time);
        }
    }

    return Bridges;

}