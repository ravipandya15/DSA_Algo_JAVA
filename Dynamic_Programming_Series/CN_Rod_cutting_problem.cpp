#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int index, int n, vector<int> &price)
{
    // base case
    if (index == 0)
    {// as rodLength is 1
        return price[0] * n;
    }

    int notTake = 0 + solve(index-1, n, price);
    int take = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= n)
    {
        take = price[index] + solve(index, n-rodLength, price);
    }

    return max(notTake, take);
}

// Recursion
// TC -> exponential
// SC -> O(w)
int cutRod1(vector<int> &price, int n) {
    return solve(n-1, n, price);
}

int solve1(int index, int n, vector<int> &price, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {// as rodLength is 1
        return price[0] * n;
    }

    if (dp[index][n] != -1) return dp[index][n];

    int notTake = 0 + solve1(index-1, n, price, dp);
    int take = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= n)
    {
        take = price[index] + solve1(index, n-rodLength, price, dp);
    }

    return dp[index][n] = max(notTake, take);
}

// Memoization
// TC -> O(N * n)
// SC -> O(N * n) + O(N)
int cutRod2(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve1(n-1, n, price, dp);
}

// Tabulation
// TC -> O(N * n)
// SC -> O(N * n)
int cutRod3(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // base case
    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = price[0] * N;
    }

    for (int index = 1; index < n; index++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + dp[index-1][N];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= N)
            {
                take = price[index] + dp[index][N-rodLength];
            }

            dp[index][N] = max(notTake, take);
        }
    }

    return dp[n-1][n];
}

// Space optimization
// TC -> O(N * n)
// SC -> O(n)
int cutRod4(vector<int> &price, int n) {
    vector<int> prev(n+1, 0);

    // base case
    for (int N = 0; N <= n; N++)
    {
        prev[N] = price[0] * N;
    }

    for (int index = 1; index < n; index++)
    {
        vector<int> cur(n+1, 0);
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 +prev[N];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= N)
            {
                take = price[index] + cur[N-rodLength];
            }

            cur[N] = max(notTake, take);
        }
        prev = cur;
    }

    return prev[n];
}

// Single Array Space optimized
// TC -> O(N * n)
// SC -> O(n)
int cutRod5(vector<int> &price, int n) {
    vector<int> prev(n+1, 0);

    // base case
    for (int N = 0; N <= n; N++)
    {
        prev[N] = price[0] * N;
    }

    for (int index = 1; index < n; index++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 +prev[N];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= N)
            {
                take = price[index] + prev[N-rodLength];
            }

            prev[N] = max(notTake, take);
        }
    }

    return prev[n];
}