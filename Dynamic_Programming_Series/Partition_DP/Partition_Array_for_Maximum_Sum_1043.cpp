#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
    return 0;
}

int solve(int ind, int k, vector<int>& arr, int n, vector<int> &dp)
{
    // base case
    if (ind == n) return 0;

    if (dp[ind] != -1) return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int sum = INT_MIN;
    int maxAns = INT_MIN;
    for (int j = ind; j < min(n, ind + k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        sum = (len * maxi) + solve(j + 1, k, arr, n, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}

// Memoization
// TC -> O(N * K)
// SC -> O(N) + O(N)
int maxSumAfterPartitioning_1(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, k, arr, n, dp);
}

// Tabulation
// TC -> O(N * K)
// SC -> O(N)
int maxSumAfterPartitioning_1(vector<int>& arr, int k) {
     
}