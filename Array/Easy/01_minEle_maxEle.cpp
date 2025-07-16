// User function Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int minEle=INT_MAX, maxEle= INT_MIN;
        
        int i=0;
        while(i<arr.size()){
            minEle = min(minEle, arr[i]);
            maxEle = max(maxEle, arr[i]);
            i++;
        }
        
        return {minEle, maxEle};
    }
};

/*
TC = O(N)
SC = O(1)
*/

