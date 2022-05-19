#include<vector>
#include<iostream>
using namespace std;

bool isPossible(vector<int>& piles, int h, long long mid)
{
    int totalHours = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] <= mid)
        {
            totalHours++;
        }
        else
        {
            int mod = piles[i] % mid;
            totalHours += piles[i] / mid;
            if (mod > 0)
            {
                totalHours++;
            }
        }
    }
    if (totalHours <= h) return true;
    return false;
}
// binary search
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = INT_MIN;
    int ans = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] > high)
        {
            high = piles[i];
        }
    }

    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (isPossible(piles, h, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}