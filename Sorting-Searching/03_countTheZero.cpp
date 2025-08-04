#include<bits/stdc++.h>
using namespace std;


// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here
        int start=0, end=arr.size()-1;
        int n = arr.size()-1;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr[mid]==0){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        if(ans!=-1)
            return n - ans+1;;
        
        return 0;
    }
};