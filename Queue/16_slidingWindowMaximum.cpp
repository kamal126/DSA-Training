 
#include<bits/stdc++.h>
using namespace std;

vector<int>slidingMaximum(const vector<int> &A, int k) {
    vector<int>ans;
    deque<int>dq;
    int n = A.size();
    
    // 0 ----> k-1
    for(int i=0;i<k-1;i++){
        if(dq.empty()) 
            dq.push_back(i);
        else{
            while(!dq.empty() && A[i]>A[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
    }
    
    // k-1 ----> n
    for(int i=k-1; i<n;i++){
        while(!dq.empty() && A[i]>A[dq.back()]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        
        ans.push_back(A[dq.front()]);
    }
    
    
    // for(int i=0;i<=n-k;i++){
    //     int maxVal = A[i];
        
    //     for(int j=i;j<i+k;j++){
    //         maxVal = max(maxVal, A[j]);
    //     }
        
    //     ans.push_back(maxVal);
    // }
    
    return ans;
}
