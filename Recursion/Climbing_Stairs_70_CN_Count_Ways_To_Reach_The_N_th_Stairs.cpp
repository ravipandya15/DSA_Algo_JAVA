#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "CN_Count_Ways_To_Reach_The_N_th_Stairs.cpp";
    return 0;
}

// famous question -> Adobe, Microsoft, Morgan Stanley, Expedia group
// will give TLE -> need to do DP.
// Climbing_Stairs_70
int countDistinctWayToClimbStair(long long nStairs)
{
    if (nStairs < 0) return 0;
    if (nStairs == 0) return 1;
    return countDistinctWayToClimbStair(nStairs - 1) + countDistinctWayToClimbStair(nStairs - 2);
}

static int solve(int index, vector<int> &dp)
{
    if (index < 0) return 0;
    if (index == 0) return 1;

    if (dp[index] != -1) return dp[index];

    int cost = 0;
    if (index - 1 >= 0 && dp[index - 1] != -1) cost += dp[index - 1];
    else cost += solve(index - 1, dp);

    if (index - 2 >= 0 && dp[index - 2] != -1) cost += dp[index - 2];
    else cost += solve(index - 2, dp);

    return dp[index] = cost;
}

// memoization
int countDistinctWayToClimbStair_2(long long nStairs)
{
    vector<int> dp(nStairs, -1);
    return solve(nStairs -1, dp) + solve(nStairs - 2, dp);
}

