#include<iostream>
#include<vector>
#include<queue>
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
        
        vector<int>InDeg(V,0);
        // find total indegree each node
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                InDeg[adj[i][j]]++;
            }
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(!InDeg[i])
                q.push(i);
        }
        // vector<int>ans;
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            // ans.push_back(node);
            count++;

            for(int neighbor: adj[node]){
                InDeg[neighbor]--;

                if(!InDeg[neighbor])
                    q.push(InDeg[neighbor]);
            }
        }

        // return ans.size()!=V;/
        return count != V; // true cyle detect o/w not present
    }
};

int main(){

}