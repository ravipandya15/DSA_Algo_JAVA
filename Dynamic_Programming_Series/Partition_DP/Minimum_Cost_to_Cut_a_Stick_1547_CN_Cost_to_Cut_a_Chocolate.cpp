#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

int solve(int i, int j, vector<int> &cuts)
{
    // base case
    if (i > j) return 0;

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts) + solve(ind + 1, j, cuts);
        mini = min(mini, cost);
    }

    return mini;
}

// Recursion
// TC -> Exponential
int cost_1(int n, int c, vector<int> &cuts){
    // c is the size oof cuts array
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return solve(1, c, cuts);
}

int solve_1(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    // base case
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve_1(i, ind - 1, cuts, dp) + solve_1(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

// Memoization
// TC -> O(c^3)
// SC -> O(C^2) + Stack space
int cost_2(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
    return solve_1(1, c, cuts, dp);
}

// Tabulation
// TC -> O(c^3)
// SC -> O(C^2)
int cost_3(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j) continue;

            int mini = INT_MAX;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] +dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, cost);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}