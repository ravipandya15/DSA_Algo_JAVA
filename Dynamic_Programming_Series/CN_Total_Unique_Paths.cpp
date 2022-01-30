#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int i, int j)
{
    // base case
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    int up = solve(i - 1, j);
    int left = solve(i, j - 1);
    return up + left;
}

//Recursion
// TC -> O(2^(m*n))
// SC -> O(m-1 + n-1)
int uniquePaths1(int m, int n)
{
    return solve(m - 1, n - 1);
}

int solve1(int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int up = solve1(i - 1, j, dp);
    int left = solve1(i, j - 1, dp);
    return dp[i][j] = up + left;
}

// memoization
// TC -> O(M * N)
// SC -> O(M-1 + N-1) + O(M * N)
int uniquePaths2(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve1(m - 1, n - 1, dp);
}

// Tabulation
// TC -> O(M*N)
// SC -> O(M * N)
int uniquePaths3(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;
            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

// Space optimization
// TC -> O(M*N)
// SC -> O(N) -> no. of columns
int uniquePaths4(int m, int n)
{

    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> cur(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                cur[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
            {
                up = prev[j];
            }
            if (j > 0)
            {
                left = cur[j - 1];
            }

            cur[j] = up + left;
        }
        prev = cur;
    }

    return prev[n - 1];
}