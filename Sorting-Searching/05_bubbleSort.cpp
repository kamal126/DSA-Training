 
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    void bubbleSort(vector<int>&arr){
        int n = arr.size();

        // Traverse through all array elements
        for(int i=0;i<n;i++){
            bool swapped = false;
            // Last i elements are already sorted
            for(int j=1;j<n-i;j++){
                if(arr[j-1] > arr[j]){
                    swapped = true;
                    swap(arr[j-1], arr[j]);
                }
            }

            // If no two elements were swapped by inner loop, then break
            if(!swapped) break;
        }
    }
};

int main(){
    Solution obj;
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    obj.bubbleSort(arr);
    for(int i: arr) cout<<i<<" ";
    return 0;
}// Bubble Sort Algorithm