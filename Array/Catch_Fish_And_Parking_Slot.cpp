#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

// love bubber contest 3 
// TC -> O(N) + O(N)
int minimumNet(int n, int k, vector<bool> fish)
{
    int r = -1;
    int count = 0;
    int ans = INT_MAX;

    for (int l = 0; l < n; l++)
    {
        while (r < n - 1 && count < k)
        {
            r++;

            if (fish[r])
                count++;
        }

        if (count == k)
            ans = min(ans, r - l + 1);

        if (fish[l])
            count--;
    }

    if (ans == INT_MAX)
        return -1;

    return ans;
}

// asked in swiggy
// TC -> O(N) + O(N)
int minLengthRoof(vector<int> cars, int k)
{
    sort(cars.begin(), cars.end());
    // to reverse
    // reverse(cars.begin(), cars.end());
    int n = cars.size();
    int ans = INT_MAX;
    int count = 0;
    int r = -1;

    for (int l = 0; l < n; l++)
    {
        while (r < n-1 && count < k)
        {
            r++;
            count++;
        }

        if (count == k)
            ans = min(ans, cars[r] - cars[l] + 1);

        count--;
    }
    return ans;
}