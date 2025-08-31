 
#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    int digitSum(int n){
        int sum = 0;
        n = abs(n);
        while(n>0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }

    long long numberCount(long long N, long long K){
        int start=0, end=N, idx=-1;

        while(start<=end){
            long long mid = start + (end-start)/2;

            if(mid - digitSum(mid) >= K){
                idx = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return idx == -1 ? -1 : N-idx+1;
    }
};