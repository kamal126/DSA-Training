#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxDiff(vector<int> &arr){
        int n = arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>st;

        for(int i=0;i<n;++i){
            while (!st.empty() && arr[i]<arr[st.top()]){
                left[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; --i){
            while(!st.empty() && arr[i] < arr[st.top()]){
                right[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        int diff = 0;
        for(int i=0;i<n;i++){
            diff= max(diff, abs(left[i]-right[i]));
        }

        return diff;
    }
};