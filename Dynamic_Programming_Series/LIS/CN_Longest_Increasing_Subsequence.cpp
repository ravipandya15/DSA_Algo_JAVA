#include<vector>
#include<iostream>
// #include<bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


int solve(int index, int prev_ind, int arr[], int n)
{
    // base case
    if (index == n) return 0;

    int length = 0 + solve(index + 1, prev_ind, arr, n); // not take

    if (prev_ind == -1 || arr[index] > arr[prev_ind])
    {
        length = max(length, 1 + solve(index + 1, index, arr, n));
    }
    return length;
}

// Recursion
// TC -> O(2^N)
// SC -> O(N) -> Recursive Stack space
int longestIncreasingSubsequence_1(int arr[], int n)
{
    return solve(0, -1, arr, n);
}

int solve_1(int index, int prev_ind, int arr[], int n, vector<vector<int>> &dp)
{
    // base case
    if (index == n) return 0;

    if (dp[index][prev_ind + 1] != -1) return dp[index][prev_ind + 1];

    int length = 0 + solve_1(index + 1, prev_ind, arr, n, dp); // not take

    if (prev_ind == -1 || arr[index] > arr[prev_ind])
    {
        length = max(length, 1 + solve_1(index + 1, index, arr, n, dp));
    }
    return dp[index][prev_ind + 1] = length;
}

// Memoization
// TC -> O(N * N)
// SC -> O(N * N) + O(N)
int longestIncreasingSubsequence_2(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve_1(0, -1, arr, n, dp);
}

// Tabulation
// TC -> O(N * N)
// SC -> O(N * N)
int longestIncreasingSubsequence_3(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // not required base case
    for (int index = n-1; index >= 0; index--)
    {
        for (int prev_ind = index - 1; prev_ind >= -1; prev_ind--)
        {
            int length = 0 + dp[index + 1][prev_ind + 1]; // not take

            if (prev_ind == -1 || arr[index] > arr[prev_ind])
            {
                length = max(length, 1 + dp[index + 1][index + 1]);
            }
            dp[index][prev_ind + 1] = length;
        }
    }

    return dp[0][-1 + 1];
}

// Space optimization
// TC -> O(N * N)
// SC -> O(2 * N)
int longestIncreasingSubsequence_4(int arr[], int n)
{
    vector<int> next(n+1, 0);
    vector<int> cur(n+1, 0);

    // not required base case
    for (int index = n-1; index >= 0; index--)
    {
        for (int prev_ind = index - 1; prev_ind >= -1; prev_ind--)
        {
            int length = 0 + next[prev_ind + 1]; // not take

            if (prev_ind == -1 || arr[index] > arr[prev_ind])
            {
                length = max(length, 1 + next[index + 1]);
            }
            cur[prev_ind + 1] = length;
        }
        next = cur;
    }

    return next[-1 + 1];
}

// Algorithmic way
// TC -> O(N * N)
// SC -> O(N)
int longestIncreasingSubsequence_5(int arr[], int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

// Algorithmic way -> to print Longest Increasing subsequence
// TC -> O(N * N)
// SC -> O(N)
int print_longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    int maxi = 1;
    int last_index = 0;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            last_index = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[last_index]);
    while (hash[last_index] != last_index)
    {
        last_index = hash[last_index];
        temp.push_back(arr[last_index]);
    }

    reverse(temp.begin(), temp.end());

    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;

    return maxi;
}

// not working -> next solution is working -> has Binary Search as method

// Binary Search technique
// TC -> O(N * log(N))
// SC -> O(N)
int longestIncreasingSubsequence_5(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            // int ind = lower_bound(temp.begin(), temp.end(), arr[i]);
            // temp[ind] = arr[i];
        }
    }
    return len;
}

int BinarySearch(int num, vector<int> sub)
{
    int left = 0, right = sub.size() - 1;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if (num == sub[mid])
        {
            return mid;
        }
        else if (num > sub[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

// Working
// Binary Search technique
// TC -> O(N * log(N))
// SC -> O(N)
int longestIncreasingSubsequence_6(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = BinarySearch(arr[i], temp);
            temp[ind] = arr[i];
        }
    }
    return len;
}

