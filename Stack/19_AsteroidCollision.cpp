 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &astreroids) {
        vector<int>ans;
        stack<int>st;

        for(int ele : astreroids){
            if(ele >= 0) st.push(ele);
            else{
                while (!st.empty() && st.top()>=0 && st.top() < abs(ele)){
                    st.pop();
                }

                if(!st.empty()&& st.top()>=0 && st.top() == abs(ele))
                    st.pop();
                else if(st.empty() || st.top() < 0){
                    st.push(ele);
                }
                
            }
        }

        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }

        reverse(ans.begin(), ans.end());


        return ans;
    }
};

/**Asteroid Collision
Difficulty: MediumAccuracy: 50.06%Submissions: 40K+Points: 4Average Time: 30m
We are given an integer array asteroids of size N representing asteroids in a row. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are of same size, both will explode. Two asteroids moving in the same direction will never meet.
 

Example 1:

Input:
N = 3
asteroids[ ] = {3, 5, -3}
Output: {3, 5}
Explanation: The asteroid 5 and -3 collide resulting in 5. The 5 and 3 never collide.
Example 2:

Input:
N = 2
asteroids[ ] = {10, -10}
Output: { }
Explanation: The asteroid -10 and 10 collide exploding each other.
Your Task:
You don't need to read input or print anything. Your task is to complete the function asteroidCollision() which takes the array of integers asteroids and N as parameters and returns the state of asteroids after all collisions.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
-1000 ≤ asteroidsi  ≤ 1000
asteroids[i]!=0 */