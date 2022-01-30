#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int i, int j, vector<vector<int>> &matrix)
{
    // base cases
    if (j < 0 || j >= matrix[0].size()) return (int)-1e8;
    if (i == 0) return matrix[0][j];

    int u = matrix[i][j] + solve(i-1, j, matrix);
    int ld = matrix[i][j] + solve(i-1, j-1, matrix);
    int rd = matrix[i][j] + solve(i-1, j+1, matrix);

    return max(u, max(ld, rd));
}

// Recursion
// TC -> O(3^(N))
// SC -> O(N)
int getMaxPathSum1(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int maxi = (int)-1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, solve(n-1, j, matrix));
    }

    return maxi;
}

int solve1(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // base cases
    if (j < 0 || j >= matrix[0].size()) return (int)-1e8;
    if (i == 0) return matrix[0][j];

    if (dp[i][j] != -1) return dp[i][j];

    int u = matrix[i][j] + solve1(i-1, j, matrix, dp);
    int ld = matrix[i][j] + solve1(i-1, j-1, matrix, dp);
    int rd = matrix[i][j] + solve1(i-1, j+1, matrix, dp);

    return dp[i][j] = max(u, max(ld, rd));
}

// Memoization
// TC -> O(N * M)
// SC -> O(N) + O(N * M)
int getMaxPathSum2(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = (int)-1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, solve1(n-1, j, matrix, dp));
    }

    return maxi;
}

// Tabulation
// TC -> O(N * M)
// SC -> O(N) + O(N * M)
int getMaxPathSum3(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // base case
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = matrix[0][i]; 
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = matrix[i][j] + dp[i-1][j];
            int ld = matrix[i][j];
            if (j - 1 >= 0) ld += dp[i-1][j-1];
            else ld += (int)-1e8;
            int rd = matrix[i][j];
            if (j+1 < m) rd += dp[i-1][j+1];
            else rd += (int)-1e8;

            dp[i][j] = max(u, max(ld, rd));
        }
    }

    int maxi = (int)-1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n-1][j]);
    }

    return maxi;
}

// Space Optimization
// TC -> O(N * M)
// SC -> O(N) + O(N * M)
int getMaxPathSum4(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0);

    // base case
    for (int i = 0; i < m; i++)
    {
        prev[i] = matrix[0][i]; 
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> cur(m, 0);
        for (int j = 0; j < m; j++)
        {
            int u = matrix[i][j] + prev[j];
            int ld = matrix[i][j];
            if (j - 1 >= 0) ld += prev[j-1];
            else ld += (int)-1e8;
            int rd = matrix[i][j];
            if (j+1 < m) rd += prev[j+1];
            else rd += (int)-1e8;

            cur[j] = max(u, max(ld, rd));
        }
        // IMP
        prev = cur;
    }

    int maxi = (int)-1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }

    return maxi;
}