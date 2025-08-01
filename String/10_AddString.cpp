#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans="";
        int i = num1.size()-1;
        int j = num2.size()-1;

        // while(i>=0 || j>=0 || carry){
        //     int x = i>=0 ? num1[i--]-'0' : 0;
        //     int y = j>=0 ? num2[j--]-'0' : 0;
        //     int sum = x+y+carry;
        //     carry = sum/10;
        //     ans += (sum%10 + '0');
        // }

        while(i>=0 && j>=0){
            int sum = (num1[i--]-'0') + (num2[j--]-'0') + carry;
            carry = sum/10;
            ans += (sum%10 + '0');
        }

        while(j>=0){
            int sum = (num2[j--]-'0') + carry;
            carry = sum/10;
            ans += (sum%10 + '0');
        }

        while(i>=0){
            int sum = (num1[i--]-'0') + carry;
            carry = sum/10;
            ans += sum%10 + '0';
        }

        if(carry) ans+='1';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};