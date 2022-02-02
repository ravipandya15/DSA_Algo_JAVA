#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

bool solve(int index, int target, vector<int> &arr)
{
    // base cases
    if (target == 0) return true;
    if (index == 0) return (arr[index] == target);

    // explore possiblities of that index
    bool notTake = solve(index -1, target, arr);
    bool take = false;
    if (target >= arr[index])
        take = solve(index - 1, target - arr[index], arr);

    return notTake || take;
}

// Recursion
// TC -> O(2^n)
// SC -> O(N)
bool subsetSumToK1(int n, int k, vector<int> &arr){
    return solve(n-1, k, arr);
}

int solve1(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // base cases
    if (target == 0) return 1;
    if (index == 0) return (arr[index] == target) ? 1 : 0;

    if (dp[index][target] != -1)  return dp[index][target];
    // explore possiblities of that index
    int notTake = solve1(index -1, target, arr, dp);
    int take = 0;
    if (target >= arr[index])
        take = solve1(index - 1, target - arr[index], arr, dp);

    if (take == 1 || notTake == 1) 
    {
        return dp[index][target] = 1;
    }
    else
    {
        return dp[index][target] = 0;
    }
}

// Memoization
// TC -> O(N * target)
// SC -> O(N) + O(N * target)
bool subsetSumToK2(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    if(solve1(n-1, k, arr, dp) == 1)
        return true;
    else return false;
}

// Tabulation
// TC -> O(N * target)
// SC -> O(N) + O(N * target) 
bool subsetSumToK3(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));

    // base cases
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

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
    return dp[n-1][k];
}

// Space optimization
// TC -> O(N * target)
// SC -> O(N * target) 
bool subsetSumToK4(int n, int k, vector<int> &arr){
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
    return prev[k];
}