
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return 1 + find(i - 1, j - 1, s1, s2, dp);
        else
            return max(find(i - 1, j, s1, s2, dp), find(i, j - 1, s1, s2, dp));
    }
    // int find(int i, int j, string &s1, string &s2){
    //     if(i==0 || j==0) return 0;

    //     if(s1[i-1]==s2[j-1])
    //         return 1 + find(i-1, j-1, s1, s2);
    //     else
    //         return max(find(i-1, j, s1, s2), find(i, j-1, s1, s2));

    // }

    // ================ Bottom UP approach ===========================
    int lcs(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<int> dp(m + 1, 0);

        int prevDiag, temp;
        for (int i = 1; i <= n; i++)
        {
            prevDiag = 0;   // This will hold the value of dp[i-1][j-1] in the 2D array
            for (int j = 1; j <= m; j++)
            {
                temp = dp[j];   // Store the current dp[j] which is dp[i-1][j] before updating it
                if (s1[i - 1] == s2[j - 1])
                    dp[j] = 1 + prevDiag;
                else
                    dp[j] = max(dp[j], dp[j - 1]);

                prevDiag = temp;    // shifted diagonal value
            }
        }

        return dp[m];
    }
    // int lcs(string &s1, string &s2){
    //     int n = s1.size();
    //     int m = s2.size();

    //     vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    //     for(int i=1;i<=n;i++)
    //     for(int j=1;j<=m;j++){
    //         if(s1[i-1]==s2[j-1])
    //             dp[i][j] = 1 + dp[i-1][j-1];
    //         else
    //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //     }

    //     return dp[n][m];
    // }

    // int lcs(string &s1, string &s2){
    //     int n = s1.size();
    //     int m = s2.size();

    //     vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    //     return find(n, m, s1, s2, dp);
    // }
};

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDEHR";
    Solution obj;
    cout << obj.lcs(s1, s2);
    return 0;
}