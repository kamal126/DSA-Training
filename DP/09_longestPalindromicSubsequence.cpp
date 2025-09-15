 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int find(int i, int j, string &s1, string &s2){
        if(i<0 || j<0) return 0;
        
        
        if(s1[i]==s2[j]){
            return 1+find(i-1, j-1, s1, s2);
        }else{
            return max(find(i-1,j, s1, s2), find(i,j-1, s1, s2));
        }
    }
  
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        return find(n-1,n-1,s,rev);
    }
};