#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve1(int index, vector<int> &heights)
{
    // base case
    if (index == 0) return 0;

    int left = solve1(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if (index > 1) right = solve1(index - 2, heights) + abs(heights[index] - heights[index - 2]);

    return min(left, right);
}

// recursion
int frogJump1(int n, vector<int> &heights)
{
    return solve1(n - 1, heights);
}

int solve(int index, vector<int> &heights, vector<int> &dp)
{
    // base case
    if (index == 0) return 0;

    if (dp[index] != -1) return dp[index];

    int left = solve(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if (index > 1) right = solve(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    return dp[index] = min(left, right);
}

// memoization
// TC -> O(N)
// SC -> O(N) + O(N)
int frogJump2(int n, vector<int> &heights)
{
    // dp(n) will also work
    vector<int> dp(n+1, -1);
    return solve(n - 1, heights, dp);
}

//tabulation
// TC -> O(N)
// SC -> O(N)
int frogJump3(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1) right = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

// space optimazation
int frogJump4(int n, vector<int> &heights)
{

    int prev = 0, prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1) right = prev2 + abs(heights[i] - heights[i - 2]);

        int curi = min(left, right);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}