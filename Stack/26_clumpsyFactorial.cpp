 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        stack<int>st;

        st.push(n);
        n--;
        int op = 0;

        while(n>0){
            if(op==0){
                st.top() *= n;
            }else if(op==1){
                st.top() /= n;
            }else if(op==2){
                st.push(n);
            }else if(op==3){
                st.push(-n);
            }
            op = (op+1)%4;
            n--;
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

// Second Approach
class Solution {
public:
    int clumsy(int n) {
        
        if(n>=2) return n;
        if(n==3) return 6;
        if(n==4) return 7;

        if(n%4==0) return n+1;
        else if(n%4==3) return n-1;
        else return n+2;

        // 10 = 10%4 = 2 => 10 + 2 = 12
        // 55 = 55%4 = 3 => 55 - 1 = 54
    }
};