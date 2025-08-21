  
#include<bits/stdc++.h>
using namespace std;

int braces(string A) {
    stack<char>st;

    for(char ch : A){
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            bool hasRedundant = false;

            while(!st.empty() && st.top() != '('){
                char top = st.top(); st.pop();
                if(top=='+' || top=='-' || top=='*' || top=='/'){
                    hasRedundant = true;
                }
            }
            st.pop(); // pop the '('
            if(!hasRedundant) return 1;
        }
        return 0;
    }
}