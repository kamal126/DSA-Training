#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int trap(vector<int>height){
        int n = height.size();
        int maxH = height[0];
        int maxLeft=0, maxRight=0;
        int idx = 0;

        for(int i=1;i<n;i++){
            if(maxH < height[i]){
                maxH = height[i];
                idx = i;
            }
        }

        int water = 0;

        // left side se
        for(int i=0;i<idx;i++){
            if(height[i] < maxLeft){
                water += maxLeft - height[i];
            }else{
                maxLeft = height[i];
            }
        }

        // right side se
        for(int i=n-1; i>idx;i--){
            if(height[i] > maxRight){
                water += maxRight - height[i];
            }else{
                maxRight = height[i];
            }
        }

        return water;
    }
};