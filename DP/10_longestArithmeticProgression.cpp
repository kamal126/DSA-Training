 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int solve(int idx, int diff, vector<int>&arr){
        if(idx<0) return 0;

        int ans = 0;

        for(int j=idx-1; j>=0; j--){
            if(arr[idx]-arr[j]==diff){
                ans = max(ans, 1+solve(j, diff, arr));
            }
        }

        return ans;
    }
    
    int longestArithmeticPro(vector<int>&arr){
        int n = arr.size();

        if(n<=2) return n;

        int ans=0;

        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            int diff = arr[j]-arr[i];
            ans = max(ans, 2+solve(i,diff, arr));
        }

        return ans;
    }
};

int main(){
    vector<int>arr = {1,7,10,13,14,19};
    Solution obj;
    cout<<obj.longestArithmeticPro(arr);

    return 0;
}