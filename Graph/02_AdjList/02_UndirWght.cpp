#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

int main(){
    int V,E;
    cout<<"Enter vertex and edges:";
    cin>>V>>E;

    vector<vector<pair<int,int>>>AdjList(V);

    int u,v,w;
    cout<<"\nEnter node1 node2 and weight: ";

    for(int i=0;i<E;i++){
        cin>>u>>v>>w;

        AdjList[u].push_back({v,w});
        AdjList[v].push_back({u,w});
    }


    cout<<"Adjacency List Representation of the Graph:\n";
    for(int i=0;i<V;i++){
        cout<<i<<" -> ";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<"("<<AdjList[i][j].first<<", "<<AdjList[i][j].second<<")";
        }
        cout<<endl;
    }

}