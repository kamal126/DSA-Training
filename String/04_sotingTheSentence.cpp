#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string>order(9);

        string tmp="";

        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                tmp += s[i];
            }else{
                int pos = tmp.back()-'1';
                tmp.pop_back();
                order[pos] = tmp;
                tmp = "";
            }
        }

        // handle last 
        if(!tmp.empty()){
            int pos = tmp.back()-'1';
            tmp.pop_back();
            order[pos] = tmp;
        }

        string ans = "";
        for(int i=0;i<9;i++){
            if(!order[i].empty()){
                ans += order[i]+" ";
            }
        }

        // remove back extra space (trailing space)

        if(!ans.empty())
            ans.pop_back();

        return ans;
    }
};