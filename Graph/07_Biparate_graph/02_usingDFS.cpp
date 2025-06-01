#include<iostream>
#include<queue>
using namespace std;

class Solution {
  public:
        
        bool DFS(int node, vector<vector<int>>&adj, vector<int>&color){

            for(int neighbor : adj[node]){
                // agar node not assign color till now
                if(color[neighbor]==-1){
                    color[neighbor] = (color[neighbor]+1)%2;
                    if(DFS(neighbor, adj, color))
                        return false;
                }
                // node alredy assign color than check not is same same
                else if(color[node] == color[neighbor]){
                    return false;
                }
            }


            return true;
        }

        bool isBipartite(int V, vector<vector<int>> &edges) {
            // Code here
            vector<vector<int>>adj(V);
            for(auto& edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            
            vector<int>color(V,-1);
            
            for(int i=0;i<V;i++){
                if(color[i]==-1){
                    if(DFS(i,adj,color)) return false;
                }
            return true;
        }
    }
};