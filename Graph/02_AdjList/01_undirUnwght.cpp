#include<iostream>
#include<vector>

using namespace std;

int main(){
    int V,E;
    cout<<"Enter vertex and edges: ";

    // vector<int>adjList(V);
    cin>>V>>E;
    vector<vector<int>> adjList(V);

    int u,v;

    for(int i=0;i<E;i++){
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since the graph is undirected
    }
    cout<<"Adjacency List Representation of the Graph:\n";
    for(int i=0;i<V;i++){
        cout<<i<<" -> ";
        for(int j=0;j<adjList[i].size();j++){
            cout<<adjList[i][j]<<" ";
        }
        cout<<"\n";
    }
}