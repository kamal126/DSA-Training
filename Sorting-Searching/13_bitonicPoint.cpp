 
#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int n = arr.size();
        
        // first element is maimum
        if(n==1 || arr[0] >arr[1]) return arr[0];
        // last element is maximum
        if(arr[n-1] > arr[n-2]) return arr[n-1];
        
        int start=0, end=arr.size()-1;
        
        while(start < end){
            int mid = start+(end-start)/2;
            // maximum point
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return arr[mid];
                // we are in decreasing part of array
            }else if(arr[mid] > arr[mid+1]){
                end = mid-1;
                // we are in increasing part of array
            }else if(arr[mid] > arr[mid-1]){
                start = mid+1;
            }
        }
        
        return arr[start];
    }
};