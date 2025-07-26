#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        
        long long res = 0;
        long long p = 1;
        
        for(int start=0, end=0; end<n; end++){
            
            p *= arr[end];
            
            while(start<end && p>=k)
                p /= arr[start++];
                
            if(arr[start]<k)
                res += (end-start)+1;

        }
        
        return res;
    }
};
/*
[1,2,3,4] n = 4
res = 0
p = 1
start = 0
end = 0
n = 4
k = 10

i=0 j= 0 p=1
*/


// Brute Force Approach

// class Solution {
//   public:
//     long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
//         long long cnt = 0;
        
//         for(int i=0;i<n;i++){
//             if(arr[i]<k) cnt++;
//             long long product = arr[i];
//             for(int j=i+1;j<n;j++){
//                 product *= arr[j];
                
//                 if(product < k) cnt++;
//                 else break;
//             }
//         }
        
//         return cnt;
//     }
// };

/*class Solution {
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        
        long long cnt = 0;
        long long product = 1;
        
        for(int i=0, j=0;j<n;j++){
            
            product *= arr[j];
            
            while(i<j && product>=k)
                product /= arr[i++];
                
            if(arr[i]<k)
                cnt += (j-i)+1;

        }
        
        return cnt;
    }
};*/


/*
Subarrays Product Less than K
Difficulty: MediumAccuracy: 21.0%Submissions: 109K+Points: 4
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

Example 1:

Input : 
n = 4, k = 10
a[] = [1, 2, 3, 4]
Output : 
7
Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} 
{1, 2}, {1, 2, 3} and {2, 3}, in all these subarrays
product of elements is less than 10, count of
such subarray is 7.
{2,3,4} will not be a valid subarray, because 
2*3*4=24 which is greater than 10.
Example 2:

Input:
n = 7 , k = 100
a[] = [1, 9, 2, 8, 6, 4, 3]
Output:
16
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countSubArrayProductLessThanK() which takes the array a[], its size n and an integer k as inputs and returns the count of required subarrays.

Constraints:
1<=n<=106
1<=k<=1015
1<=a[i]<=105

Expected Complexities
Company Tags
Goldman Sachs Facebook Walmart Yatra.com Amazon Linkedin Microsoft Uber
  
*/