#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    /* Function to replace every element with the
    next greatest element */
    vector<int> nextGreatest(vector<int> arr) {
        int n = arr.size();
        vector<int>ans(n);
        ans[n-1] = -1;
        int i = n-1;
        int j = n-2;
        
        while(j>=0){
            if(arr[j]>arr[i]){
                int tmp = arr[i];
                while(i>j){
                    ans[i-1] = tmp;
                    i--;
                }
            }
            j--;
        }
        
        int tmp = arr[i];
        
        while(i>0){
            ans[i-1] = tmp;
            i--;
        }
        
        
        return ans;
        
    }
};

/*
arr = 16 17 4 3 5 2
algo:
1. n = arr.size();
2. take vector<int>ans[n];
3. initilize i=n-1, j=n-2;
4. while j>=0:
        if arr[j]>arr[i]:
            tmp = arr[i];
            while i>j:
                ans[i-1] = tmp;
                i--;
        sec--;
5.  END while;
6. tmp = arr[i];
7. while i>0:
        arr[i-1] = tmp;
        i--;
8. end while;
9. stop




Greater on right side

You are given an array arr. Replace every element with the next greatest element (the greatest element on its right side) in the array. Note: There is no element next to the last element, so replace it with -1.

Example:

Input: arr[] = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 5, 5, 2, -1]
Explanation: For 16 the greatest element 
on its right is 17. For 17 it's 5. 
For 4 it's 5. For 3 it's 5. For 5 it's 2. 
For 2 it's -1(no element to its right). 
Input: arr[] = [2, 3, 1, 9]
Output: [9, 9, 9, -1]
Explanation: For each element except 9 the
greatest element on its right is 9.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 105
1 <= arr[i]<= 106

*/