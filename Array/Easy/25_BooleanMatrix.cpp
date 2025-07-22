#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int idx=0;
                if(mat[i][j]==1){
                    
                    while(idx<row){
                        if(mat[idx][j]==0)
                        mat[idx][j]=-1;
                        idx++;
                    }
                    idx=0;
                    while(idx<col){
                        if(mat[i][idx]==0)
                        mat[i][idx]=-1;
                        idx++;
                    }
                }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==-1)
                    mat[i][j]=1;
            }
        }
    }
};





/*
Boolean Matrix
Difficulty: MediumAccuracy: 40.05%Submissions: 125K+Points: 4
Given a boolean matrix mat[], where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.

Examples:

Input: mat[][] = [[1, 0], [0, 0]]
Output: [[1, 1], [1, 0]] 
Explanation: Only cell that has 1 is at (0,0) so all cells in row 0 are modified to 1 and all cells in column 0 are modified to 1.
Input: mat[][] = [[1, 0, 0], [1, 0, 0], [1, 0, 0], [0, 0, 0]]
Output: [[1, 1, 1], [1, 1, 1], [1, 1, 1], [1, 0, 0]]
Explanation: The position of cells that have 1 in the original matrix are (0, 0), (1, 0) and (2, 0). Therefore, all cells in row 0, 1, 2 are and column 0 are modified to 1. 
Input: mat[][] = [[0, 0], [0, 0]]
Output: [[0, 0], [0, 0]] 
Explanation: There is no cell that contains 1, so mat[] will remain the same.
Constraints:
1 ≤ mat.size(), mat[0].size() ≤ 103
0 ≤ mat[i][j] ≤ 1


*/