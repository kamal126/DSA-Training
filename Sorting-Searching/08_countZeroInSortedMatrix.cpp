 
#include<bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++

class Solution {
  public:
    int countZeros(vector<vector<int>> A) {
        // code here
        int n = A.size();
        
        int col = n-1, row = 0;
        int count = 0;
        // Start from top-right corner of the matrix
        while(row < n){
            // Move left until we find a zero
            while(col >=0 && A[row][col]){
                col--;
            }
            // If we found a zero, all elements to the left are also zeros
            count += col+1;
            // Move to the next row
            row++;
        }
        
        return count;
    }
};