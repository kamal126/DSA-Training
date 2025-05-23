#include<iostream>
#include<vector>

using namespace std;

int main(){
    int V,E;
    cout<<"enter no. of vertex: ";
    cin>>V;
    cout<<"\nenter no. of vertex: ";
    cin>>E;

    vector<vector<bool>>AdjMat(V, vector<bool>(V,0));

    cout<<"\n Enter edges like(0 1 means 0 to 1): ";

    int u,v;
    for(int i=0;i<E;i++){
        cin>>u>>v;

        AdjMat[u][v] = 1;
        AdjMat[v][u] = 1;
    }

    // print Adjency Matrix
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }

}