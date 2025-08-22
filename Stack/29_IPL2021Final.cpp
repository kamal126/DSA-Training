#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string s) {
        int n = s.size();
        stack<int>st;
        st.push(-1); // handle edge case ))() start with )
        int maxLen = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();

                if(st.empty()) st.push(i);
                else   
                    maxLen = max(maxLen, i-st.top());
            }
        }

        return maxLen;
    }
    
    int findMaxLen2(string s) {
        int n = s.size();
        int open=0, close=0;
        int maxLen = 0;
        // left to right
        for(char ch : s){
            if(ch == '(') open++;
            else close++;

            if(open==close) 
                maxLen = max(maxLen, 2*close);
            
            if(close > open) open=close=0;
        }

        // initial state open and close = 0
        open=close=0;
        // right to left

        for(int i=n-1;i>=0;i--){
            if(s[i]==')') close++;
            else open++;

            if(open==close)
                maxLen = max(maxLen, 2*open);
            
            if(open > close) open=close = 0;
        }

        return maxLen;
    }
};