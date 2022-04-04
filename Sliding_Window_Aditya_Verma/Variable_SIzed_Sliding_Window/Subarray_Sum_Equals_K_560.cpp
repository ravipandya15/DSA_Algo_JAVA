#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int n = nums.size();
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
        if (sum == k)
        {
            count++;
        }
        if (map.find(sum - k) != map.end())
        {
            count = count + map[sum-k];
        }
        map[sum]++;
    }
    
    return count;
}