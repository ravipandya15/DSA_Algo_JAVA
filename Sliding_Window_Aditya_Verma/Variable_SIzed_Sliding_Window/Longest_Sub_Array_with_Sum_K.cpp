#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lenOfLongSubarr(int nums[],  int n, int k) 
{ 
    unordered_map<int, int> map;
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
        if (sum == k)
        {
            maxi = i+1;
        }
        else
        {
            if (map.find(sum - k) != map.end())
            {
                maxi = max(maxi, i - map[sum - k]);
                //count = count + map[sum-k];
            }
        }
        
        if (map.find(sum) == map.end())
        {
            map[sum] = i;
        }
        
    }
    
    return maxi;
} 