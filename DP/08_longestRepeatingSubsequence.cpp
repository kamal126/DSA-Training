 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int n;
    
    int find(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i==n || j==n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i!=j && s1[i]==s2[j]){
            return dp[i][j] = max(1+find(i+1, j+1, s1, s2, dp), 
            max(find(i, j+1, s1, s2, dp), find(i+1, j, s1, s2, dp)));
        }else{
            return dp[i][j] = max(find(i, j+1, s1, s2, dp), find(i+1, j, s1, s2, dp));
        }
    }

    int LongestRepeatingSubsequence(string &s) {
        // Code here
        n = s.size();
        vector<int>dp(n+1, 0);

        int prevDiagonal, curr;
        
        for(int i=1;i<=n;i++){
            prevDiagonal = 0;
            for(int j=1;j<=n;j++){
                curr = dp[j];
                if(i!=j && s[i-1]==s[j-1]){
                    dp[j] = 1+prevDiagonal;
                }else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prevDiagonal = curr;
            }
        }
        
        return dp[n];
    }
    // ===============================================
    // int LongestRepeatingSubsequence(string &s) {
    //     // Code here
    //     n = s.size();
    //     vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             if(i!=j && s[i-1]==s[j-1]){
    //                 dp[i][j] = max(1+dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
    //             }else{
    //                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
        
    //     return dp[n][n];
    // }
    // =====================================================================================
    // int LongestRepeatingSubsequence(string &s) {
    //     // Code here
    //     n = s.size();
    //     vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        
    //     return find(0,0,s,s, dp);
    // }
    // ==========================================================
    // int LongestRepeatingSubsequence(string &s) {
    //     // Code here
    //     n = s.size();
        
    //     return find(0,0,s,s);
    // }
};
int main(){
    string s1 = "axxzxy";
    string s2 = "axxxy";
    
    Solution obj;

    cout<<obj.LongestRepeatingSubsequence(s1)<<endl;
    cout<<obj.LongestRepeatingSubsequence(s2)<<endl;

    return 0;
}