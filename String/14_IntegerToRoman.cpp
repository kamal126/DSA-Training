/*
| Calculation                                   | Value              |
| --------------------------------------------- | ------------------ |
| num = 1987                                    |                    |
| num / 1000 = 1                                | thousand\[1] = "M" |
| (num % 1000) / 100 = (987) / 100 = 9          | hundred\[9] = "CM" |
| (num % 100) / 10 = (87) / 10 = 8              | tens\[8] = "LXXX"  |
| num % 10 = 7                                  | ones\[7] = "VII"   |
| Final Roman = "M" + "CM" + "LXXX" + "VII"     | "MCMLXXXVII"       |

*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string intToRoman(int num){

        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hunds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thous[] = {"", "M", "MM", "MMM"};

        // assume 1897: 
        return thous[num/1000] +        // 1897/1000 = 1    -> M
                hunds[(num%1000)/100] +     // (897%1000)/100 = 897/100 = 8 -> DCCC
                tens[(num%100)/10] +    // (97%100)/10 = 97/10 = 9  -> XC
                ones[num%10];           // 9%10 = 9     -> IX
                                                            // MDCCCXCIX
        
    }
};
