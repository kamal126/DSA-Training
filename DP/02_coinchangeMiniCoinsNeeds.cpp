
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

    // ================== space optimization =======================
    int minCoins(vector<int> &coins, int sum)
    {
        int n = coins.size();

        vector<int> dp(sum + 1, 1e9);

        dp[0] = 0;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (coins[i] <= j)
                {
                    dp[j] = min(1 + dp[j - coins[i]], dp[j]);
                }
            }
        }

        return dp[sum] >= 1e9 ? -1 : dp[sum];
    }


    // =============== Bottom Up =====================================
    // int minCoins(vector<int> &coins, int sum){
    //     int n = coins.size();

    //     vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 1e9));

    //     for(int i=0;i<=n;i++) dp[i][0] = 0;

    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=sum;j++){
    //             if(coins[i]>j){
    //                 dp[i][j] = dp[i-1][j];
    //             }else{
    //                 dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
    //             }
    //         }
    //     }

    //     return dp[n][sum] >= 1e9 ? -1 : dp[n][sum];
    // }



    // ======================= recursive DP ============================
    // int minCoins(vector<int> &coins, int sum)
    // {
    //     int n = coins.size();

    //     vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    //     int ans = find(n - 1, coins, sum, dp);

    //     return ans >= 1e9 ? -1 : ans;
    // }
};

int main(){
    Solution obj;

    vector<int>coins = {20,10,5}; int sum = 30;
    vector<int>coins1 = {2,4,17,2,1,19}; int sum1 = 39;
    vector<int>coins2 = {9,6,5,1}; int sum2 = 19;
    vector<int>coins3 = {2, 5, 7, 12, 15, 16}; int sum3 = 1;

    int ans1 = obj.minCoins(coins, sum);
    int ans2 = obj.minCoins(coins1, sum1);
    int ans3 = obj.minCoins(coins2, sum2);
    int ans4 = obj.minCoins(coins3, sum3);

    cout<<"ans1 :"<<ans1<<endl;
    cout<<"ans2 :"<<ans2<<endl;
    cout<<"ans3 :"<<ans3<<endl;
    cout<<"ans4 :"<<ans4<<endl;

    return 0;
}
