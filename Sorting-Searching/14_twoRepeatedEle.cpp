 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoRepeated(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int idx = abs(arr[i]);

            if(arr[idx]>0){
                arr[idx] = -arr[idx];
            }else{
                ans.push_back(idx);
            }
        }

        return ans;
    }
};
