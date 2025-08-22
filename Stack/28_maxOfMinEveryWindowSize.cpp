 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
//   Approach 1 : O(n^3) O(1)
    vector<int> maxOfMins2(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);

        for(int i=0; i<n; i++){
            for(int j=0;j<n-i;j++){
                int num = INT_MAX;
                for(int k=j; k<j+i+1; k++){
                    num = min(num, arr[k]);
                }

                ans[i] = max(arr[i], num);
            }
        }

        return ans;
    }
// Approach 2: O(n) O(n)
    vector<int>maxOfMins1(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st1, st2;
        vector<int>prevS(n,-1);
        vector<int>nextS(n,n);

        // next smaller right
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[i]<=arr[st1.top()]){
                arr[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[i]<=arr[st2.top()]){
                arr[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        for(int i=0;i<n;i++){
            int range = nextS[i] - prevS[i] -1;
            ans[range-1] = max(ans[range-1], arr[i]);
        }

        for(int i=n-2; i>=0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }

        return ans;
    }
// single stack use : O(n) O(n)
    vector<int>maxOfMins(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int idx = st.top(); st.pop();

                int range = st.empty() ? i : i - st.top() -1;

                ans[range-1] = max(ans[range-1], arr[idx]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int idx = st.top(); st.pop();  
            int range = st.empty() ? n : n - st.top() -1;
            ans[range-1] = max(ans[range-1], arr[idx]);
        }

        for(int i=n-2; i>=0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }

        return ans;
    }
};