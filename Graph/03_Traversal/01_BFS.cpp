#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(int V, vector<vector<int>>&adjList, vector<int>&ans, vector<bool>&visited){
    queue<int>q;
    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int i=0;i<adjList[node].size();i++){
            if(!visited[adjList[node][i]]){
                visited[adjList[node][i]] = 1;
                q.push(adjList[node][i]);
            }
        }
    }
}

int main(){
    vector<vector<int>>adjList;
    adjList.push_back({1,2,3});
    adjList.push_back({0,4});
    adjList.push_back({0,5,7});
    adjList.push_back({0,5,8});
    adjList.push_back({1});
    adjList.push_back({2,3});
    adjList.push_back({});
    adjList.push_back({2});
    adjList.push_back({3});
    vector<int>ans;
    vector<bool>visited(adjList.size(),false);
    BFS(adjList.size(), adjList,ans,visited); 

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}