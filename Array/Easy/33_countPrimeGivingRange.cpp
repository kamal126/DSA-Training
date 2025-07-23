
#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int countPrimes(int L, int R) {
       if (R <= 2) return 0;
        
        vector<int>visited(R+1,0);
        visited[0]=1, visited[1]=1;

        for(int i=2; i*i<=R; i++){
            if(visited[i]==0){
                for(int j=i*i; j<=R; j+=i){
                    visited[j]=1;
                }
            }
        }
        int cnt=0;
        
        for(int i = max(2,L); i <= R; i++){
            if(visited[i] == 0){
                cnt++;
            }
        }
        
        return cnt;
    }
};

/*
Count Primes In Range
Difficulty: EasyAccuracy: 40.37%Submissions: 14K+Points: 2
Given two numbers L and R(L<R). Count all the prime numbers in the range [L, R].

Example 1:

Input:
L=1,R=10
Output:
4
Explanation:
There are 4 primes in this range, 
which are 2,3,5 and 7.
Example 2:

Input:
L=5,R=10
Output:
2
Explanation:
There are 2 primes in this range, 
which are 5 and 7.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPrimes() which takes the two integers L and R as input parameters and returns the number of prime numbers in the range [L, R].


Expected Time Complexity:O(RLogLog(R))
Expected Auxillary Space:O(R)


Constraints:
1<=L<R<=2*105
*/