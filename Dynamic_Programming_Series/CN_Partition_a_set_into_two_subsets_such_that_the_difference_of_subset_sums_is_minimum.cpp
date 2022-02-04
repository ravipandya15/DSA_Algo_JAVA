#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}
// pre - requisist - Subset sum equal to k


// Tabulation
// TC -> O(N) + O(N * totalSum) + O(totalSum / 2)
// SC -> O(N * totalSum) 
int minSubsetSumDifference1(vector<int>& arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    int k = totalSum;

    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));

    // base cases
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= k) dp[0][arr[0]] = true;

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[index -1][target];
            bool take = false;
            if (target >= arr[index])
                take = dp[index - 1][target - arr[index]];

            dp[index][target] = take || notTake;
        }
    }
    
    int mini = (int)1e9;
    for (int s1 = 0; s1 <= totalSum/2; s1++)
    {
        if (dp[n-1][s1] == true)
        {
            int s2 = k - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}

// Space Optimization
// TC -> O(N) + O(N * totalSum) + O(totalSum / 2)
// SC -> O(totalSum)
int minSubsetSumDifference2(vector<int>& arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    int k = totalSum;

    vector<bool> prev(k+1, 0);

    // base cases
    prev[0] = true;
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int index = 1; index < n; index++)
    {
        vector<bool> cur(k+1, 0);
        cur[0] = true;
        for (int target = 1; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (target >= arr[index])
                take = prev[target - arr[index]];

            cur[target] = take || notTake;
        }
        prev = cur;
    }
    
    int mini = (int)1e9;
    for (int s1 = 0; s1 <= totalSum/2; s1++)
    {
        if (prev[s1] == true)
        {
            int s2 = k - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}