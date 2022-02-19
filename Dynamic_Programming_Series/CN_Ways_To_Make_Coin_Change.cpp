#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

long solve(int index, int target, int * arr)
{
    // base case
    if (index == 0)
    {
        if ( (target % arr[0]) == 0)
            return 1;
        else
            return 0;
    }

    long notTake = solve(index-1, target, arr);
    long take = 0;
    if (arr[index] <= target)
        take = solve(index, target-arr[index], arr);

    return notTake + take;
}

// Recursion
// TC -> >> O(2^N) -> Exponential
// SC -> >> O(N) -> if min. coin is of 1 then O(Target)
long countWaysToMakeChange1(int *denominations, int n, int value)
{
    return solve(n-1, value, denominations);
}

long solve1(int index, int target, int* arr,  vector<vector<long>> dp)
    {
        // base case
        if (index == 0)
        {
            if ( (target % arr[0]) == 0)
                return 1;
            else
                return 0;
        }

        if (dp[index][target] != -1) return dp[index][target];

        long notTake = solve1(index-1, target, arr, dp);
        long take = 0;
        if (arr[index] <= target)
            take = solve1(index, target-arr[index], arr, dp);

        return dp[index][target] = notTake + take;
    }

// Memoization
// TC -> >> O(n * value)
// SC -> >> O(n * value) + O(N)
long countWaysToMakeChange2(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return solve1(n-1, value, denominations, dp);
}

// Tabulation
// TC -> >> O(n * value)
// SC -> >> O(n * value)
long countWaysToMakeChange3(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));

    // base case
    for (int T = 0; T <= value; T++)
    {
        if (T  % denominations[0] == 0)
        {
            dp[0][T] = 1;
        }           
    }

    for (int index = 1; index < n; index++)
    {
        for (int T = 0; T <= value; T++)
        {
            long notTake = dp[index-1][T];
            long take = 0;
            if (denominations[index] <= T)
                take = dp[index][T-denominations[index]];

            dp[index][T] = notTake + take;
        }
    }

    return dp[n-1][value];
}

// Space Optimization
// TC -> >> O(n * value)
// SC -> >> O(value)
long countWaysToMakeChange4(int *denominations, int n, int value)
{
    vector<long> prev(value + 1, 0);

    // base case
    for (int T = 0; T <= value; T++)
    {
        if (T  % denominations[0] == 0)
        {
            prev[T] = 1;
        }           
    }

    for (int index = 1; index < n; index++)
    {
        vector<long> cur(value + 1, 0);
        for (int T = 0; T <= value; T++)
        {
            long notTake = prev[T];
            long take = 0;
            if (denominations[index] <= T)
                take = cur[T-denominations[index]];

            cur[T] = notTake + take;
        }
    }

    return prev[value];
}