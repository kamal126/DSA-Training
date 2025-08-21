#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeKdigits(string s, int k) {
        stack<char>st;

        for(char ch : s){
            while(!st.empty() && k>0 && st.top() > ch){
                st.pop();
                k--;
            }

            if(!st.empty() || ch != '0') st.push(ch);
        }

        while(!st.empty() && k--){
            st.pop();
        }

        if(st.empty()) return "0";
        
        string ans;
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

