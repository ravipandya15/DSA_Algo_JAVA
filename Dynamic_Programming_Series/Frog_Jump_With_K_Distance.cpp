#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve1(int index, vector<int> &heights, int k)
{
    // base case
    if (index == 0) return 0;

    int MinSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (index - j >= 0)
        {
            int jump = solve1(index - j, heights, k) + abs(heights[index] - heights[index - j]);
            MinSteps = min(MinSteps, jump);
        }
    }

    return MinSteps;
}

// recursion
int frogJump1(int n, vector<int> &heights, int k)
{
    return solve1(n - 1, heights, k);
}

int solve(int index, vector<int> &heights, vector<int> &dp, int k)
{
    // base case
    if (index == 0) return 0;

    if (dp[index] != -1) return dp[index];

    int MinSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (index - j >= 0)
        {
            int jump = solve1(index - j, heights, k) + abs(heights[index] - heights[index - j]);
            MinSteps = min(MinSteps, jump);
        }
    }

    return dp[index] = MinSteps;
}

// memoization
// TC -> O(N)
// SC -> O(N) + O(N)
int frogJump2(int n, vector<int> &heights, int k)
{
    vector<int> dp(n+1, -1);
    return solve(n - 1, heights, dp, k);
}

//tabulation
// TC -> O(N)
// SC -> O(N)
int frogJump3(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int MinSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                MinSteps = min(MinSteps, jump);
            }
        }

        dp[i] = MinSteps;
    }
    return dp[n - 1];
}