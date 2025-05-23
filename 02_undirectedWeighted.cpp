#include<iostream>
#include<vector>

using namespace std;

int main(){
    int V,E;
    cout<<"Enter vertex and Edges: ";
    cin>>V>>E;

    vector<vector<int>>Adjmat(V, vector<int>(V,0));

    cout<<"\n Enter edges and weight(u v w): ";
    int u,v,w;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;

        Adjmat[u][v]=w;
        Adjmat[v][u]=w;
    }

    cout<<"\n So finally Adjency Matrix here: ";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cout<<Adjmat[i][j]<<" ";
        cout<<endl;
    }
}