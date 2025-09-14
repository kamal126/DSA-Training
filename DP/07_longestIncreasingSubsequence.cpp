#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int n;

    int LIS(int idx, vector<int>&nums, int prevIdx){
        if(idx==n) return 0;

        // take 
        int take=0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1+LIS(idx+1, nums, idx);
        }

        // skip:
        int skip = LIS(idx+1, nums, prevIdx);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n= nums.size();

        return LIS(0, nums, -1);
    }
};
