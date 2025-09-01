
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    // recursive + memoization
    int find(int idx, vector<int>&val, vector<int>&wt, int W, vector<vector<int>>&dp){
        if(idx==0 || W==0) return 0;

        if(dp[idx][W]!=-1) return dp[idx][W];

        if(wt[idx-1]>W)
            return dp[idx][W] = find(idx-1, val, wt, W, dp);
        else  
            return dp[idx][W] = max(val[idx-1] + find(idx-1, val, wt, W-wt[idx-1], dp), find(idx-1, val, wt, W, dp));
    }

// ================ Space optimization ===========================
    int knapscak(vector<int>&val, vector<int>&wt, int W){
        int n = val.size();
        vector<int>dp(W+1, 0);

        for(int i=0;i<=n;i++)
        for(int j=W;j>=wt[i-1];j--){
            dp[j] = max(val[i-1] + dp[j-wt[i-1]], dp[j]);
        }

        return dp[W];

    }

// ================= Bottom UP approach ===========================
    // int knapscak(vector<int>&val, vector<int>&wt, int W){
    //     int n = val.size();
    //     vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
    //     for(int i=1;i<=n;i++)
    //     for(int j=1;j<=W;j++){
    //         if(wt[i-1]>j)
    //             dp[i][j] = dp[i-1][j];
    //         else  
    //             dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
    //     }

    //     return dp[n][W];

    // }

// ================ recursive + mempization ===========================
    // int knapscak(vector<int>&val, vector<int>&wt, int W){
    //     int n = val.size();
    //     vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
    //     return find(n, val, wt, W, dp);

    // }

// ============== Bottom Up ============================
    // int knapscak(vector<int>&val, vector<int>&wt, int W){
    //     int n = val.size();

    //     return find(n, val, wt, W);

    // }
};

int main(){

    vector<int>val = {60, 100, 120};
    vector<int>wt = {10, 20, 30};
    int W = 50;

    Solution obj;
    cout<<obj.knapscak(val, wt, W)<<endl;

    return 0;
};