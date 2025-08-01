#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int>lower(26,0), upper(26,0);

        for(int i=0; i<s.size(); i++){
            if(s[i]>='a'){
                lower[s[i]-'a']++;
            }else{
                upper[s[i]-'A']++;
            }
        }

        int count = 0;
        bool odd = 0;

        for(int i=0; i<26; i++){
            // lower
            if(lower[i]%2==0){
                count += lower[i];
            }else{
                count += lower[i]-1;
                odd = 1;
            }
            // upper
            if(upper[i]%2==0){
                count += upper[i];
            }else{
                count += upper[i]-1;
                odd = 1;
            }
        }

        return count + odd;
    }
};

/*
409. Longest Palindrome
Solved
Easy
Topics
premium lock icon
Companies
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.*/