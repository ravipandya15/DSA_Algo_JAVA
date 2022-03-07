#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

int canYouMake(string &str, string &ptr)
{
    return str.size() + ptr.size() - 2 * lcs4(str, ptr);
}

// Tabulation
// TC -> O(N * M)
// SC -> O(N * M)
int lcs4(string s, string t) {
    int n = s.length();
    int m = t.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // base case
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i-1] == t[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

