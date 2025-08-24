#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        
        if(q.size()<k) return q;
        
        stack<int>st;
        queue<int>q1;
        
        
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
        }
        
        
        while(!st.empty()){
            q1.push(st.top());
            st.pop();
        }
        
        while(!q.empty()){
            q1.push(q.front()); q.pop();
        }
        
        return q1;
    }
};