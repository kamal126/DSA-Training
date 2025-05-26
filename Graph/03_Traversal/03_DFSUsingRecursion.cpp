#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(int node, vector<vector<int>>&adjList, vector<bool>&visited, vector<int>&ans){
    
    visited[node] = 1;
    ans.push_back(node);

    for(int j=0;j<adjList[node].size();j++){
        int neighbor = adjList[node][j];

        if(!visited[neighbor]){
            DFS(neighbor, adjList, visited, ans);
        }
    }
    

}

void print(vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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
    vector<bool>visited(adjList.size(), 0);

    DFS(0,adjList,visited, ans);

    print(ans);

    return 0;
}