#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Approach 1: Stack-based
    // Time: O(n), Space: O(n)
    int findMaxLen(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1); // base for valid substring length
        int maxLen = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();
                if(st.empty()) st.push(i);
                else maxLen = max(maxLen, i - st.top());
            }
        }
        return maxLen;
    }

    // Approach 2: Two-pointer (Left-to-Right & Right-to-Left)
    // Time: O(n), Space: O(1)
    int findMaxLen2(string s) {
        int n = s.size();
        int open = 0, close = 0, maxLen = 0;

        // Left to right scan
        for(char ch : s) {
            if(ch == '(') open++;
            else close++;
            if(open == close) maxLen = max(maxLen, 2*close);
            if(close > open) open = close = 0;
        }

        // Right to left scan
        open = close = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == ')') close++;
            else open++;
            if(open == close) maxLen = max(maxLen, 2*open);
            if(open > close) open = close = 0;
        }

        return maxLen;
    }
};
