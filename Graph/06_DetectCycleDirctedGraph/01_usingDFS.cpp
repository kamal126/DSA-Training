#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  
    bool detect(int node, vector<vector<int>>&adj, vector<bool>&path, vector<bool>&visited){
        visited[node] = 1;
        path[node] = 1;
        
        for(int j=0;j<adj[node].size();j++){
            int neighbor = adj[node][j];
            // path mai alredy hai => cycle detect
            if(path[neighbor]) return 1;
            // kya alredy visited hai => skip kar do alredy cycle nahi mili hai
            if(visited[neighbor]) continue;
            // function call karo ab neighbor mai check karo
            if(detect(neighbor, adj,path,visited)) return 1;
        }
        
        // path se bapas aate hue path ko remove karo
        path[node] = 0;
        
        // agar overall cycle nahi mili to
        return 0;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>>adj(V);
        
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        
        
        for(int i=0;i<V;i++)
            if(!visited[i])
                if(detect(i, adj,path,visited))
                    return 1;
            
        
        return 0;
    }
};

int main(){

}