#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

int solve(int i, int j, vector<int>& a)
{
    // base case
    if (i > j) return 0;

    // first burst the last baloon -> think in reverse direction
    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = a[i - 1] * a[ind] * a[j + 1] + solve(i, ind - 1, a) + solve(ind + 1, j, a);
        maxi = max(maxi, cost);
    }

    return maxi;
}

// Recursion
// TC -> Exponential
int maxCoins_1(vector<int>& a)
{
    int n = a.size();
	a.push_back(1);
    a.insert(a.begin(), 1);
    return solve(1, n, a);
}

int solve1(int i, int j, vector<int>& a, vector<vector<int>> &dp)
{
    // base case
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    // first burst the last baloon -> think in reverse direction
    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = a[i - 1] * a[ind] * a[j + 1] + solve1(i, ind - 1, a, dp) + solve1(ind + 1, j, a, dp);
        maxi = max(maxi, cost);
    }

    return dp[i][j] = maxi;
}

// Memoization
// TC -> O(N^3)
// Sc -> O(N^2) + O(N)
int maxCoins_2(vector<int>& a)
{
	int n = a.size();
	a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve1(1, n, a, dp);
}

// Tabulation
// TC -> O(N^3)
// Sc -> O(N^2)
int maxCoins_1(vector<int>& a)
{
	int n = a.size();
	a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j) continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = a[i - 1] * a[ind] * a[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}