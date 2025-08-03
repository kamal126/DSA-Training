#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void findLPS(string s, vector<int>&lps){
        int pre=0, suff=1;

        while(suff<s.size()){
            if(s[pre]==s[suff]){
                lps[suff] = pre+1;
                pre++, suff++;
            }else{
                if(pre==0){
                    suff++;
                }else{
                    pre = lps[pre-1];
                }
            }
        }
    }
    int minChar(string &s) {
        
        // reverse a string 
        // add reverse string original string seprated by '$'
        // find lps
        // return string size to lps last index value

        string rev = s;
        reverse(rev.begin(), rev.end());
        int size = rev.size();
        s += '$' + rev;
        int n = s.size();

        vector<int>lps(n,0);
        findLPS(s, lps);

        return size - lps[n-1];
    }
};