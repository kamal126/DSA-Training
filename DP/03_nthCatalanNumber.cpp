 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int findCatalan(int n){
        int catalan[n+1];

        catalan[0]=catalan[1]=1;

        for(int i=2;i<=n;i++){
            catalan[i] = 0;
            for(int j=0;j<i;j++){
                catalan[i] += catalan[j] * catalan[j-i-1];
            }
        }

        return catalan[n];
    }
    // int findCatalan(int n){
    //     if(n<=1) return 1;

    //     int res = 0;

    //     for(int i=0;i<n;i++){
    //         res += findCatalan(i) * findCatalan(n-i-1);
    //     }

    //     return res;
    // }
};