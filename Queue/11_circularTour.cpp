 
#include<bits/stdc++.h>
using namespace std;

/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int tank = 0;
        int idxS = 0;
        
        int total_gas=0, total_cost=0;
        
        for(int i=0;i<gas.size();i++){
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];
            
            if(tank < 0){
                tank=0;
                idxS = i+1;
            }
        }
        
        if(total_gas < total_cost) return -1;
        
        // for(int i=0;i<gas.size();i++){
        //     total_gas+=gas[i];
        // }
        // for(int i=0;i<gas.size();i++){
        //     total_cost+=cost[i];
        // }
        
        // if(total_gas<total_cost) return -1;
            

        // for(int i=0;i<gas.size(); i++){
        //     tank += gas[i]-cost[i];
            
        //     if(tank<0){
        //         tank = 0;
        //         idxS = i+1;
        //     }
        // }
        
        return idxS;
        
    }
};