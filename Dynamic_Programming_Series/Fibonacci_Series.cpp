#include<vector>
#include<iostream>
using namespace std;

int main()
{
    cout << "Fibonacci number" << endl;
    int n = 5;
    vector<int> dp(n+1, -1);
    for (int i = 0; i < n + 1; i++) dp[i] = -1;
    cout << "result is " << Fib(n, dp) << endl;

    vector<int> dp2(n+1, -1);
    dp2[0] = 0;
    dp2[1] = 1;
    int result2 = Fib2(n, dp2);

    int prev2 = 0, prev = 1;
    int result3 = Fib3(n, prev2, prev);
    return 0;
}

// Memoization
//TC -> O(N)
// SC -> O(N) + O(N)
int Fib(int n, vector<int>& dp)
{
    // base case
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = Fib(n - 1, dp) + Fib(n - 2, dp);
}

// Tabulation
// TC -> O(N)
// SC -> O(N)
int Fib2(int n, vector<int>& dp)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// best 
// TC -> O(N)
// SC -> O(1)
int Fib3(int n, int prev2, int prev)
{
    for (int i = 2; i <= n; i++)
    {
        int curi = prev2 + prev;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}