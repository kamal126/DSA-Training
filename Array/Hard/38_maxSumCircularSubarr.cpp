/*918. Maximum Sum Circular Subarray
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kadanesMax(vector<int>&nums, int n){
        int sum = nums[0];
        int maxSum = nums[0];

        for(int i=1;i<n;i++){
            sum = max(sum+nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }

    int kadanesMin(vector<int>&nums, int n){
        int sum = nums[0];
        int minSum = nums[0];

        for(int i=1;i<n;i++){
            sum = min(sum+nums[i], nums[i]);
            minSum = min(minSum, sum);
        }
        return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        // 1. sum
        int sum = accumulate(begin(nums), end(nums), 0);
        // 2. minSum
        int minSum = kadanesMin(nums, n);
        // 3. maxSum
        int maxSum = kadanesMax(nums, n);
        // 4. circular_Sum
        int circular_Sum = sum - minSum;

        if(maxSum>0){
            return max(maxSum, circular_Sum);
        }

        return maxSum;
    }
};