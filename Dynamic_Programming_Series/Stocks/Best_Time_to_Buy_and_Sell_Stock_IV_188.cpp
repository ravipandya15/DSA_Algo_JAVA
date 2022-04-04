#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// CN -> Best Time To Buy and Sell Stock

// Tabulation
// TC -> O(N * 2 * k)
// SC -> O(N * 2 * k)
int maxProfit_1(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    // base case -> not required as vector is already initialized with 0
    // if (index == n || cap == 0) return 0;

    for (int index = n-1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++) // cap == 0 is covered in base case
            {
                if (buy == 1)
                {
                    dp[index][buy][cap] = max( ( -prices[index] + dp[index + 1][0][cap] ), 
                                             ( 0 + dp[index + 1][1][cap] ) );
                }
                else // sell
                {
                    dp[index][buy][cap] = max( ( prices[index] + dp[index + 1][1][cap - 1] ), 
                                             ( 0 + dp[index + 1][0][cap] ) );
                }
            }
        }
    }

    return dp[0][1][k];
}

int solve(int index, int transaction, vector<int>& prices, int n, int k)
{
    // base case
    if (index == n || transaction == 2 * k) return 0;

    if (transaction % 2 == 0) // even -> buy
    {
        return max( (-prices[index] + solve(index + 1, transaction + 1, prices, n, k)), 
                    (0 + solve(index + 1, transaction, prices, n, k)) );
    }
    else
    {// odd -> sell
        return max( ( prices[index] + solve(index + 1, transaction + 1, prices, n, k)), 
                    ( 0 + solve(index + 1, transaction, prices, n, k)) );
    }
}

// Recursion
// TC -> Exponential
// SC -> O(N)
int maxProfit_2(int k, vector<int>& prices) {
    int n = prices.size();
    return solve(0, 0, prices, n, k);
}

int solve_1(int index, int transaction, vector<int>& prices, int n, int k, vector<vector<int>> &dp)
{
    // base case
    if (index == n || transaction == 2 * k) return 0;

    if (dp[index][transaction] != -1) return dp[index][transaction];

    if (transaction % 2 == 0) // even -> buy
    {
        return dp[index][transaction] = max( (-prices[index] + solve_1(index + 1, transaction + 1, prices, n, k, dp)), 
                    (0 + solve_1(index + 1, transaction, prices, n, k, dp)) );
    }
    else
    {// odd -> sell
        return dp[index][transaction] = max( ( prices[index] + solve_1(index + 1, transaction + 1, prices, n, k, dp)), 
                    ( 0 + solve_1(index + 1, transaction, prices, n, k, dp)) );
    }
}

// Memoization
// TC -> O (N * 2 * Transaction)
// SC -> O (N * 2 * Transaction) + O(N)
int maxProfit_3(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return solve_1(0, 0, prices, n, k, dp);
}

// Tabulation
// TC -> O (N * 2 * Transaction)
// SC -> O (N * 2 * Transaction)
int maxProfit_4(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    // not need to write separate base case as it's 0 -> and vector is initialized as 0
    for (int index = n-1; index >= 0; index--)
    {
        for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
        {
            if (transaction % 2 == 0) // even -> buy
            {
                dp[index][transaction] = max( (-prices[index] + dp[index + 1][transaction + 1]), 
                            (0 + dp[index + 1][transaction]) );
            }
            else
            {// odd -> sell
                dp[index][transaction] = max( ( prices[index] + dp[index + 1][transaction + 1]), 
                            ( 0 +  dp[index + 1][transaction]) );
            }
        }
    }

    return dp[0][0];
}

// Space optimization
// TC -> O (N * 2 * Transaction)
// SC -> O (N * 2 * Transaction)
int maxProfit_4(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int> after(2 * k + 1, 0);
    vector<int> cur(2 * k + 1, 0);

    // not need to write separate base case as it's 0 -> and vector is initialized as 0
    for (int index = n-1; index >= 0; index--)
    {
        for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
        {
            if (transaction % 2 == 0) // even -> buy
            {
                cur[transaction] = max( (-prices[index] + after[transaction + 1]), 
                            (0 + after[transaction]) );
            }
            else
            {// odd -> sell
                cur[transaction] = max( ( prices[index] + after[transaction + 1]), 
                            ( 0 +  after[transaction]) );
            }
        }
        after = cur;
    }

    return after[0];
}

