 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int n;
    
    int find(int i, int j, string &s1, string &s2){
        if(i==n || j==n) return 0;
        
        if(i!=j && s1[i]==s2[j]){
            return max(1+find(i+1, j+1, s1, s2), 
            max(find(i, j+1, s1, s2), find(i+1, j, s1, s2)));
        }else{
            return max(find(i, j+1, s1, s2), find(i+1, j, s1, s2));
        }
    }
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        n = s.size();
        
        return find(0,0,s,s);
    }
};

int main(){
    string s1 = "axxzxy";
    string s2 = "axxxy";
    
    Solution obj;

    cout<<obj.LongestRepeatingSubsequence(s1)<<endl;
    cout<<obj.LongestRepeatingSubsequence(s2)<<endl;

    return 0;
}