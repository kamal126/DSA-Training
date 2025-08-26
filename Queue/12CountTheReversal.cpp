 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countMinReversals(string s) {
        int n = s.size();
        
        if(n%2!=0) return -1;
        
        int open=0,close=0;
        
        for(char ch : s){
            if(ch=='{'){
                open++;
            }else{
                if(open>0) 
                    open--;
                else
                    close++;
            }
        }
        
        open = open%2==0 ? open/2 : (open+1)/2;
        close = close%2==0 ? close/2 : (close+1)/2;
        
        return open+close;
    }
};