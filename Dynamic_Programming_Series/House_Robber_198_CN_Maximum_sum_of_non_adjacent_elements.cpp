#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int index, vector<int> &nums)
{
    if (index == 0)
    {
        return nums[index];
    }
    if (index < 0)
    {
        return 0;
    }

    // pick
    int pick = nums[index] + solve(index - 2, nums);
    // non pick 
    int not_pick = solve(index - 1, nums);

    return max(pick, not_pick);
}

// Recursion
// TC -> O(2^n)
// SC -> O(N)
int MaximumNonAdjacentSum1(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    return solve(n - 1, nums);
}

int solve1(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0) return nums[index];
    if (index < 0) return 0;

    if (dp[index] != -1) return dp[index];

    // pick
    int pick = nums[index] + solve1(index - 2, nums, dp);
    // non pick 
    int not_pick = solve1(index - 1, nums, dp);

    return dp[index] = max(pick, not_pick);
}

// Memoization
// TC -> O(N)
// SC -> O(N) + O(N)
int MaximumNonAdjacentSum2(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve1(n - 1, nums, dp);
}

// tabulation
// TC -> O(N)
// SC -> O(N)
int MaximumNonAdjacentSum3(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0) pick += dp[i - 2];

        int not_pick = dp[i - 1];

        dp[i] = max(pick, not_pick);
    }

    return dp[n - 1];
}

// space optimization
// TC -> O(N)
// SC -> O(1)
int MaximumNonAdjacentSum4(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0) pick += prev2;

        int not_pick = prev;

        int curi = max(pick, not_pick);

        prev2 = prev;
        prev = curi;
    }

    return prev;
}