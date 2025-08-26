 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        vector<int>freq(26,0);
        queue<int>q;
        string ans="";

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;

            if(freq[s[i]-'a']==1) q.push(i);

            while(!q.empty() && freq[s[q.front()]-'a'] > 1) q.pop();

            if(q.empty()) 
                ans += '#';
            else
                ans += s[q.front()];
        }

        return ans;
    }
};