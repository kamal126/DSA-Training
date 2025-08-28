 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstAndLast(int x, vector<int> &arr) {
        int n = arr.size();
        int first = -1, last = -1;

        // Finding first occurrence
        int start = 0, end = n - 1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid]==x){
                first = mid;
                end = mid - 1;
            }else if(arr[mid] > x){
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
        // Finding last occurrence

        start = 0, end = n - 1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid]==x){
                last = mid;
                start = mid + 1;
            }else if(arr[mid] > x){
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }

        if(first == -1 && last == -1) return {-1};

        return {first, last};
    }
};

int main(){
    Solution obj;
    vector<int>arr = {5,7,7,8,8,10};
    int x = 8;
    vector<int>ans = obj.firstAndLast(x, arr);
    for(int i: ans) cout<<i<<" ";
}