#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        // int n = arr.size();
        
        vector<int>pos;
        vector<int>neg;
        
        for(int ele : arr){
            if(ele<0) neg.push_back(ele);
            else pos.push_back(ele);
        }
        
        int i = 0;
       for(int ele : pos){
           arr[i] = ele;
           i++;
       }
       
        for(int ele : neg){
            arr[i] = ele;
            i++;
        }
        
    }
};

// pos : 1 3 2 11 6
// neg : -1 -7 -5 

// arr : 1 3 2 11 6 -1 -7 -5

/*
Move all negative elements to end
Given an unsorted array arr[ ] having both negative and positive integers. The task is to place all negative elements at the end of the array without changing the order of positive elements and negative elements.

Note: Don't return any array, just in-place on the array.

Examples:

Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
Output : [1, 3, 2, 11, 6, -1, -7, -5]
Explanation: By doing operations we separated the integers without changing the order.
Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
Output : [7, 9, 10, 11, -5, -3, -4, -1]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size ≤ 106
-109 ≤ arr[i] ≤ 109
*/