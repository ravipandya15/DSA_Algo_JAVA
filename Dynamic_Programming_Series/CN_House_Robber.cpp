#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// space optimization
// TC -> O(N)
// SC -> O(1)
long long MaximumNonAdjacentSum4(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    long long prev2 = 0;
    long long prev = nums[0];

    for (int i = 1; i < n; i++)
    {
        long long pick = nums[i];
        if (i - 2 >= 0) pick += prev2;

        long long not_pick = prev;

        long long curi = max(pick, not_pick);

        prev2 = prev;
        prev = curi;
    }

    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];

    vector<int> arr1;
    vector<int> arr2;
    
    for (int i = 0; i < n; i++)
    {
        if (i != 0) arr1.push_back(valueInHouse[i]);
        if (i != n - 1) arr2.push_back(valueInHouse[i]);
    }

    return max(MaximumNonAdjacentSum4(arr1), MaximumNonAdjacentSum4(arr2));
}