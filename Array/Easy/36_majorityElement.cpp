#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int candidate = -1;
        int cnt = 0;
        int n = arr.size();
        
        for(int num : arr){
            if(cnt==0){
                candidate = num;
                cnt++;
            }else if(num == candidate){
                cnt++;
            }else{
                cnt--;
            }
        }
        
        // validate karo 
        cnt = 0;
        for(int num : arr){
            if(num==candidate){
                cnt++;
            }
        }
        
        // n/2 se garter hai ya nahi
        return cnt > n/2 ? candidate : -1;
        
    }
};



/*
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int ans = -1, cnt=0;
        
        int start=0, end=0;
        while(end<n){
            int val = arr[start];
            if(arr[end]==val){
                cnt++;
                if(cnt>n/2)
                    return val;
                end++;
            }
            else{
                cnt = 1;
                start = end;
                end++;
            }
            
        }
        return -1;
    }
};

OR

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
                if (count > n / 2)
                    return arr[i];
            } else {
                count = 1;
            }
        }
        return -1; // Should never happen if a majority element is guaranteed
    }
};

*/

/*class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        int ans = -1;
        int val = -1;
        for(int i=0;i<n;i++){
            int ele = arr[i];
            int tmp = 0;
            for(int j=0;j<n;j++){
                if(arr[j]==ele){
                    tmp++;
                }
            }
            if(tmp>n/2 && ans<tmp){
                ans = tmp;
                val = ele;
            }
        }
        return val;
    }
};
*/

/*Majority Element
Difficulty: MediumAccuracy: 27.82%Submissions: 741K+Points: 4Average Time: 59m
Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.

Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

Examples:

Input: arr[] = [1, 1, 2, 1, 3, 5, 1]
Output: 1
Explanation: Since, 1 is present more than 7/2 times, so it is the majority element.
Input: arr[] = [7]
Output: 7
Explanation: Since, 7 is single element and present more than 1/2 times, so it is the majority element.
Input: arr[] = [2, 13]
Output: -1
Explanation: Since, no element is present more than 2/2 times, so there is no majority element.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

Expected Complexities
Company Tags
FlipkartAccoliteAmazonMicrosoftD-E-ShawGoogleNagarroAtlassian
*/