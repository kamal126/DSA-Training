#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterRight(vector<int>arr){
    stack<int>st;
    vector<int>ans(arr.size(),-1);

    for(int i=0;i<arr.size(); i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int main(){
    vector<int>arr = {1,3,4,2};

    vector<int>ans = nextGreaterRight(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i] << " ";    // 3 4 -1 -1 
    }
    return 0;
}