 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int find(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i]==s2[j]){
            return dp[i][j] = 1+find(i-1, j-1, s1, s2, dp);
        }else{
            return dp[i][j] = max(find(i-1,j, s1, s2, dp), find(i,j-1, s1, s2, dp));
        }
    }

    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        vector<int>dp(n+1, 0);
        string rev = s;
        reverse(rev.begin(), rev.end());
        int tmp, prev;
        for(int i=1;i<=n; i++){
            prev=0;
            for(int j=1;j<=n;j++){
                tmp = dp[j];
                if(s[i-1] == rev[j-1]){
                    dp[j] = 1+prev;
                }else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = tmp;
            }
        }
        
        return dp[n];
    }

    // int longestPalinSubseq(string &s) {
    //     // code here
    //     int n = s.size();
    //     vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    //     string rev = s;
    //     reverse(rev.begin(), rev.end());
        
    //     for(int i=1;i<=n; i++){
    //         for(int j=1;j<=n;j++){
    //             if(s[i-1] == rev[j-1]){
    //                 dp[i][j] = 1+dp[i-1][j-1];
    //             }else{
    //                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
        
    //     return dp[n][n];
    // }

    // int longestPalinSubseq(string &s) {
    //     // code here
    //     int n = s.size();
    //     vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    //     string rev = s;
    //     reverse(rev.begin(), rev.end());
        
    //     return find(n-1,n-1,s,rev, dp);
    // }
  
    // int longestPalinSubseq(string &s) {
    //     // code here
    //     int n = s.size();
    //     string rev = s;
    //     reverse(rev.begin(), rev.end());
        
    //     return find(n-1,n-1,s,rev);
    // }
};