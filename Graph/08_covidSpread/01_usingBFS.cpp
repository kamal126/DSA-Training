#include<vector>
#include<queue>
using namespace std;

// User function Template for C++

class Solution {
  public:
  
  int row[4]={-1,1,0,0};
  int col[4]={0,0,-1,1};
  int r;
  int c;
    
    bool isvalid(int i, int j){
        
        return i>=0&&i<r && j>=0&&j<c;
    }
  
    int helpaterp(vector<vector<int>>hospital) {
        // code here
        r = hospital.size();
        c = hospital[0].size();
        
        queue<pair<int,int>> q;
        
        // all covid pateient push into queue
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(hospital[i][j]==2)
            q.push({i,j});
        
        if(q.empty()) return 0;
        
        int timer = 0;
        while(!q.empty()){
            timer++;
            int size = q.size();
            
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++){
                    if(isvalid(i+row[k], j+col[k])&&hospital[i+row[k]][j+col[k]]==1){
                        hospital[i+row[k]][j+col[k]]=2;
                        q.push({i+row[k], j+col[k]});
                    }
                }
                /*
                // up => [i-1][j]
                if(isvalid(i-1, j)&&hospital[i-1][j]==1){
                    hospital[i-1][j] = 2;
                    q.push({i-1,j});
                }
                // down => [i+1][j]
                if(isvalid(i+1, j)&&hospital[i+1][j]==1){
                    hospital[i+1][j] = 2;
                    q.push({i+1,j});
                }
                //left  => [i][j-1]
                if(isvalid(i, j-1)&&hospital[i][j-1]==1){
                    hospital[i][j-1] = 2;
                    q.push({i,j-1});
                }
                // right    => [i][j+1]
                if(isvalid(i, j+1)&&hospital[i][j+1]==1){
                    hospital[i][j+1] = 2;
                    q.push({i,j+1});
                }
                */
            }
        }
        
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(hospital[i][j]==1)
            return -1;
            
        return timer-1;
    }
};








