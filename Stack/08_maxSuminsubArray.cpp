#include<bits/stdc++.h>
using namespace std;


    int maxSum(vector<int>& arr) {
        int n = arr.size();
        
        // find two consecutive elements with maximum sum
        int res = arr[0] + arr[1];
        for (int i = 1; i < n - 1; i++)
            res = max(res, arr[i] + arr[i + 1]);

        return res;
    }
    
int main() {
    
    vector<int> arr = { 5, 4, 3, 1, 6 };
    int result = maxSum(arr);
    cout << result << endl;
    
}