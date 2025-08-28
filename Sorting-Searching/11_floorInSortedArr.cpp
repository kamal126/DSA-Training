 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int idx = -1;
        // for(int i=n-1; i>=0; i--){
            
        //     if(arr[i] <= x){
        //         idx = i;
        //         break;
        //     }
        // }
        
        int start = 0, end = n-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            // If arr[mid] is less than or equal to x, it could be a potential floor
            if(arr[mid] <= x){
                idx = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        
        return idx;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1,2,8,10,10,12,19};
    int x = 5;
    cout<<obj.findFloor(arr, x);
    return 0;
}//{ Driver Code Starts
// Initial Template for C++