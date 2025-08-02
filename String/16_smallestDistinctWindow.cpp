#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findSubString(string& str) {
        vector<int>alpha(26,0);
        int diff=0;
        for(char ch : str){
            if(alpha[ch-'a']==0)
                diff++;
            alpha[ch-'a']++;
        }
        // initilize vector by zero
        for(int i=0;i<26;i++)
            alpha[i]=0;

        int first=0, second=0, len=str.size();

        while(second<str.size()){

            while(diff && second<str.size()){
                if(alpha[str[second]-'a']==0){
                    diff--;
                }
                alpha[str[second]-'a']++;
                second++;
            }

            len = min(len, second-first);

            while(diff!=1){
                len = min(len, second-first);
                alpha[str[first]-'a']--;

                if(alpha[str[first]-'a']==0)
                    diff++;
                
                first++;
            }
        }
        return len;
    }
};