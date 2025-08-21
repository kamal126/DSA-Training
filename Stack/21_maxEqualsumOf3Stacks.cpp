 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2,vector<int> &S3) {
        stack<int>st1, st2, st3;
        int sum1=0, sum2=0, sum3=0;
        
        for(int i=N1-1; i>=0;--i){
            st1.push(S1[i]);
            sum1 += S1[i];
        }
        for(int i=N2-1; i>=0;--i){
            st2.push(S2[i]);
            sum2 += S2[i];
        }
        for(int i=N3-1; i>=0;--i){
            st3.push(S3[i]);
            sum3 += S3[i];
        }

        while(!st1.empty() && !st2.empty() && st3.empty()){
            if(sum1==sum2 && sum2==sum3) return sum1;

            if(sum1>=sum2 && sum1>=sum3){
                sum1 -= st1.top();
                st1.pop();
            }else if(sum2>=sum1 && sum2>=sum3){
                sum2 -= st2.top();
                st2.pop();
            }else{
                sum3 -= st3.top();
                st3.pop();
            }
        }

        return 0;
    }
};

// 9536017460

/** @author Kamal chandra
 *  Approach O(1) sapce and O(N1 + N2 + N3) */

class Solution {
  public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2,vector<int> &S3) {
        int sum1=0, sum2=0, sum3=0;

        for(int ele : S1) sum1 += ele;
        for(int ele : S2) sum2 += ele;
        for(int ele : S3) sum3 += ele;

        int i=0,j=0,k=0;
        while(i<N1 && j<N2 && k<N3){
            if(sum1==sum2 && sum2==sum3) return sum1;

            if(sum1>=sum2 && sum1>=sum3){
                sum1 -= S1[i++];
            }else if(sum2>=sum1 && sum2>=sum3){
                sum2 -= S2[j++];
            }else{
                sum3 -= S3[k++];
            }
        }

        return 0;
    }
};