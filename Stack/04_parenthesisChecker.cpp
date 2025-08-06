#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        stack<char>st;
        
        for(char ch : k){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else{
                if(ch==')'){
                    if(!st.empty() && st.top()=='('){
                        st.pop();
                    }else{
                        return false;
                    }
                }else if(ch == '}'){
                    if(!st.empty() && st.top() == '{'){
                        st.pop();
                    }else{
                        return false;
                    }
                }else if(ch==']'){
                    if(!st.empty() && st.top() == '['){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return st.empty();
    }
};