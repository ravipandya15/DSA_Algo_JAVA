#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }
            else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
            {
                count[i] += count[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi) cnt += count[i];
    }

    return cnt;
}