#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// CN -> Selling Stock

int solve(int index, int buy, vector<int>& prices, int n)
{
    // base case
    if (index == n) return 0;

    int profit = 0;
    if (buy == 1)
    {
        profit = max( -prices[index] + solve(index + 1, 0, prices, n),
                            0 + solve(index + 1, 1, prices, n) );
    }
    else
    {
        profit = max( prices[index] + solve(index + 1, 1, prices, n),
                            0 + solve(index + 1, 0, prices, n));
    }

    return profit;
}

// Recusrion
// TC -> O(2^N)
// SC -> O(N)
int maxProfit_1(vector<int>& prices) {
    int n = prices.size();
    return solve(0, 1, prices, n);
}

int solve_1(int index, int buy, vector<int>& prices, int n, vector<vector<int>> &dp)
{
    // base case
    if (index == n) return 0;

    if (dp[index][buy] != -1) return dp[index][buy];

    int profit = 0;
    if (buy == 1)
    {
        profit = max( -prices[index] + solve_1(index + 1, 0, prices, n, dp),
                            0 + solve_1(index + 1, 1, prices, n, dp) );
    }
    else
    {
        profit = max( prices[index] + solve_1(index + 1, 1, prices, n, dp),
                            0 + solve_1(index + 1, 0, prices, n, dp));
    }

    return dp[index][buy] = profit;
}

// Memoization
// TC -> O(N * 2)
// SC -> O(N * 2) + O(N)
int maxProfit_2(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve_1(0, 1, prices, n, dp);
}

// Tabulation
// TC -> O(N * 2)
// SC -> O(N * 2)
int maxProfit_3(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    // base case
    dp[n][0] = dp[n][1] = 0;

    for (int index = n-1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy == 1)
            {
                profit = max( -prices[index] + dp[index + 1][0],
                                0 + dp[index + 1][1] );
            }
            else
            {
                profit = max( prices[index] + dp[index + 1][1],
                                0 + dp[index + 1][0] );
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

// Space optimization
// TC -> O(N * 2)
// SC -> O(2)
int maxProfit_4(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2);

    // base case
    ahead[0] = ahead[1] = 0;

    for (int index = n-1; index >= 0; index--)
    {
        vector<int> cur(2);
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy == 1)
            {
                profit = max( -prices[index] + ahead[0],
                                0 + ahead[1] );
            }
            else
            {
                profit = max( prices[index] + ahead[1],
                                0 + ahead[0] );
            }

            cur[buy] = profit;
        }
        ahead = cur;
    }

    return ahead[1];
}

// Using 2 variables
// TC -> O(N * 2)
// SC -> O(1)
int maxProfit_5(vector<int>& prices) {
    int n = prices.size();

    // base case
    int aheadNotBuy = 0, aheadBuy = 0, currentNotBuy, currentBuy;
    for (int index = n-1; index >= 0; index--)
    {
        currentBuy = max( -prices[index] + aheadNotBuy,
                            0 + aheadBuy );
        currentNotBuy = max( prices[index] + aheadBuy,
                            0 + aheadNotBuy );

        aheadNotBuy = currentNotBuy;
        aheadBuy = currentBuy;
    }

    return aheadBuy;
}

// Easiest Approach
// TC -> O(N)
// SC -> O(1)
int maxProfit_6(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i-1])
        {
            profit += prices[i] - prices[i-1];
        }
    }
    return profit;
}