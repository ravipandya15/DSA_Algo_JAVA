#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int i, int j, string str1, string str2)
{
    // base case
    if (i < 0) return j+1;
    if (j < 0) return i+1;

    if (str1[i] == str2[j])
    {
        return 0 + solve(i-1, j-1, str1, str2);
    }
    else
    {
        return min(1 + solve(i, j-1, str1, str2), 
                        min(1 + solve(i-1, j, str1, str2), 
                                    1 + solve(i-1, j-1, str1, str2)));
    }
}

// Recursion
// TC -> Exponential -> O(3^n * 3^m)
// SC -> O(N + M)
int editDistance_1(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    return solve(n-1, m-1, str1, str2);
}

int solve_2(int i, int j, string str1, string str2)
{
    // base case
    if (i == 0) return j;
    if (j == 0) return i;

    if (str1[i-1] == str2[j-1])
    {
        return 0 + solve_2(i-1, j-1, str1, str2);
    }
    else
    {
        return min(1 + solve_2(i, j-1, str1, str2), 
                        min(1 + solve_2(i-1, j, str1, str2), 
                                    1 + solve_2(i-1, j-1, str1, str2)));
    }
}

// Recursion
// TC -> Exponential -> O(3^n * 3^m)
// SC -> O(N + M)
int editDistance_2(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    return solve_2(n, m, str1, str2);
}

int solve_3(int i, int j, string str1, string str2, vector<vector<int>> &dp)
{
    // base case
    if (i == 0) return j;
    if (j == 0) return i;

    if (dp[i][j] != -1) return dp[i][j];
    if (str1[i-1] == str2[j-1])
    {
        return dp[i][j] = 0 + solve_3(i-1, j-1, str1, str2, dp);
    }
    else
    {
        return dp[i][j] = min(1 + solve_3(i, j-1, str1, str2, dp), 
                            min(1 + solve_3(i-1, j, str1, str2, dp), 
                                    1 + solve_3(i-1, j-1, str1, str2, dp)));
    }
}

// Memoization
// TC -> O(N * M)
// SC -> O(N * M) + O(N + M)
int editDistance_3(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    return solve_3(n, m, str1, str2, dp);
}

// Tabulation
// TC -> O(N * M)
// SC -> O(N * M)
int editDistance_4(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // base case
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(1 + dp[i][j-1], 
                                min(1 + dp[i-1][j], 
                                        1 + dp[i-1][j-1]));
            }
        }
    }

    return dp[n][m];
}

// Space optimization
// TC -> O(N * M)
// SC -> O(M)
int editDistance_5(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<int> prev(m+1, 0);

    // base case
    for (int j = 0; j <= m; j++) prev[j] = j;
    
    for (int i = 1; i <= n; i++)
    {
        vector<int> cur(m+1, 0);
        cur[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                cur[j] = 0 + prev[j-1];
            }
            else
            {
                cur[j] = min(1 + cur[j-1], 
                                min(1 + prev[j], 
                                        1 + prev[j-1]));
            }
        }
        prev = cur;
    }

    return prev[m];
}