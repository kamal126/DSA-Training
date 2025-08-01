#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        vector<int>alpha(26,0);
        
        for(char ch : s){
            alpha[ch-'a']++;
        }
        
        int maxChar = INT_MIN;
        int idx = -1;
        for(int i=0;i<26;i++){
            if(maxChar < alpha[i]){
                maxChar = alpha[i];
                idx = i;
            }
        }
        
        return 'a'+idx;
    }
};