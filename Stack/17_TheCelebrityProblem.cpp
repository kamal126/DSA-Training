#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        stack<int>st;

        int n = mat.size();

        for (int i = 0; i < n; i++)
            st.push(i);
        
            while(st.size() > 1){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                mat[a][b]? st.push(b) : st.push(a);
            }

            int c = st.top(); st.pop();

            for(int i=0;i<n;i++){
                if(i==c) continue;

                if(mat[c][i] || !mat[i][c])
                    return -1;
            }

            return c;
    }
};

// Approach 2
int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    
    int i=0, j=n-1;

    while(i<j){

        if(mat[i][j]){
            i++;
        }else{
            j--;
        }
    }

    int c = i;

    for(int i=0;i<n;i++){
        if(c==i) continue;

        if(mat[c][i] || !mat[i][c]) return -1;
    }

    return c;
}