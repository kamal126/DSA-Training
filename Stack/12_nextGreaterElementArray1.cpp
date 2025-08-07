#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>right(m,-1);
        stack<int>st;

        // find right greatest so start from 0
        for(int i=0;i<m;i++){
            // whenever nums2[i] is greater than nums2[stack's top index] then right[index] = nums2[i]
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                right[st.top()] = nums2[i];
                st.pop();
            }
            // push index
            st.push(i);
        }
        
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]] = right[i];
        }

        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};

// Approach 2nd 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};