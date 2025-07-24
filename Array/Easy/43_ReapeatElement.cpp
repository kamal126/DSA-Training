#include<bits/stdc++.h>
using namespace std;
int repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;

    // First pass: find possible candidates
    for (int num : A) {
        if (num == num1) {
            count1++;
        } else if (num == num2) {
            count2++;
        } else if (count1 == 0) {
            num1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            num2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    

    // Second pass: verify the candidates
    count1 = count2 = 0;
    for (int num : A) {
        if (num == num1) count1++;
        else if (num == num2) count2++;
    }

    if (count1 > n / 3) return num1;
    if (count2 > n / 3) return num2;
    return -1;
}
