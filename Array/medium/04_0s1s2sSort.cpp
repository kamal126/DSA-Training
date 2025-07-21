/*
Sort 0s, 1s and 2s
Difficulty: MediumAccuracy: 50.58%Submissions: 788K+Points: 4Average Time: 10m
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

You need to solve this problem without utilizing the built-in sort function.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2

Expected Complexities
Company Tags
PaytmFlipkartMorgan StanleyAmazonMicrosoftOYO RoomsSamsungSnapdealHikeMakeMyTripOla CabsWalmartMAQ SoftwareAdobeYatra.comSAP LabsQualcomm
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int zero=0, one=0,two=0;
      
        for(int ele : arr){
            if(ele==0) zero++;
            else if(ele==1) one++;
            else two++;
        }
        
        int i=0;
        
        for(i;i<zero;i++) arr[i] = 0;
        for(i;i<zero+one;i++) arr[i] = 1;
        for(i;i<zero+one+two;i++) arr[i] = 2;
        
    }
};
