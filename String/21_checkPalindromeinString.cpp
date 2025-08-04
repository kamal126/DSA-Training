#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool check(string s){
        int i=0, n = s.size();
        
        while(i<n/2){
            if(s[i]!= s[n-1-i]){
                return 0;
            }
            i++;
        }
        
        return 1;
    }
    // using recursion
    bool check2(string s, int start, int end){
        if(start>=end) return 1;
        
        if(s[start]!=s[end]) return 0;
        
        else
        
        return check2(s, start+1, end-1);
    }
    bool isPalindrome(string& s) {
        // code here
        return check(s);
        // return check2(s, 0, s.size()-1); // memeory limit exceed
    }
};