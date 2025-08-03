#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int getLPSLength(string &s) {
        vector<int>lps(s.size(),0);

        int pre=0,suff=1;
        lps[0] = 0;

        while(suff<s.size()){
            // Match
            if(s[pre]==s[suff]){
                lps[suff] = pre+1;
                pre++, suff++;
            }
            // Not Match
            else{
                // pre==0
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                // pre not zero
                else{
                    pre = lps[pre-1];
                }
            }
        }
        return lps[s.size()-1];
    }
};