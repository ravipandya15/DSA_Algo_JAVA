#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// CN -> Stock Profits

int solve(int index, int buy, vector<int>& prices, int n)
{
    // base case
    if (index >= n) return 0;

    int profit = 0;
    if (buy == 1)
    {
        profit = max( -prices[index] + solve(index + 1, 0, prices, n),
                            0 + solve(index + 1, 1, prices, n) );
    }
    else
    {
        profit = max( prices[index] + solve(index + 2, 1, prices, n),
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
    if (index >= n) return 0;

    if (dp[index][buy] != -1) return dp[index][buy];

    if (buy == 1)
    {
        return dp[index][buy] = max( -prices[index] + solve_1(index + 1, 0, prices, n, dp),
                            0 + solve_1(index + 1, 1, prices, n, dp) );
    }
    else
    {
        return dp[index][buy] = max( prices[index] + solve_1(index + 2, 1, prices, n, dp),
                            0 + solve_1(index + 1, 0, prices, n, dp));
    }
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
int maxProfit_2(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    
    for (int index = n-1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
            {
                dp[index][buy] = max( -prices[index] + dp[index + 1][0],
                                    0 + dp[index + 1][1] );
            }
            else
            {
                dp[index][buy] = max( prices[index] + dp[index + 2][1],
                                    0 + dp[index + 1][0]);
            }
        }
    }

    return dp[0][1];
}

// Tabulation
// TC -> O(N)
// SC -> O(N)
int maxProfit_3(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    
    for (int index = n-1; index >= 0; index--)
    {
        dp[index][1] = max( -prices[index] + dp[index + 1][0],
                            0 + dp[index + 1][1] );
        dp[index][0] = max( prices[index] + dp[index + 2][1],
                            0 + dp[index + 1][0]);
    }

    return dp[0][1];
}

// Space optimization
// TC -> O(N)
// SC -> O(6) -> O(1)
int maxProfit_3(vector<int>& prices) {
    int n = prices.size();
    vector<int> front2(2, 0);
    vector<int> front1(2, 0);
    vector<int> cur(2, 0);
    
    for (int index = n-1; index >= 0; index--)
    {
        cur[1] = max( -prices[index] + front1[0],
                            0 + front1[1] );
        cur[0] = max( prices[index] + front2[1],
                            0 + front1[0]);

        front2 = front1;
        front1 = cur;
    }

    return cur[1]; // or front1[1]   front2[1] will not work
}

