#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve1(int index, int target, vector<int> &arr, vector<vector<int>> &dp, int mod)
    {
        // base cases
        if (index == 0)
        {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0]) return 1;
            else return 0;
        }

        if (dp[index][target] != -1) return dp[index][target];

        // explore possiblities of that index
        int notTake = solve1(index -1, target, arr, dp, mod);
        int take = 0;
        if (target >= arr[index])
            take = solve1(index - 1, target - arr[index], arr, dp, mod);

        return dp[index][target] = (notTake + take) % mod;
    }

    
    int findWays2(vector<int> &num, int tar, int mod) {
        vector<vector<int>> dp(num.size(), vector<int>(tar + 1, -1));
        return solve1(num.size()-1, tar, num, dp, mod);
    }

    // Memoization
    // TC -> O(N * target)
    // SC -> O(N) + O(N * target)
    int countPartitions1(int n, int d, vector<int> &arr) {
        int mod = (int)(1e9 + 7);
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
        }

        if (totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;
        return findWays2(arr, (totalSum - d) / 2, mod);
	}

    // Tabulation
    // TC -> O(N * target)
    // SC -> O(N * target) 
    int findWays3(vector<int> &num, int tar, int mod) {
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

                dp[index][target] = (take + notTake) % mod;
            }
        }
        return dp[n-1][tar];
    }

    int countPartitions2(int n, int d, vector<int> &arr) {
        int mod = (int)1e9 + 7;
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
        }

        if (totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;
        return findWays3(arr, (totalSum - d) / 2, mod);
	}