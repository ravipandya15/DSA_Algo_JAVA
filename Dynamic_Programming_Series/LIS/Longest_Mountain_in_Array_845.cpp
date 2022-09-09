#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

int longestBitonicSequence(vector<int>& arr) {

    // LIS from front
    int n = arr.size();
    if (n < 3) return 0;
    vector<int> dp1(n, 1);

    int maxi1 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i])
            {
                dp1[i] = 1 + dp1[prev];
                maxi1 = max(maxi1, dp1[i]);
            }
        }
    }
    if (maxi1 == 1) return 0;

    int maxi2 = 1;
    vector<int> dp2(n, 1);

    for (int i = n-1; i >= 0; i--)
    {
        for (int prev = n-1; prev > i; prev--)
        {
            if (arr[prev] < arr[i] && 1 + dp2[prev] > dp2[i])
            {
                dp2[i] = 1 + dp2[prev];
                maxi2 = max(maxi2, dp2[i]);
            }
        }
    }
    if (maxi2 == 1) return 0;

    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}
