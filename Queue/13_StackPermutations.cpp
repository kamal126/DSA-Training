 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkPerm(vector<int>& a, vector<int>& b) {
        stack<int> st;
        int j = 0;
        
        for (int ele : a) {
            st.push(ele);
            while (!st.empty() && st.top() == b[j]) {
                st.pop();
                j++;
            }
        }
        return j == b.size();
    }
};
