#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int>ans;
        stack<int>st;
        int i=1;
        for(char ch : str){
            if(ch == '('){
                ans.push_back(i);
                st.push(i);
                i++;
            }else if(ch == ')'){
                if(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }else{
                    ans.push_back(i);
                    i++;
                }
            }
        }

        return ans;
    }
};