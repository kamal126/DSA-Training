/*
Triplets with Smaller Sum
Difficulty: MediumAccuracy: 40.33%Submissions: 96K+Points: 4
Given an array arr[] of distinct integers of size n and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


Examples :


Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
Input: n = 5, sum = 12, arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with sum less than 12 (1, 3, 4), (1, 3, 5), (1, 3, 7) and (1, 4, 5).
Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(1).


Constraints:
3 ≤ N ≤ 103
-103 ≤ arr[i] ≤ 103
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr, arr+n);

        long long count=0;
        
        for(int i=0;i<n-2;i++){
            int j=i+1, k=n-1;
            
            while(j<k){
                if(arr[i]+arr[j]+arr[k]>=sum){
                    k--;
                }else{
                    count += (k-j);
                    j++;
                }
            }
        }
        return count;
    }
};

/*
class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        long long count=0;
        
        for(int i=0;i<n-2;i++)
            for(int j=i+1;j<n-1;j++)
                for(int k=j+1;k<n;k++)
                    if(arr[i]+arr[j]+arr[k] < sum)
                        count++;
                
            
        return count;
    }
};

*/