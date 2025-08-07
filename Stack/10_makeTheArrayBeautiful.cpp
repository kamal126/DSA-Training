#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> makeBeautiful(vector<int> arr){
        stack<int>st;

        for(int ele : arr){
            if(st.empty()){
                st.push(ele);
            }else{
                if((ele>=0 && st.top()<0) || ele<0 && st.top()>=0){
                    st.pop();
                }else{
                    st.push(ele);
                }
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};