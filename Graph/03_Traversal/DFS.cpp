#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(int V, vector<vector<int>>&adjList, vector<bool>&visited, vector<int>&ans){
    stack<int>st;
    st.push(0);
    visited[0] = 1;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        ans.push_back(node);

        for(int i=0;i<adjList[node].size();i++){
            int neighbor = adjList[node][i];
            if(!visited[neighbor]){
                visited[neighbor] = 1;
                st.push(neighbor);
            }
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

    DFS(adjList.size(),adjList,visited, ans);

    print(ans);

    return 0;
}