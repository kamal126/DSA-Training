#include<bits/stdc++.h>
using namespace std;

// Using Kadane;s Algorithm O(n) and O(1)

class Solution {
    public:

    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();

        int sum = accumulate(begin(arr), end(arr), 0);
        int minSum=arr[0];
        int maxSum=arr[0], circularSum=0;
        int sum2 = arr[0], sum1 = arr[0];
        for(int i = 0; i < n; i++){

            sum1 = max(sum+arr[i], arr[i]);
            maxSum = max(maxSum, sum1);

            sum2 = min(sum2+arr[i], arr[i]);
            minSum = min(minSum, sum2);
        }

        circularSum = sum - minSum;

        if(minSum>0){
            return max(maxSum, circularSum);
        }

        return maxSum;
    }
};


// class Solution {
//   public:
    
//     int kadanesMax(vector<int>arr, int n){
//         int sum = arr[0];
//         int maxSum = arr[0];
        
//         for(int i=1;i<n;i++){
//             sum = max(sum+arr[i], arr[i]);
//             maxSum = max(maxSum, sum);
//         }
//         return maxSum;
//     }
    
//     int kadanesMin(vector<int>arr, int n){
//         int sum = arr[0];
//         int minSum = arr[0];
        
//         for(int i=1;i<n;i++){
//             sum = min(sum+arr[i], arr[i]);
//             minSum = min(minSum, sum);
//         }
//         return minSum;
//     }
    
//     int maxCircularSum(vector<int> &arr) {
//         int n = arr.size();
//         // 1. sum
//         int sum = accumulate(begin(arr), end(arr), 0);
//         // 2. minSum
//         int minSum = kadanesMin(arr, n);
//         // 3. maxSum
//         int maxSum = kadanesMax(arr, n);
//         // 4. circularSum
//         int circularSum = sum - minSum;
        
//         if(maxSum>0){
//             return max(maxSum, circularSum);
//         }
        
//         return maxSum;
//     }
// };






// [Naive Approach] Considering All Possible Subarrays – O(n^2) Time and O(1) Space
// class Solution {
//   public:
//     int maxCircularSum(vector<int> &arr) {
        
//         int n = arr.size();
//         int res = arr[0];
        
//         for(int i=0;i<n;i++){
//             int curr_sum = 0;
            
//             for(int j=0;j<n;j++){
//                 int idx = (i+j)%n;
//                 curr_sum += arr[idx];
//                 res = max(res, curr_sum);
//             }
//         }
        
//         return res;
//     }
// };
// 