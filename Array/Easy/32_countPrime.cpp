#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<int>visited(n,0);

        for(int i = 2; i*i < n; i++){
            if(visited[i] == 0){
                for(int j = i*i; j < n; j += i){
                    visited[j] = 1;
                }
            }
        }
        int cnt=0;
        for(int i = 2;i < n; i++){
            if(visited[i] == 0){
                cnt++;
            }
        }

        return cnt;
    }
};

/*
204. Count Primes
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,090,519/3.1M
Acceptance Rate
35.0%
Topics
icon
Companies
Hint 1
Checking all the integers in the range [1, n - 1] is not efficient. Think about a better approach.
Hint 2
Since most of the numbers are not primes, we need a fast approach to exclude the non-prime integers.
Hint 3
Use Sieve of Eratosthenes.
*/