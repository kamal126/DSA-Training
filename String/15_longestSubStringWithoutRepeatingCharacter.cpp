#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        vector<bool>count(256,false);
        
        int first=0, second=0, len=0;

        while(second<s.size()){

            while(count[s[second]]){
                count[s[first++]] = false;
                // first++;
            }

            count[s[second]] = true;
            len = max(len, second-first+1);
            second++;
        }

        return len;
    }
};

/*
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        vector<bool>count(256,false);
        
        int first=0, second=0, len=0;

        while(second<s.size()){

            while(count[s[second]]){
                count[s[first++]] = false;
                // first++;
            }

            count[s[second++]] = true;
            len = max(len, second-first);
            // second++;
        }

        return len;
    }
};
*/