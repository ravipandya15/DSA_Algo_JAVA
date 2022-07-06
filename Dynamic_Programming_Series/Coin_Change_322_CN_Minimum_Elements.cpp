#include<vector>
#include<iostream>
using namespace std;

int main()
{
    // Minimum Coins
    return 0;
}

// Minimum Coins

int solve(int index, int T, vector<int> &num)
{
    // base case
    if (index == 0)
    {
        if (T % num[0] == 0) return T / num[0];
        return (int)1e9;
    }

    int notTake = 0 + solve(index - 1, T, num);
    int take = INT_MAX;
    if (num[index] <= T) take = 1 + solve(index, T - num[index], num);

    return min(notTake, take);
}

// Recursion
// TC -> >> O(2^N) -> Exponential
// SC -> >> O(N) -> if min. coin is of 1 then O(Target)
int minimumElements1(vector<int> &num, int x) {
    int n = num.size();
    int ans = solve(n-1, x, num);
    if (ans >= 1e9) return -1;
    return ans;
}

int solve1(int index, int T, vector<int> &num, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        if (T % num[0] == 0) return T / num[0];
        return (int)1e9;
    }

    if (dp[index][T] != -1) return dp[index][T];

    int notTake = 0 + solve1(index - 1, T, num, dp);
    int take = INT_MAX;
    if (num[index] <= T) take = 1 + solve1(index, T - num[index], num, dp);

    return dp[index][T] = min(notTake, take);
}

// Memoization
// TC -> >> O(n * x)
// SC -> >> O(n * x) + O(N)
int minimumElements2(vector<int> &num, int x) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1));

    int ans = solve1(n-1, x, num, dp);
    if (ans >= 1e9) return -1;
    return ans;
}

// Tabulation
// TC -> >> O(n * x)
// SC -> >> O(n * x)
int minimumElements3(vector<int> &num, int x) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, 0));

    // base case
    for (int T = 0; T <= x; T++)
    {
        if (T % num[0] == 0) dp[0][T] = T / num[0];
        else dp[0][T] = (int)1e9;
    }

    for (int index = 1; index < n; index++)
    {
        for (int T = 0; T <= x; T++)
        {
            int notTake = 0 + dp[index - 1][T];
            int take = INT_MAX;
            if (num[index] <= T) take = 1 + dp[index][T - num[index]];

            dp[index][T] = min(notTake, take);
        }
    }

    int ans = dp[n-1][x];
    if (ans >= 1e9) return -1;
    return ans;
}

// Space Optimization
// TC -> >> O(n * x)
// SC -> >> O(x)
int minimumElements4(vector<int> &num, int x) {
    int n = num.size();
    vector<int> prev(x+1, 0);

    // base case
    for (int T = 0; T <= x; T++)
    {
        if (T % num[0] == 0) prev[T] = T / num[0];
        else prev[T] = (int)1e9;
    }

    for (int index = 1; index < n; index++)
    {
        vector<int> cur(x+1, 0);
        for (int T = 0; T <= x; T++)
        {
            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if (num[index] <= T) take = 1 + cur[T - num[index]];

            cur[T] = min(notTake, take);
        }
        prev = cur;
    }

    int ans = prev[x];
    if (ans >= 1e9) return -1;
    return ans;
}
