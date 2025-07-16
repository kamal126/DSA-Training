#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int start=0, end = arr.size()-1;
        
        while(start<end){
            int tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
            
            start++, end--;
        }
    }
};