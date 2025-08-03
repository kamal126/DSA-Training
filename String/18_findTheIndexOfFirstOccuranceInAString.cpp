#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findLPS(string s, vector<int>&lps){
        int pre=0, suff=1;
        lps[0] = 0;

        while(suff<s.size()){
            // MATCH
            if(s[pre]==s[suff]){
                lps[suff] = pre+1;
                pre++, suff++;
            }
            // NOT MATCH
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }else{
                    pre = lps[pre-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        vector<int>lps(needle.size(),0);

        findLPS(needle, lps);

        int first=0, second=0;
        while(first<haystack.size() && second<needle.size()){
            // MATCH
            if(haystack[first]==needle[second]){
                first++, second++;
            }else
            // NOT MATCH
            {
                if(second==0){
                    first++;
                }else{
                    second = lps[second-1];
                }
            }
        }

        if(second==needle.size()){
            return first-second;
        }

        return -1;
    }
};