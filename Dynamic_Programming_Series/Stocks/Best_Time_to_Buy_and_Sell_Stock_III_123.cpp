#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// CN -> Buy and Sell Stock

int solve(int index, int buy, int cap, vector<int>& prices, int n)
{
    // base case
    if (index == n || cap == 0) return 0;

    if (buy == 1)
    {
        return max( (-prices[index] + solve(index + 1, 0, cap, prices, n)), 
                    (0 + solve(index + 1, 1, cap, prices, n)) );
    }
    else // sell
    {
        return max( (prices[index] + solve(index + 1, 1, cap - 1, prices, n)), 
                    (0 + solve(index + 1, 0, cap, prices, n)));
    }
}

// Recusrion
// TC -> Exponential
// SC -> O(N)
int maxProfit_1(vector<int>& prices) {
    int n = prices.size();
    return solve(0, 1, 2, prices, n);
}

int solve_1(int index, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>> &dp)
{
    // base case
    if (index == n || cap == 0) return 0;

    if (dp[index][buy][cap] != -1) return dp[index][buy][cap];

    if (buy == 1)
    {
        return dp[index][buy][cap] = max( (-prices[index] + solve_1(index + 1, 0, cap, prices, n, dp)), 
                    (0 + solve_1(index + 1, 1, cap, prices, n, dp)) );
    }
    else // sell
    {
        return dp[index][buy][cap] = max( (prices[index] + solve_1(index + 1, 1, cap - 1, prices, n, dp)), 
                    (0 + solve_1(index + 1, 0, cap, prices, n, dp)));
    }
}

// Memoization
// TC -> O(N * 2 * 3)
// SC -> O(N * 2 * 3) + O(N)
int maxProfit_1(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve_1(0, 1, 2, prices, n, dp);
}

// Tabulation
// TC -> O(N * 2 * 3)
// SC -> O(N * 2 * 3)
int maxProfit_1(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    // base case -> not required as vector is already initialized with 0
    // if (index == n || cap == 0) return 0;

    for (int index = n-1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++) // cap == 0 is covered in base case
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

    return dp[0][1][2];
}

// Space optimization
// TC -> O(N * 2 * 3)
// SC -> O(2 * 3)
int maxProfit_1(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    // base case -> not required as vector is already initialized with 0
    // if (index == n || cap == 0) return 0;

    for (int index = n-1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++) // cap == 0 is covered in base case
            {
                if (buy == 1)
                {
                    cur[buy][cap] = max( ( -prices[index] + ahead[0][cap] ), 
                                             ( 0 + ahead[1][cap] ) );
                }
                else // sell
                {
                    cur[buy][cap] = max( ( prices[index] + ahead[1][cap - 1] ), 
                                             ( 0 + ahead[0][cap] ) );
                }
            }
        }
        ahead = cur;
    }

    return ahead[1][2];
}