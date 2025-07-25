#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    long long int totalFine(int date, vector<int> &car, vector<int> &fine) {
        // code here
        int n = car.size();
        int i = 0;
        
        long long int panality = 0;
        while(i<n){
            if(date%2==0){
                if(car[i]%2!=0){
                    panality += fine[i];
                }
            }else{
                if(car[i]%2==0){
                    panality += fine[i];
                }
            }
            i++;
        }
        return panality;
    }
};

/*
Find the fine

Given an array of car numbers car[], an array of penalties fine[], and an integer value date. The task is to find the total fine which will be collected on the given date. The fine is collected from odd-numbered cars on even dates and vice versa.

Examples:

Input: date = 12, car[] = [2375, 7682, 2325, 2352], fine[] = [250, 500, 350, 200]
Output: 600
Explanation: The date is 12 (even), so we collect the fine from odd-numbered cars. The odd-numbered cars and the fines associated with them are as follows:
2375 -> 250
2325 -> 350
The sum of the fines is 250+350 = 600
Input: date = 8, car[] = [2222, 2223, 2224], fine[] = [200, 300, 400]
Output: 300
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= car.size <= 105
1 <= car[i], fine[i], date <= 105
*/