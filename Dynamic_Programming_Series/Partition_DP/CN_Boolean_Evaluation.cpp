#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
    return 0;
}

int mod = 1000000007;

long long solve(int i, int j, bool isTrue, string &exp, int mod)
{
    // base case
    if (i > j) return 0;

    if (i == j)
    {
        if (isTrue) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        long long lT = solve(i, ind - 1, 1, exp, mod);
        long long lF = solve(i, ind - 1, 0, exp, mod);
        long long rT = solve(ind + 1, j, 1, exp, mod);
        long long rF = solve(ind + 1, j, 0, exp, mod);

        if (exp[ind] == '&')
        {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) & mod;
            else ways = (ways + (lF * rF) % mod) % mod; 
        }
        else
        {// exp[ind] == '^'
            if (isTrue) ways = (ways + (lT * rF) % mod + (lF * rT)) % mod;
            else ways = (ways + (lT * rT) % mod + (lF * rF)) % mod;
        }
    }

    return ways;
}

// Recusrion
// TC -> Exponential
int evaluateExp_1(string &exp) {
    int mod = 1000000007;
    return solve(0, exp.size() - 1, 1, exp, mod);
}

long long solve_1(int i, int j, bool isTrue, string &exp, vector<vector<vector<long long>>> &dp)
{
    // base case
    if (i > j) return 0;

    if (i == j)
    {
        if (isTrue) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        long long lT = solve_1(i, ind - 1, 1, exp, dp);
        long long lF = solve_1(i, ind - 1, 0, exp, dp);
        long long rT = solve_1(ind + 1, j, 1, exp, dp);
        long long rF = solve_1(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&')
        {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) & mod;
            else ways = (ways + (lF * rF) % mod) % mod; 
        }
        else
        {// exp[ind] == '^'
            if (isTrue) ways = (ways + (lT * rF) % mod + (lF * rT)) % mod;
            else ways = (ways + (lT * rT) % mod + (lF * rF)) % mod;
        }
    }

    return dp[i][j][isTrue] = ways % mod;;
}

// Memoization
// TC -> O(N^3)
// Sc-> O(N^2) + Stack space
int evaluateExp_2(string &exp) {
    int n = exp.size();
    //int mod = 1000000007;
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return solve_1(0, n - 1, 1, exp, dp);
}