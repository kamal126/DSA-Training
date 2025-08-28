 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int,int>mp;

        for(int ele : a) mp[ele]++;

        // Check for each element in b if it exists in the map with non-zero count
        for(int ele : b){
            // If element not found or count is zero, b is not a subset of a
            if(mp.find(ele) == mp.end() || mp[ele]==0)
                return false;
            // Decrease the count of the element in the map
            mp[ele]--;
        }

        return true;
    }
};