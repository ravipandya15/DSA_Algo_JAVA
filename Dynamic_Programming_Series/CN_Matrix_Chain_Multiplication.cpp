#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int matrixMultiplication(vector<int> &arr, int N)
{

}

int solve(int i, int j, vector<int> &arr)
{
    // base case
    if (i == j)
    {
        return 0;
    }

    int mini = (int)1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j] + solve(i, k, arr) + solve(k+1, j, arr);
        if (steps < mini)
        {
            mini = steps;
        }
    }

    return mini;
}

// Recursion
// TC -> Exponential
// SC -> ? ->  may be O(N)
int matrixMultiplication1(vector<int> &arr , int N) {
    return solve(1, N-1, arr);
}

int solve1(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    // base case
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1) return dp[i][j];

    int mini = (int)1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j] + solve1(i, k, arr, dp) + solve1(k+1, j, arr, dp);
        if (steps < mini)
        {
            mini = steps;
        }
    }

    return dp[i][j] = mini;
}

// Memoization
// TC -> O(N^3)
// S -> O(N^2) + O(N)
int matrixMultiplication2(vector<int> &arr , int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve1(1, N-1, arr, dp);
}

// Tabulation
// TC -> O(N^3)
// S -> O(N^2)
int matrixMultiplication3(vector<int> &arr , int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // base case
    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N-1; i >= 1; i--)
    {
        for (int j = i+1; j < N; j++)
        {
            int mini = (int)1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                if (steps < mini)
                {
                    mini = steps;
                }
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}