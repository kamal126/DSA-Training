#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n) {
        long long max1=LLONG_MIN,max2=LLONG_MIN,max3=LLONG_MIN;
        long long  mini1=LLONG_MAX, mini2=LLONG_MAX;

        for(int i=0;i<n;i++){
            long long val = arr[i];
            if(val>max1){
                max3=max2;
                max2=max1;
                max1=val;
            }else if(val>max2){
                max3=max2;
                max2=val;
            }else if(val>max3){
                max3=val;
            }

            // mini1 annd mini2
            if(val<mini1){
                mini2 = mini1;
                mini1 = val;
            }else if(val <mini2){
                mini2 = val;
            }
        }

        return max(mini1*mini2*max1, max1*max2*max3);
    }
};

// class Solution {
//   public:
//     long long maxTripletProduct(long long arr[], int n) {
        
//         long long ans = INT_MIN;
        
//         sort(arr, arr+n);
        
//         return max(arr[0]*arr[1]*arr[n-1], arr[n-1]*arr[n-2]*arr[n-3]);
//     }
// };

/*
// User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n) {
        
        long long ans = INT_MIN;
        
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    ans = max(ans, arr[i]*arr[j]*arr[k]);
                }
            }
        }
        
        return ans;
    }
};
*/

/*
Maximum Triplet product
Difficulty: MediumAccuracy: 54.93%Submissions: 30K+Points: 4
Given an array arr of size n, the task is to find the maximum triplet product in the array.


Example 1:

Input:
n = 4
arr[] = {1, 2, 3, 5}
Output:
30
Explanation:
5*3*2 gives 30. This is the maximum possible
triplet product in the array.
Example 2:

Input:
n = 7
arr[] = {-3, -5, 1, 0, 8, 3, -2} 
Output:
120
Explanation: 
-3*-5*8 gives 120. This is the maximum possible triplet product in the array.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxTripletProduct() which takes an integer n and an array arr and returns the maximum triplet product in the array.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)


Constraints:
3 ≤ N ≤ 5*105
-106 ≤ A[i] ≤ 106
*/