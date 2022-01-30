#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int i, int j, vector<vector<int>>& triangle, int n)
{
    // base case
    if (i == n-1)
        return triangle[n-1][j];

    int d = triangle[i][j] + solve(i+1, j, triangle, n);
    int dg = triangle[i][j] + solve(i+1, j+1, triangle, n);

    return min(d, dg);
}

// Recursion
// TC -> O(2^(n*(n+1)/2))
// SC -> O(N)
int minimumPathSum1(vector<vector<int>>& triangle, int n) {
    return solve(0, 0, triangle, n);
}

int solve1(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp)
{
    // base case
    if (i == n-1)
        return triangle[n-1][j];

    if (dp[i][j] != -1) return dp[i][j];

    int d = triangle[i][j] + solve1(i+1, j, triangle, n, dp);
    int dg = triangle[i][j] + solve1(i+1, j+1, triangle, n, dp);

    return dp[i][j] = min(d, dg);
}

// Memoization
// TC -> O(N*N)
// SC -> O(N) + O(N*N)
int minimumPathSum2(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve1(0, 0, triangle, n, dp);

}

// Tabulation
// TC -> O(N*N)
// SC -> O(N*N)
int minimumPathSum3(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // In Tabulation do reverse of Recursion
    // Recursion O -> n-1
    // Tabulation n-1 to 0
    // base case
    for (int j = 0; j < n; j++)
        dp[n-1][j] = triangle[n-1][j];

    
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = triangle[i][j] + dp[i+1][j];
            int dg = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(d, dg);
        }
    }

    return dp[0][0];
}

// Space Optimization
// TC -> O(N*N)
// SC -> O(N)
int minimumPathSum4(vector<vector<int>>& triangle, int n) {
    vector<int> front(n, 0), cur(n, 0);

    // base case
    for (int j = 0; j < n; j++)
        front[j] = triangle[n-1][j];

    
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = triangle[i][j] + front[j];
            int dg = triangle[i][j] + front[j+1];

            cur[j] = min(d, dg);
        }
        front = cur;
    }

    return front[0];
}