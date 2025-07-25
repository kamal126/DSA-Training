#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

/*Reverse a String
Difficulty: BasicAccuracy: 69.49%Submissions: 416K+Points: 1Average Time: 15m
You are given a string s, and your task is to reverse the string.

Examples:

Input: s = "Geeks"
Output: "skeeG"
Input: s = "for"
Output: "rof"
Input: s = "a"
Output: "a"
Constraints:
1 <= s.size() <= 106
s contains only alphabetic characters (both uppercase and lowercase).*/
