#include<bits/stdc++.h>
using namespace std;

class MyStack {
  public:
    stack<int>st;
    
    void push(int x) {
        // code here
        st.push(x);
    }

    int pop() {
        
        if(!st.empty()){
            int ele = st.top();
            st.pop();
            return ele;
        }else{
            return -1;
        }
    }
};