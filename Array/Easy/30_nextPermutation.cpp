#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int gola_idx = -1;

        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                gola_idx = i-1;
                break;
            }
        }

        if(gola_idx != -1){
            int swap_idx = gola_idx;

            for(int i=n-1;i>=gola_idx;i--){
                if(arr[i]>arr[gola_idx]){
                    swap_idx = i;
                    break;
                }
            }

            swap(arr[gola_idx], arr[swap_idx]);
        }

        reverse(arr.begin()+gola_idx+1, arr.end());
    }
};

/*
31. Next Permutation
Solved
Medium
Topics
premium lock icon
Companies
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/