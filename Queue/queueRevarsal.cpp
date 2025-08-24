 
#include<bits/stdc++.h>
using namespace std;

// function Template for C++

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        queue<int>ans;
        stack<int>st;
        
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            ans.push(st.top());
            st.pop();
        }
        
        return ans;
    }
};