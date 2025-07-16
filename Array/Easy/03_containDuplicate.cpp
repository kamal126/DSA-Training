#include<bits/stdc++.h>
using namespace std;

// Approach 1: TC -> O(N^2) SC-> O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){
            for(int j=i+1; j<nums.size();j++){
                if(nums[i]==nums[j])
                    return true;
            }
        }

        return false;
    }
};

// Approach 1: TC -> O(N) SC-> O(N) using map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]>1) return true;
        }
        return false;
    }
};

/**
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
 */
