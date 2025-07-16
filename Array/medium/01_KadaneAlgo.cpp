#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    
    int maxSubarraySum(vector<int> &arr) {
        
        int sum = 0;
        int prev = INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            
            // if(sum < 0) sum = 0;
            
            prev = max(prev, sum);
            if(sum < 0) sum = 0;
        }
        
        return prev;
    }
};