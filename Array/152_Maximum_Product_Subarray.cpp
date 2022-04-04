#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

// almost similar to kadane's algorithm -> find max sum subarray
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    int prod = 1;

    for (int i = 0; i < n; i++)
    {
        prod = prod * nums[i];
        maxi = max(maxi, prod);
        if (prod == 0)
        {
            prod = 1;
        }
    }

    prod = 1;

    for (int i = n-1; i >= 0; i--)
    {
        prod = prod * nums[i];
        maxi = max(maxi, prod);
        if (prod == 0)
        {
            prod = 1;
        }
    }

    return maxi;
}