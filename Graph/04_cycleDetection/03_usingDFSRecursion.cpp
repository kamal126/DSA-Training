#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool cycleDetect(int node, int parent, vector<vector<int>>&adjList, vector<bool>&visited){

    visited[node] = 1;

    for(int i=0;i<adjList[node].size();i++){
        int neighbor = adjList[node][i];

        if(parent == neighbor) continue;

        if(visited[neighbor]) return 1;

        cycleDetect(neighbor, node, adjList, visited);

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

    vector<bool>visited(adjList.size(), 0);

    return cycleDetect(0,-1,adjList,visited);

}