#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>alpha(26,0);

        for(char ch : s){
            alpha[ch-'a']++;
        }

        for(int i=0;i<s.size(); i++){
            if(alpha[s[i]-'a'] == 1){
                return i;
            }
        }

        return -1;
    }

    int firstUniqChar1(string s) {
        vector<int>freq(26,0);
        queue<int>q;

        for(int i=0;i<s.size(); i++){
            freq[s[i]-'a']++;
            q.push(i);
        }

        while(!q.empty()){
            int idx = q.front();

            if(freq[s[idx]-'a']==1) return idx;

            q.pop();
        }

        return -1;
    }

};