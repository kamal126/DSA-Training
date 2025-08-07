#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int calPoints(vector<string>& operations) {
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(ops[i]=="C"){
                if(!st.empty()){
                    st.pop();
                }
            }else if(ops[i]=="D"){
                if(!st.empty()){
                    st.push(2*st.top());
                }
            }else if(ops[i]=="+"){
                if(st.size()>=2){
                    int e1 = st.top();
                    st.pop();
                    int e2 = st.top();
                    st.push(e1);
                    st.push(e1+e2);
                }
            }else{
                st.push(stoi(ops[i]));
            }
        }

        int totalSum = 0;
        while(!st.empty()){
            totalSum += st.top();
            st.pop();
        }

        return totalSum;
    }
};