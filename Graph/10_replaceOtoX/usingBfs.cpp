#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int r;
    int c;
    
    bool valid(int i, int j){
        return i>=0&&i<r && j>=0&&j<c;
    }
  
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // first of fall traverse all corners side only
        // if ek bhi 'O' mile to usko 'T' se replace kar do 
        // and queue mai push kar do 
        // when all sides are traverse ho jaye tab
        // one by one queue mai se nikhalo and ab unki adjency node ko traverse karo
        r = mat.size();
        c = mat[0].size();
        queue<pair<int,int>>q;
        
        // first column
        for(int i=0;i<r;i++){
            if(mat[i][0]=='O'){
                q.push({i,0});
                mat[i][0]='T';
            }
        }
        
        // last column
        for(int i=0;i<r;i++){
            if(mat[i][c-1]=='O'){
                q.push({i,c-1});
                mat[i][c-1]='T';
            }
        }
        
        // first row
        for(int i=1;i<c;i++){
            if(mat[0][i]=='O'){
                q.push({0,i});
                mat[0][i]='T';
            }
        }
        
         // last row
        for(int i=1;i<c;i++){
            if(mat[r-1][i]=='O'){
                q.push({r-1,i});
                mat[r-1][i]='T';
            }
        }
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                if(valid(i+row[k], j+col[k]) && mat[i+row[k]][j+col[k]]=='O'){
                    q.push({i+row[k], j+col[k]});
                    mat[i+row[k]][j+col[k]]='T';
                }
            }
        }
            
        //     // UP
        //         if(valid(i-1, j) && mat[i-1][j]=='O'){
        //             mat[i-1][j]='T';
        //             q.push({i-1,j});
        //         }
        //         // down
        //         if(valid(i+1, j) && mat[i+1][j]=='O'){
        //             mat[i+1][j]='T';
        //             q.push({i+1,j});
        //         }
        //         // left
        //         if(valid(i, j-1) && mat[i][j-1]=='O'){
        //             mat[i][j-1]='T';
        //             q.push({i,j-1});
        //         }
        //         // right
        //         if(valid(i,j+1) && mat[i][j+1]=='O'){
        //             mat[i][j+1]='T';
        //             q.push({i,j+1});
        //         }
        // }
        
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(mat[i][j]=='O'){
                mat[i][j]='X';
            }
            if(mat[i][j]=='T'){
                mat[i][j]='O';
            }
        }
        
        return mat;
        
    }
};