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
};