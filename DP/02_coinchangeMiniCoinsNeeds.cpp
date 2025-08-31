
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int idx, vector<int> &coins, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 0;
        if (idx < 0 || sum < 0)
            return 1e9;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        if (coins[idx] > sum)
            return dp[idx][sum] = find(idx - 1, coins, sum, dp);
        else
            return dp[idx][sum] = min(1 + find(idx, coins, sum - coins[idx], dp), find(idx - 1, coins, sum, dp));
    }

    int minCoins(vector<int> &coins, int sum)
    {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        int ans = find(n - 1, coins, sum, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};
