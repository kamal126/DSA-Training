#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;

        for(char ch : s){
            if(ch=='#'){
                if(!st1.empty())
                    st1.pop();
            }else{
                st1.push(ch);
            }
        }
        for(char ch : t){
            if(ch=='#'){
                if(!st2.empty())
                    st2.pop();
            }else{
                st2.push(ch);
            }
        }

        string s1="";
        string s2="";
        while(!st1.empty()){
            s1 += st1.top();
            st1.pop();
        }
        while(!st2.empty()){
            s2 += st2.top();
            st2.pop();
        }

        if(s1==s2) return true;

        return false;
    }
};