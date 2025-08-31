#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int idx, vector<int> &coins, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 1; // valid way
        if (idx < 0 || sum < 0)
            return 0; // no coins left or overshoot

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        if (coins[idx] > sum)
        {
            return dp[idx][sum] = find(idx - 1, coins, sum, dp);
        }
        else
        {
            return dp[idx][sum] = find(idx, coins, sum - coins[idx], dp) + find(idx - 1, coins, sum, dp);
        }
    }

    int count(vector<int> &coins, int sum)
    {
        int n = coins.size();
        // recursive and memoization
        // vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        // find(idx, coins, sum, dp);

        // Bottom Up
        /*
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, 0));

        // Base case: one way to make sum=0
        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
        }

        // return find(n-1, coins, sum, dp);
        return dp[n][sum];
        */

        // space optimized
        vector<int>dp(sum+1,0);
        dp[0]=1;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=sum;j++)
                if(coins[i-1]<=j)
                    dp[j] += dp[j-coins[i-1]];

        return dp[sum];
    }
};

int main()
{
    Solution obj;

    vector<int> coins = {1, 2, 3};
    int sum = 4;

    int count = obj.count(coins, sum);

    cout << count << " ";

    return 0;
}
