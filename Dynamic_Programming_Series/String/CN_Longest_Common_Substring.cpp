#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// Tabulation
// TC -> O(N * M)
// SC -> O(N * M)
int lcs1(string &s, string &t) {
    int n = s.length();
    int m = t.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // base case
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i-1] == t[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}

// Space optimization
// TC -> O(N * M)
// SC -> O(M)
int lcs2(string &s, string &t) {
    int n = s.length();
    int m = t.length();
    vector<int> prev(m+1, 0);

    // base case not required as default value is 0

    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> cur(m+1, 0);
        for (int j = 1; j <= m; j++)
        {
            if (s[i-1] == t[j-1])
            {
                cur[j] = 1 + prev[j-1];
                maxi = max(maxi, cur[j]);

            }
            else
            {
                cur[j] = 0;
            }
        }
        prev = cur;
    }
    return maxi;
}