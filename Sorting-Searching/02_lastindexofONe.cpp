#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lastIndex(string s) {
        int n=s.size()-1;
        
        for(int i=n; i>=0; i--){
            if(s[i]=='1') return i;
        }
        return -1;
    }
};