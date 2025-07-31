#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void clockwise(string &s){
        int n = s.size();
        
        char ch = s[n-1];
        
        for(int i=n-1; i>0; i--){
            s[i] = s[i-1];
        }
        
        s[0] = ch;
    }
    
    void anticlockwise(string &s){
        int n = s.size();
        
        char ch = s[0];
        
        for(int i=0;i<n-1;i++){
            s[i] = s[i+1];
        }
        
        s[n-1] = ch;
    }
    bool isRotated(string& s1, string& s2) {
        string tmp = s1;
        
        anticlockwise(tmp);
        anticlockwise(tmp);
        
        if(tmp == s2) return true;
        
        tmp = s1;
        
        clockwise(tmp);
        clockwise(tmp);
        
        if(tmp == s2) return true;
        
        
        return false;
        
    }
};
