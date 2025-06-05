#include<bits/stdc++.h>
using namespace std;

void findOrder(vector<string> &words, vector<vector<int>>&adj) {
        // code here
        
        for(int i=0;i<words.size()-1;i++){
            string str1=words[i];
            string str2=words[i+1];
            
            int j=0,k=0;
            
            while(j<str1.size() && k<str2.size() && str1[j]==str2[k])
                j++,k++;
                
            // cef
            // cefd
            
            if(j==str1.size())continue;
            
            adj[str1[j]-'a'].push_back(str2[k]-'a');
        }
    }

int main(){
    vector<string>words = {"baa", "abcd", "abca","cab", "cad"};
    vector<vector<int>>adj(26);

    findOrder(words, adj);

    for(int i=0;i<26;i++){
        if(!adj[i].empty()){
            cout<<i<<" -> ";
            for(char ch : adj[i]){
                cout<<ch<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}