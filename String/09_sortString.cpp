#include<bits/stdc++.h>
using namespace std;

string sort(string s) {
    // complete the function here
    vector<int>alpha(26,0);
    
    for(char ch :s){
        alpha[ch-'a']++;
    }
    
    string ans = "";
    for(int i=0;i<26;i++){
        while(alpha[i]!=0){
            ans += 'a' + i;
            alpha[i]--;
        }
    }
    
    return ans;
}