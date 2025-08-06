#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        stack<string>st;

        for(string s : arr){
            if(!st.empty() && s == st.top()){
                st.pop();
            }else{
                st.push(s);
            }
        }

        return st.size();
    }
};