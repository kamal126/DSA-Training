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
};