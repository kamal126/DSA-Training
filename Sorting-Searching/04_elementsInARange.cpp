#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check_elements(int arr[], int n, int A, int B) {
        int range = (B-A)+1;
        
        for(int i=0;i<n;i++){
            if(arr[i]>=A && arr[i]<=B){
                range--;
            }
        }
        
        if(range==0) return true;
        
        return false;
    }
};
