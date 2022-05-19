#include<vector>
#include<iostream>
#include<algorithm>
// #include<bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    sort(arr.begin(), arr.end());
    int maxi = 1;
    int last_index = 0;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i])
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

    return temp;
}