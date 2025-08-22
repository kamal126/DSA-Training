 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
//   TC-> O(n^2) SC-> O(1)
    int getMaxArea1(vector<int>&arr){
        int res=0, curr, n = arr.size();

        for(int i=0;i<n;i++){
            curr = arr[i];

            // prev smaller tak
            for(int j=i-1; j>=0 && arr[j]>=arr[i]; j--)
                curr += arr[i];

            // next smaller tak
            for(int j=i+1; j<n && arr[j]>=arr[i]; j++)
                curr += arr[i];
            
            res = max(res, curr);
        }
        return res;
    }
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int>nextS(n,n);
        vector<int>prevS(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                nextS[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && arr[i]<arr[st.top()]){
                prevS[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }


        int res=0;
        for(int i=0;i<n;i++){
            int width = nextS[i]-prevS[i]-1;
            int area = arr[i] * width;

            res = max(res, area);
        }

        return res;
    }
};