#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        st.push(-1);
        
        for(int i=n-1; i>=0; i--){
            st.push(arr[i]);
        }
        
        int i=0;
        while(!st.empty() && i<n){
            int ele = st.top();
            st.pop();
            
            if(ele>st.top()){
                arr[i] = st.top();
            }else{
                arr[i] = -1;
            }
            i++;
        }
        
    }
};


// class Solution {
//   public:
//     void immediateSmaller(vector<int>& arr) {
//         int n = arr.size();
//         for(int i=0; i<n-1; i++){
//             if(arr[i]>arr[i+1]){
//                 arr[i] = arr[i+1];
//             }else{
//                 arr[i] = -1;
//             }
//         }
//         arr[n-1] = -1;
//     }
// };