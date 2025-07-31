#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>alpha(26,0);

        for(char ch : sentence){
            alpha[ch-'a'] = 1;
        }

        for(int i=0;i<26;i++){
            if(alpha[i]!=1){
                return false;
            }
        }

        return true;
    }
};