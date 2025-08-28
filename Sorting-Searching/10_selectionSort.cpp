 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void selectionSort(vector<int>&arr){
        int n = arr.size();

        for(int i=0;i<n-1;i++){
            int mini = i;

            for(int j=i+1; j<n; j++){
                if(arr[j] < arr[mini])
                    mini = j;
            }

            swap(arr[i], arr[mini]);
        }
    }
};

int main(){
    Solution obj;

    vector<int> arr = {64, 25, 12, 22, 11};
    obj.selectionSort(arr);
    for(int i: arr) cout<<i<<" ";
    return 0;
}