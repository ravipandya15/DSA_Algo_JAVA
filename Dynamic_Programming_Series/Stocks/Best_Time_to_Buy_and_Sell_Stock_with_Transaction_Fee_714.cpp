#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}


// CN -> Rahul And His Chocolates

int solve(int index, int buy, vector<int>& prices, int n, int fee)
{
    // base case
    if (index == n) return 0;

    int profit = 0;
    if (buy == 1)
    {
        profit = max( -prices[index] + solve(index + 1, 0, prices, n, fee),
                            0 + solve(index + 1, 1, prices, n, fee) );
    }
    else
    {
        profit = max( prices[index] - fee + solve(index + 1, 1, prices, n, fee),
                            0 + solve(index + 1, 0, prices, n, fee));
    }

    return profit;
}

// Recusrion
// TC -> O(2^N)
// SC -> O(N)
int maxProfit_1(vector<int>& prices, int fee) {
    int n = prices.size();
    return solve(0, 1, prices, n, fee);
}

// Tabulation
// TC -> O(N * 2)
// SC -> O(N * 2)
int maxProfit_1(vector<int>& prices, int fee) {
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
                profit = max( prices[index] - fee + dp[index + 1][1],
                                0 + dp[index + 1][0] );
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

// Using 2 variables
// TC -> O(N * 2)
// SC -> O(1)
int maxProfit_1(vector<int>& prices, int fee) {
    int n = prices.size();

    // base case
    int aheadNotBuy = 0, aheadBuy = 0, currentNotBuy, currentBuy;
    for (int index = n-1; index >= 0; index--)
    {
        currentBuy = max( -prices[index] + aheadNotBuy,
                            0 + aheadBuy );
        currentNotBuy = max( prices[index] - fee + aheadBuy,
                            0 + aheadNotBuy );

        aheadNotBuy = currentNotBuy;
        aheadBuy = currentBuy;
    }

    return aheadBuy;
}