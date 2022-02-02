#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// Tabulation
// TC -> O(N * target)
// SC -> O(N) + O(N * target) 
bool subsetSumToK(int n, int k, vector<int> &arr){
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

// same code as SubsetSum equal to K
bool canPartition(vector<int> &arr, int n)
{
	int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    if (totalSum & 1) return false;
    int k = totalSum >> 1;
    return subsetSumToK(n, k, arr);
}