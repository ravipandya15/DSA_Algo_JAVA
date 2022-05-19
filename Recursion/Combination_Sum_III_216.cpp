#include<iostream>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

void solve(int number, int k, int n, vector<int> &ans, vector<vector<int>> &result)
{
    // base case
    if (k < 0 || n < 0) return;
    if (k == 0 && n == 0) 
    {
        result.push_back(ans);
        return;
    }

    for (int i = number; i <= 9; i++)
    {
        if (i <= n)
        {
            ans.push_back(i);
            n = n - i;
            k--;
            solve(i + 1, k, n, ans, result);
            k++;
            n = n + i;
            ans.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> ans;
    solve(1, k, n, ans, result);
    return result;
}