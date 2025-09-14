#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int n;

    int LIS(int idx, vector<int>&nums, int prevIdx, vector<vector<int>>&dp){
        if(idx==n) return 0;

        if(dp[idx][prevIdx+1]!=-1)
            return dp[idx][prevIdx+1];

        // take 
        int take=0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1+LIS(idx+1, nums, idx, dp);
        }

        // skip:
        int skip = LIS(idx+1, nums, prevIdx, dp);

        return dp[idx][prevIdx+1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n= nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return LIS(0, nums, -1, dp);
    }
    // =============================================
    // int lengthOfLIS(vector<int>& nums) {
    //     n= nums.size();

    //     return LIS(0, nums, -1);
    // }
};
