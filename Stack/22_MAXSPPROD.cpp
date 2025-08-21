 
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
class Solution{
    public:
    int maxSpecialProduct(vector<int> &A) {
        int n =A.size();
        vector<int>left(n,0), right(n,0);
        stack<int>lsv, rsv;

        // Left special Value find
        for(int i=0;i<n;i++){
            while(!lsv.empty() && A[i] >= A[lsv.top()]){
                lsv.pop();
            }
            if(!lsv.empty()) left[i] = lsv.top();

            lsv.push(i);
        }
        // right special value find
        for(int i=n-1;i>=0;--i){
            while(!rsv.empty() && A[i] >= A[rsv.top()]){
                rsv.pop();
            }

            if(rsv.empty()){
                right[i] = rsv.top();
            }
            rsv.push(i);
        }
        // calculate maximum product
        int ans = INT_MIN;
        for(int i=0; i<n;i++){
            ans = max(ans, left[i]*right[i]);
        }

        return ans%MOD;
    }
};