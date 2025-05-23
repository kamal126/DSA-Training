#include<iostream>
#include<vector>
using namespace std;

int main(){
    int V, E;
    cout<<"Enter vertex and Edges: ";
    cin>>V>>E;

    vector<vector<int>>adjMat(V, vector<int>(V,0));
    cout<<"\n Enter edges(u v w): ";
    int u,v,w;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;

        adjMat[u][v] = w;
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }

}