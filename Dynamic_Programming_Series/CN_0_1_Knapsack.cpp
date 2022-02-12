#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int index, int W, vector<int> &wt, vector<int> &val)
{
    // base case
    if (index == 0)
    {
        if (wt[0] <= W) return val[0];
        else return 0;
    }

    int notTake = 0 + solve(index - 1, W, wt, val);
    int take = INT_MIN;
    if (wt[index] <= W) take = val[index] + solve(index -1, W - wt[index], wt, val);

    return max(notTake, take);
}

// Recursion
// TC -> O(2^N)
// SC -> O(N)
int knapsack1(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return solve(n-1, maxWeight, weight, value);
}

int solve1(int index, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        if (wt[0] <= W) return val[0];
        else return 0;
    }

    if (dp[index][W] != -1) return dp[index][W];

    int notTake = 0 + solve1(index - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[index] <= W) take = val[index] + solve1(index -1, W - wt[index], wt, val, dp);

    return dp[index][W] = max(notTake, take);
}

// Memoization
// TC -> O(N * W) -> N is size of weight and value array size and W is maxWeight
// SC -> O(N * W) + O(N)
int knapsack2(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve1(n-1, maxWeight, weight, value, dp);
}

// Tabulation
// TC -> O(N * W) -> N is size of weight and value array size and W is maxWeight
// SC -> O(N * W)
int knapsack3(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // base case
    for (int W = wt[0]; W <= maxWeight; W++) dp[0][W] = val[0];

    for (int index = 1; index < n; index++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int notTake = 0 + dp[index - 1][W];
            int take = INT_MIN;
            if (wt[index] <= W) take = val[index] + dp[index -1][W - wt[index]];

            dp[index][W] = max(notTake, take);
        }
    }
    return dp[n-1][maxWeight];
}

// Space Optimization
// TC -> O(N * W) -> N is size of weight and value array size and W is maxWeight
// SC -> O(W)
int knapsack4(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<int> prev(maxWeight + 1);

    // base case
    for (int W = wt[0]; W <= maxWeight; W++) prev[W] = val[0];

    for (int index = 1; index < n; index++)
    {
        vector<int> cur(maxWeight + 1);
        for (int W = 0; W <= maxWeight; W++)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if (wt[index] <= W) take = val[index] + prev[W - wt[index]];

            cur[W] = max(notTake, take);
        }
        prev = cur;
    }
    return prev[maxWeight];
}

// SIngle Array Space Optimized Approach
int knapsack5(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<int> prev(maxWeight + 1);

    // base case
    for (int W = wt[0]; W <= maxWeight; W++) prev[W] = val[0];

    for (int index = 1; index < n; index++)
    {
        for (int W = maxWeight; W >= 0; W--)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if (wt[index] <= W) take = val[index] + prev[W - wt[index]];

            prev[W] = max(notTake, take);
        }
    }
    return prev[maxWeight];
}