#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if (i == 0 && j == 0) return grid[i][j];
    if (i < 0 || j < 0) return (int)1e9;

    int up = grid[i][j] + solve(i-1, j, grid);
    int left = grid[i][j] + solve(i, j-1, grid);

    return min(up, left);
}

// Recursion
// TC -> O(2^(N*M))
// SC -> O(N-1 + M-1)
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return solve(n-1, m-1, grid);
}

int solve1(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0) return grid[i][j];
    if (i < 0 || j < 0) return (int)1e9;

    if (dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + solve1(i-1, j, grid, dp);
    int left = grid[i][j] + solve1(i, j-1, grid, dp);

    return dp[i][j] = min(up, left);
}

// Memoization
// TC -> O(N*M)
// SC -> O(N*M) + O(N-1 + M-1)
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve1(n-1, m-1, grid, dp);
}

// Tabulation
// TC -> O(N*M)
// SC -> O(N*M)
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0) up += dp[i-1][j];
                else up += (int)1e9;

                int left = grid[i][j];
                if (j > 0) left += dp[i][j-1];
                else left += (int)1e9;

                dp[i][j] = min(up, left);
            }

            
        }
    }
    return dp[n-1][m-1];
}

// Space optimization
// TC -> O(N*M)
// SC -> O(M)
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);

    for (int i = 0; i <n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) temp[j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0) up += prev[j];
                else up += (int)1e9;

                int left = grid[i][j];
                if (j > 0) left += temp[j-1];
                else left += (int)1e9;

                temp[j] = min(up, left);
            }
        }
        prev = temp; // IMP
    }
    return prev[m-1];
}