#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        stack<int>st;
        
        int n = s.size();
        
        for(int i=0;i<n/2; i++){
            st.push(s.top());
            s.pop();
        }
        s.pop();
        
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
    }
};