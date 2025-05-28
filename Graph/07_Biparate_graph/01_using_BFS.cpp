#include<iostream>
#include<queue>
using namespace std;

class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>color(V,-1);
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                color[i] = 0;
                q.push(i);
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(int neighbor: adj[node]){
                    // not colered to color assign karo
                    if(color[neighbor]==-1){
                        color[neighbor] = (color[node]+1)%2;
                        q.push(neighbor);
                    }
                    // color assign hai check karo same to nahi hai
                    else if(color[node] == color[neighbor]){
                        return 0;
                    }
                }
            }
        }
        
        return true;
    }
};