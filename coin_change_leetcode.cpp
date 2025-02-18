// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// MASHRUF's work

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define mp make_pair
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define endl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;

    for (auto coin : coins)
    {
        for (int j = coin; j <= amount; j++)
        {
            dp[j] = min(dp[j], 1 + dp[j - coin]);
        }
    }
    return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
}

int main()
{
    fast();
    int count;
    cin >> count;
    vector<int> coins(count);
    for (int i = 0; i < count; i++)
    {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    int ans = coinChange(coins, amount);
    cout << ans << endl;

    return 0;
}

// another approach

int coinChange(vector<int> &w, int s)
{
    int n = w.size();
    int dp[n + 1][s + 1];

    dp[0][0] = 0;
    for (int i = 1; i <= s; i++)
        dp[0][i] = INT_MAX - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - w[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][s] == INT_MAX - 1)
        return -1;
    else
        return dp[n][s];
}

int main()
{
    fast();
    int count;
    cin >> count;
    vector<int> coins(count);
    for (int i = 0; i < count; i++)
    {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    int ans = coinChange(coins, amount);
    cout << ans << endl;

    return 0;
}
