 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        // Traverse through 1 to n
        for(int i=1;i<n;i++){
            int key = arr[i];
            int j = i-1;

            // Move elements of arr[0..i-1], that are greater than key,
            // to one position ahead of their current position
            while(j>=0 && arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            // Place key at after the element just smaller than it.
            arr[++j] = key;
        }
    }
};