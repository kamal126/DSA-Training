#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        bool flag = true;
        
        for(int i=0; i<=(s.size()-1)/2; i++){
            if(s[i]!=s[s.size()-1-i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

/*Palindrome String
Difficulty: EasyAccuracy: 51.21%Submissions: 413K+Points: 2
You are given a string s. Your task is to determine if the string is a palindrome. A string is considered a palindrome if it reads the same forwards and backwards.

Examples :

Input: s = "abba"
Output: true
Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.
Input: s = "abc" 
Output: false
Explanation: "abc" does not read the same forwards and backwards, so it is not a palindrome.
Input: s = "a"
Output: true
Explanation: A single-character string is always a palindrome.
Input: s = "acbca"
Output: true
Explanation: "acbca" reads the same forwards and backwards, so it is a palindrome.
Constraints:
1 ≤ s.size() ≤ 106
The string s contains only lowercase letters (a-z).

Expected Complexities
Company Tags
PaytmZohoMorgan StanleyAmazonD-E-ShawFactSetCiscoFacebook*/