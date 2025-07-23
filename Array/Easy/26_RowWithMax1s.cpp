#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        
        int idx = -1;
        int j=col-1;
        
        for(int i=0;i<row;i++){
            while(j>=0 && arr[i][j]==1){
                idx = i;
                j--;
            }
        }
        return idx;
    }
};

/*
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        
        int ans = INT_MIN;
        int idx;
        for(int i=0;i<row;i++){
            
            int start=0, end=col-1;
            while(start<=end){
                int mid = start + (end-start)/2;
                
                if(arr[i][mid]==0){
                    start = mid+1;
                }else{
                    if(ans<(col-mid)){
                        idx = i;
                        ans = col-mid;
                    }
                    end = mid-1;
                }
            }
        }
        
        return ans==INT_MAX ? -1 : idx;
    }
};
*/

/*

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        int count=0;
        int idx=-1;
        for(int i=0;i<row;i++){
            int cnt=0;
            for(int j=0;j<col;j++){
                if(arr[i][j]==1){
                    cnt++;
                }
            }
            if(count<cnt){
                count = cnt;
                idx = i;
            }
            // count = max(count,cnt);
        }
        
        return idx;
    }
};
*/

/*
Row with max 1s
Difficulty: MediumAccuracy: 33.09%Submissions: 352K+Points: 4
You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.
Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.
Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
Input: arr[][] = [[0,0], [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.
Constraints:
1 ≤ arr.size(), arr[i].size() ≤ 103
0 ≤ arr[i][j] ≤ 1 
*/