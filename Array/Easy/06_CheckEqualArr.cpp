#include<bits/stdc++.h>
using namespace std;


// User function template for C++

class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        
        if(a.size()!= b.size()) return 0;
        unordered_map<int, int>m;
        
        for(int i=0;i<a.size();i++){
            m[a[i]]++;
        }
        
        for(int i=0;i<b.size();i++){
            if(m[b[i]]>=1){ // agar present hai map mai to 
                m[b[i]]--;  // 1 decrease kar do
            }else{
                return 0;   // 
            }
        }
        
        return 1;
    }
};


// 1 5 2 4 6 2
// 4 2 1 5 6

// 1 1
// 5 1
// 2 2
// 4 1
// 6 1


/*
Check Equal Arrays
Difficulty: EasyAccuracy: 42.18%Submissions: 396K+Points: 2Average Time: 30m
Given two arrays a[] and b[] of equal size, the task is to find whether the elements in the arrays are equal.

Two arrays are said to be equal if both contain the same set of elements, arrangements (or permutations) of elements may be different though.

Note: If there are repetitions, then counts of repeated elements must also be the same for two arrays to be equal.

Examples:

Input: a[] = [1, 2, 5, 4, 0], b[] = [2, 4, 5, 0, 1]
Output: true
Explanation: Both the array can be rearranged to [0,1,2,4,5]
Input: a[] = [1, 2, 5], b[] = [2, 4, 15]
Output: false
Explanation: a[] and b[] have only one common value.
Constraints:
1<= a.size(), b.size()<=107
0<=a[i], b[i]<=109
*/