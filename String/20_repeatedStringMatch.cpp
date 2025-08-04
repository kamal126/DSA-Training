#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void FIND_LPS(string s, vector<int>&lps){
        int pre=0, suff=1;

        while (suff<s.size())
        {
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
    int KMP_MATCH(string s1, string s2){
        vector<int>lps(s2.size(), 0);

        FIND_LPS(s2, lps);

        int first=0, sec=0;
        while(first<s1.size() && sec<s2.size()){
            // MATCH
            if(s1[first]==s2[sec]){
                first++, sec++;
            }
            // NOT MATCH
            else{
                if(sec==0) {
                    first++;
                }
                else{
                    sec = lps[sec-1];
                }
            }
        }

        if(sec==s2.size()) return 1;

        return 0;

    }
    int repeatedStringMatch(string a, string b) {
        
        if(a==b) return 1;

        string tmp = a;
        int repeat = 1;
        while(tmp.size()<b.size()){
            tmp += a;
            repeat++;
        }

        // MATCH 
        if(KMP_MATCH(tmp, b)) return repeat;

        // NOT MATCH
        if(KMP_MATCH(tmp+a, b)) return repeat+1;

        return -1;
    }
};