 
#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int row = mat.size();
        int col = mat[0].size();
        
        int idx = 0;
        
        while(col>=0 && idx < row){
            
            if(mat[idx][col-1] == x){
                return true;
            }else if(mat[idx][col-1]<x){
                idx++;
            }else if(mat[idx][col-1]>x){
                col--;
            }
        }
        
        return false;
    }
};