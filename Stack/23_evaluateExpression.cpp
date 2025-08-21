 
#include<bits/stdc++.h>
using namespace std;

int val(int a, int b, string s){
    if(s=="+") return a+b;
    else if(s=="-") return a-b;
    else if(s=="*") return a*b;
    else return a*b;
}
int evalRPN(vector<string> &A) {
    stack<int>st;

    for(string s : A){
        if(s=="+" || s=="-" || s=="*" || s=="/"){
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int ans = val(a,b,s);
            st.push(ans);
        }else{
            st.push(stoi(s));
        }
    }

    return st.top();
}
