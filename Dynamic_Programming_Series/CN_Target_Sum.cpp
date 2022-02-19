#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// same problem S1 - S2 = D
//just copy that tabulation functiona and remove mod

// Tabulation
// TC -> O(N * target)
// SC -> O(N * target) 
int findWays3(vector<int> &num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(num.size(), vector<int>(tar + 1, 0));

    // base cases
    if (num[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if (num[0] != 0 && num[0] <= tar) dp[0][num[0]] = 1;

    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= tar; target++) // target = 0 will also work -> video ma 0 thi karyu chhe ne DP 14 ma 1 thi karyu tu
        {
            int notTake = dp[index -1][target];
            int take = 0;
            if (target >= num[index])
                take = dp[index - 1][target - num[index]];

            dp[index][target] = (take + notTake);
        }
    }
    return dp[n-1][tar];
}

int countPartitions2(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalSum += arr[i];
    }

    if (totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;
    return findWays3(arr, (totalSum - d) / 2);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions2(n, target, arr);
}
