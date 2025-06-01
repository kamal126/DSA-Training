#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int r;
    int c;
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    bool valid(int i, int j){
        return i>=0 && i<r && j>=0 && j<c;
    }

    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>>q;
        int count = 0;

        for(int ir=0;ir<r;ir++)
        for(int jc=0;jc<c;jc++){
            if(grid[ir][jc]=='1'){
                count++;
                q.push({ir,jc});
                grid[ir][jc] = '0';
            }

            while(!q.empty()){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // for(int k=0;k<4;k++){
                //     if(valid(row[i],col[i]) && grid[row[i]][col[i]]){
                //         q.push({i,j});
                //         grid[row[i]][col[i]] = '0';
                //     }
                // }

                
                // UP
                if(valid(i-1, j) && grid[i-1][j]=='1'){
                    q.push({i-1,j});
                    grid[i-1][j]='0';
                }
                // down
                if(valid(i+1, j) && grid[i+1][j]=='1'){
                    q.push({i+1,j});
                    grid[i+1][j]='0';
                }
                // left
                if(valid(i, j-1) && grid[i][j-1]=='1'){
                    q.push({i,j-1});
                    grid[i][j-1]='0';
                }
                // right
                if(valid(i,j+1) && grid[i][j+1]=='1'){
                    q.push({i,j+1});
                    grid[i][j+1]='0';
                }
            }
        }
        return count;
    }
};