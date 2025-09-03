#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    // int find(int n, int m, string &s1, string &s2){
    //     if(n==0 || m==0) return 0;

    //     if(s1[n] == s2[m]){
    //         return 1+find(n-1, m-1, s1, s2);
    //     }else{
    //         return find(n-1, m, s1, s2), find(n, m-1, s1, s2);
    //     }
    // }
    int find(int n, int m, string &s1, string &s2, vector<vector<int>>&dp){
        if(n==0 || m==0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(s1[n] == s2[m]){
            return dp[n][m] = 1+find(n-1, m-1, s1, s2, dp);
        }else{
            return dp[n][m] = max(find(n-1, m, s1, s2,dp) ,find(n, m-1, s1, s2, dp));
        }
    }

    int LCS(string &s1, string &s2){
        int n = s1.size();
        int m =s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
    int LCS(string &s1, string &s2){
        int n = s1.size();
        int m =s2.size();
        vector<int>dp(m+1, 0);
        
        int ans = 0;
        int prev, curr;
        for(int i=1;i<=n;i++){
            prev=0,curr=0;
            for(int j=1;j<=m;j++){
                curr = dp[j];
                if(s1[i-1]==s2[j-1]){
                    dp[j] = 1+dp[j-1];
                    ans = max(ans, dp[j]);
                }
            }
        }
        return ans;
    }
    // int LCS(string &s1, string &s2){
    //     int n = s1.size();
    //     int m =s2.size();
    //     vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

    //     return find(n-1,m-1,s1,s2, dp);
    // }
};