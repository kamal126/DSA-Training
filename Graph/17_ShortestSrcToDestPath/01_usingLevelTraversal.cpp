#include <bits/stdc++.h>
using namespace std;
/**
Shortest Source to Destination Path
Difficulty: MediumAccuracy: 24.69%Submissions: 120K+Points: 4
Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3, M=4
A=[[1,0,0,0], 
   [1,1,0,1],
   [0,1,1,1]]
X=2, Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
Example 2:

Input:
N=3, M=4
A=[[1,1,1,1],
   [0,0,0,1],
   [0,0,0,1]]
X=0, Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).
Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

Constraints:
1 <= N,M <= 250
0 <= X < N
0 <= Y < M
0 <= A[i][j] <= 1
 */

// User function Template for C++

class Solution {
  public:
        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,-1,1};
  
        bool valid(int i, int j, int r, int c){
          return i>=0 && j>=0 && i<r && j<c;
        }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        // edge cases
        if(A[0][0]==0) return -1;   // src 0 hai
        if(X==0 && Y==0) return 0;  // src hi dest hai
        if(A[X][Y]==0) return -1;   // dest hi 0 hai
        
        int steps=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        A[0][0] = 0;
        
        while(!q.empty()){
            int count = q.size();
            
            while(count--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
 
                for(int k=0;k<4;k++){
                    
                    if(valid(i+row[k], j+col[k], N, M) && A[i+row[k]][j+col[k]]==1){
                        if(i+row[k] == X && j+col[k] == Y)
                            return steps+1;
                        // otherwise
                        A[i+row[k]][j+col[k]] = 0;
                        q.push({i+row[k], j+col[k]});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
