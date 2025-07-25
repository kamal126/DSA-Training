#include<bits/stdc++.h>
using namespace std;

class Solution {

  public:
    int Maximum_Sum(vector<vector<int>> &mat, int N, int K) {
        int ans = INT_MIN;
        vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                prefix[i][j] = mat[i-1][j-1] 
                            +prefix[i-1][j] 
                            +prefix[i][j-1] 
                            -prefix[i-1][j-1];
            }
        }
        
        for(int i = K; i<=N; i++){
            for(int j = K; j<=N; j++){
                int total = prefix[i][j]
                          - prefix[i - K][j]
                          - prefix[i][j - K]
                          + prefix[i - K][j - K];  
                ans = max(ans, total);
            }
        }
        
        return ans;
        
    }
};

/*
class Solution {

  public:
    int Maximum_Sum(vector<vector<int>> &mat, int N, int K) {
        int ans = INT_MIN;
        
        for(int i=0; i<=N-K; i++)
        for(int j=0; j<=N-K; j++){
            int sum = 0;
            
            for(int a = i; a<i+K; a++)
            for(int b = j; b<j+K; b++)
                sum += mat[a][b];
            
            ans = max(ans, sum);
        }
        return ans;
        
    }
};
*/

/*
Coins of Geekland
Difficulty: MediumAccuracy: 51.4%Submissions: 9K+Points: 4
In Geekland there is a grid of coins of size N x N. You have to find the maximum sum of coins in any sub-grid of size K x K.
Note: Coins of the negative denomination are also possible at Geekland.

Example 1:

Input: N = 5, K = 3 
mat[[]] = {1, 1, 1, 1, 1} 
          {2, 2, 2, 2, 2} 
          {3, 8, 6, 7, 3} 
          {4, 4, 4, 4, 4} 
          {5, 5, 5, 5, 5}
Output: 48
Explanation: {8, 6, 7}
             {4, 4, 4}
             {5, 5, 5}
has the maximum sum

Example 2:

Input: N = 1, K = 1
mat[[]] = {{4}} 
Output: 4
Your Task:  
You don't need to read input or print anything. Complete the function Maximum_Sum() which takes the matrix mat[], size of Matrix N, and value K as input parameters and returns the maximum sum.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ K ≤ N ≤ 103
-5*105 ≤ mat[i][j] ≤ 5*105

Company Tags
Adobe
*/