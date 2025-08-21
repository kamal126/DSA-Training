 
#include<bits/stdc++.h>
using namespace std;

vector<int>nextGreaterEle(vector<int>num){
    int n = num.size();
    vector<int>ans(n,-1);
    stack<int>st;

    for(int i = 2*n-1; i>=0; --i){
        int idx = i % n; // handle circular array idx

        while(!st.empty() && num[idx] >= num[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            ans[idx] = num[st.top()];
        }    
        st.push(idx);
    }
    return ans;
}